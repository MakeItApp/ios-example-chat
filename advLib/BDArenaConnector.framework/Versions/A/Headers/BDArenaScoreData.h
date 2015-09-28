//
//  BDArenaTableData.h
//  NCC2
//
//  Created by saver on 2/12/12.
//  Copyright 2012 ArenaDaemon Srl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BDArenaPlayerData.h"

@interface BDArenaScoreData : NSObject {
	@private
	
    NSInteger           leaderboardId;
    NSInteger           score;
    BDArenaPlayerData*  playerData;
}

@property (nonatomic, readonly, assign) NSInteger           leaderboardId;
@property (nonatomic, readonly, assign) NSInteger           score;
@property (nonatomic, readonly, assign) BDArenaPlayerData*  playerData;

- (id) initWithParams:(NSDictionary*)params;

@end
