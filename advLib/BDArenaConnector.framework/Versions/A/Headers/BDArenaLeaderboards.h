//
//  BDArenaLeaderboards.h
//  BDArenaConnectorClient
//
//  Created by Salvatore Iodice on 2/27/12.
//  Copyright (c) 2012 ArenaDaemon Srl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BDArenaLeaderboardsDelegate.h"

@interface BDArenaLeaderboards : NSObject

@property (assign)	NSMutableArray* delegates;

- (void) getLeaderboards;
- (void) setScore:(NSInteger)score toLeaderboardWithId:(NSInteger)leaderboardId;
- (void) postScore:(NSInteger)score toLeaderboardWithId:(NSInteger)leaderboardId;
- (void) getScoreForLeaderboardWithId:(NSInteger)leaderboardId start:(NSInteger)start limit:(NSInteger)limit;
- (void) getScoreForPlayerWithAuid:(NSInteger)auid inLeaderboardWithId:(NSInteger)leaderboardId;

@end
