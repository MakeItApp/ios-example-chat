//
//  BDArenaAchievementsDelegate.h
//  BDArenaConnectorClient
//
//  Created by Salvatore Iodice on 2/27/12.
//  Copyright (c) 2012 ArenaDaemon Srl. All rights reserved.
//

#ifndef BDArenaConnectorClient_BDArenaAchievementsDelegate_h
#define BDArenaConnectorClient_BDArenaAchievementsDelegate_h

#import "BDArenaDataObjects.h"
#import "BDArenaPlayerData.h"

@class BDArenaAchievements;

@protocol BDArenaAchievementsDelegate <NSObject>

@optional

- (void) arenaAchievements:(BDArenaAchievements*)achievements loadAchievementsDidFailWithError:(NSError*)error;
- (void) arenaAchievements:(BDArenaAchievements*)achievements loadAchievementsSuccessfullyCompletedWithArray:(NSArray*)achievementsArray;

- (void) arenaAchievements:(BDArenaAchievements*)achievements reportAchievementDidFailWithError:(NSError*)error;
- (void) arenaAchievements:(BDArenaAchievements*)achievements reportAchievementWithId:(NSInteger)achievementId didFailWithError:(NSError*)error;
- (void) arenaAchievements:(BDArenaAchievements*)achievements reportAchievementSuccessfullyCompletedWithData:(BDArenaAchievementData*)achievementData;

@end

#endif
