//
//  BDArenaLeaderboardsDelegate.h
//  BDArenaConnectorClient
//
//  Created by Salvatore Iodice on 2/27/12.
//  Copyright (c) 2012 ArenaDaemon Srl. All rights reserved.
//

#ifndef BDArenaConnectorClient_BDArenaLeaderboardsDelegate_h
#define BDArenaConnectorClient_BDArenaLeaderboardsDelegate_h

#import "BDArenaPlayerData.h"

@class BDArenaLeaderboards;

@protocol BDArenaLeaderboardsDelegate <NSObject>

@optional

- (void) arenaLeaderboards:(BDArenaLeaderboards*)leaderboards getLeaderboardsDidFailWithError:(NSError*)error;
- (void) arenaLeaderboards:(BDArenaLeaderboards*)leaderboards getLeaderboardsSuccessfullyCompletedWithArray:(NSArray*)leaderboardsArray;

- (void) arenaLeaderboards:(BDArenaLeaderboards*)leaderboards setScoreToLeaderboardWithId:(NSInteger)leaderboardId didFailWithError:(NSError*)error;
- (void) arenaLeaderboards:(BDArenaLeaderboards*)leaderboards setScoreSuccessfullyCompletedToLeaderboardWithId:(NSInteger)leaderboardId;

- (void) arenaLeaderboards:(BDArenaLeaderboards*)leaderboards postScoreToLeaderboardWithId:(NSInteger)leaderboardId didFailWithError:(NSError*)error;
- (void) arenaLeaderboards:(BDArenaLeaderboards*)leaderboards postScoreSuccessfullyCompletedToLeaderboardWithId:(NSInteger)leaderboardId;

- (void) arenaLeaderboards:(BDArenaLeaderboards*)leaderboards getScoreForLeaderboardWithId:(NSInteger)leaderboardId didFailWithError:(NSError*)error;
- (void) arenaLeaderboards:(BDArenaLeaderboards*)leaderboards getScoreForLeaderboardWithId:(NSInteger)leaderboardId successfullyCompletedWithArray:(NSArray*)scoresArray;

- (void) arenaLeaderboards:(BDArenaLeaderboards*)leaderboards getScoreForPlayerWithAuid:(NSInteger)auid inLeaderboardWithId:(NSInteger)leaderboardId didFailWithError:(NSError*)error;
- (void) arenaLeaderboards:(BDArenaLeaderboards*)leaderboards getScoreForPlayerWithAuid:(NSInteger)auid successfullyCompletedWithScore:(NSInteger)score withPlacement:(NSInteger)placement withPlayerData:(BDArenaPlayerData*)playerData inLeaderboardWithId:(NSInteger)leaderboardId;

@end

#endif
