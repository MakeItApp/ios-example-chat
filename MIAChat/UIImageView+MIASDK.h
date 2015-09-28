//
//  UIImageView+MIASDK.h
//  piantala
//
//  Created by Work on 15/07/15.
//  Copyright (c) 2015 ale. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImageView (MIASDK)

+ (void)mia_cacheImage:(UIImage *)image forCollectionId:(NSString *)collectionId;

- (void)mia_setImageWithCollectionId:(NSString *)collectionId placeholderImage:(UIImage *)placeholder completionHandler:(void(^)(void))completionHandler;

@end
