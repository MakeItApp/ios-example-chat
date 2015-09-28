//
//  BDArenaTableData.h
//  NCC2
//
//  Created by saver on 2/12/12.
//  Copyright 2012 ArenaDaemon Srl. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface BDArenaAchievementData : NSObject {
	@private
	
    NSInteger	achievementId;
    CGFloat     percentComplete;
    NSInteger   points;
    NSString*	achievementTitle;
    NSString*	achievementDescription;
    NSString*	achievementImageUrl;
}

@property (nonatomic, readonly, assign) NSInteger	achievementId;
@property (nonatomic, readonly, assign) CGFloat     percentComplete;
@property (nonatomic, readonly, assign) NSInteger   points;
@property (nonatomic, readonly, retain) NSString*	achievementTitle;
@property (nonatomic, readonly, retain) NSString*	achievementDescription;
@property (nonatomic, readonly, retain) NSString*	achievementImageUrl;

- (id) initWithParams:(NSDictionary*)params;
- (id) initWithAchievementsData:(BDArenaAchievementData*)data;

@end
