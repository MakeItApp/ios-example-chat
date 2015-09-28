//
//  BDArenaGate.h
//  BDArenaConnectorClient
//
//  Created by Salvatore Iodice on 2/27/12.
//  Copyright (c) 2012 ArenaDaemon Srl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BDArenaAchievementsDelegate.h"

@interface BDArenaAchievements : NSObject

@property (assign) NSMutableArray*  delegates;
@property (assign) BOOL             useNotificationPanel;

- (void) loadAchievements;
- (void) reportAchievement:(NSInteger)achievementId withPercentComplete:(CGFloat)percentComplete;

@end
