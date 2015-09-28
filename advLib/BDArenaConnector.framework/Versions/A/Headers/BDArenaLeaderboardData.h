//
//  BDArenaTableData.h
//  NCC2
//
//  Created by saver on 2/12/12.
//  Copyright 2012 ArenaDaemon Srl. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BDArenaLeaderboardData : NSObject {
	@private
	
	NSInteger       leaderboardId;
	NSString*       leaderboardTitle;
}

@property (nonatomic, readonly, assign) NSInteger	leaderboardId;
@property (nonatomic, readonly, retain) NSString*	leaderboardTitle;

- (id) initWithParams:(NSDictionary*)params;
- (id) initWithLeaderboardData:(BDArenaLeaderboardData*)data;

@end
