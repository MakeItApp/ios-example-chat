//
//  MKAnalytics.h
//  Tactics Seasons
//
//  Created by Fedius on 02/04/13.
//  Copyright (c) 2013 Soft Fss. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MKAnalytics : NSObject

+ (MKAnalytics*)sharedInstance;

- (void)start:(NSString *)appKey;

- (void)recordEvent:(NSString *)key count:(int)count;

- (void)recordEvent:(NSString *)key count:(int)count sum:(double)sum;

- (void)recordEvent:(NSString *)key segmentation:(NSDictionary *)segmentation count:(int)count;

- (void)recordEvent:(NSString *)key segmentation:(NSDictionary *)segmentation count:(int)count sum:(double)sum;

@end
