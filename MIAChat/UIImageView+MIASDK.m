//
//  UIImageView+MIASDK.m
//  piantala
//
//  Created by Work on 15/07/15.
//  Copyright (c) 2015 ale. All rights reserved.
//

#import "UIImageView+MIASDK.h"
#import <objc/runtime.h>
#import <mkApp/mkApp.h>

@interface MIASDKCache : NSCache

@end

@implementation MIASDKCache

- (UIImage *)cachedImageForCollectionId:(NSString *)collectionId
{
    return [self objectForKey:collectionId];
}

- (void)cacheImage:(UIImage *)image forCollectionId:(NSString *)collectionId
{
    if (image && collectionId) {
        [self setObject:image forKey:collectionId];
    }
}

@end

@interface UIImageView (_MIASDK)

@property (nonatomic, strong, setter=mia_setImageQuery:) MKQuery *mia_imageQuery;

@end

@implementation UIImageView (MIASDK)

+ (MIASDKCache *)sharedImageCache
{
    static MIASDKCache *mia_defaultImageCache = nil;
    static dispatch_once_t oncePredicate;
    dispatch_once(&oncePredicate, ^{
        mia_defaultImageCache = [[MIASDKCache alloc] init];

        [[NSNotificationCenter defaultCenter] addObserverForName:UIApplicationDidReceiveMemoryWarningNotification object:nil queue:[NSOperationQueue mainQueue] usingBlock:^(NSNotification * __unused notification) {
            [mia_defaultImageCache removeAllObjects];
        }];
    });

    return mia_defaultImageCache;
}

- (MKQuery *)mia_imageQuery
{
    return (MKQuery *)objc_getAssociatedObject(self, @selector(mia_imageQuery));
}

- (void)mia_setImageQuery:(MKQuery *)imageQuery
{
    objc_setAssociatedObject(self, @selector(mia_imageQuery), imageQuery, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

+ (void)mia_cacheImage:(UIImage *)image forCollectionId:(NSString *)collectionId
{
    [[UIImageView sharedImageCache] cacheImage:image forCollectionId:collectionId];
}

- (void)mia_setImageWithCollectionId:(NSString *)collectionId placeholderImage:(UIImage *)placeholder completionHandler:(void(^)(void))completionHandler
{
    [self mia_cancelLastQuery];
    UIImage *cachedImage = [[UIImageView sharedImageCache] cachedImageForCollectionId:collectionId];
    if (cachedImage) {
        self.image = cachedImage;
        self.mia_imageQuery = nil;
        if (completionHandler) {
            completionHandler();
        }
        return;
    } else {
        if (placeholder) {
            self.image = placeholder;
        }
    }

    MKQuery *query = [MKQuery queryWithcollectionName:@"files"];
    [query whereKey:@"file" equalTo:collectionId];
    self.mia_imageQuery = query;

    __weak typeof(self)weakSelf = self;
    [query findAllInBackgroundWithBlock:^(NSArray *results, NSError *error) {
        if (error) {
            return;
        }

        if (results.count > 0) {
            MKCollectionFile *file = results.firstObject;
            [file loadDataInBackgroundWithBlock:^(BOOL success, NSData *data, NSError *loadError) {
                if (!success) {
                    return;
                }
                __strong typeof(weakSelf)strongSelf = weakSelf;
                UIImage *image = [UIImage imageWithData:data];
                strongSelf.image = image;
                if (completionHandler) {
                        completionHandler();
                }

                [[UIImageView sharedImageCache] cacheImage:image forCollectionId:collectionId];
                self.mia_imageQuery = nil;
            }];
        }
    }];
}

- (void)mia_cancelLastQuery
{
    self.mia_imageQuery = nil;
}

@end
