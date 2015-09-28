//
//  BDArenaMatchData.h
//  NCC2
//
//  Created by saver on 2/16/12.
//  Copyright 2012 ArenaDaemon Srl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BDArenaTypes.h"

@interface BDArenaMatchData : NSObject {
	@private
	
	NSInteger		matchId;
	NSString*		tableId;
	NSString*		tableReferenceName;
	NSString*		param;
	NSInteger		maxPlayers;
	NSMutableArray*	players;
}

@property (nonatomic, readonly, assign) NSInteger		matchId;
@property (nonatomic, readonly, retain) NSString*		tableId;
@property (nonatomic, readonly, retain) NSString*		tableReferenceName; 
@property (nonatomic, readonly, retain) NSString*		param;
@property (nonatomic, readonly, assign) NSInteger		maxPlayers;
@property (nonatomic, readonly, retain) NSMutableArray*	players;

- (id) initWithParams:(NSDictionary*)params;
- (id) initWithMatchData:(BDArenaMatchData*)matchData;
- (id) initWithMatchId:(NSInteger)_matchId
		   withTableId:(NSString*)_tableId
			  withName:(NSString*)_name
			 withParam:(NSString*)_param
		   withPlayers:(BDArenaPlayersArray*)_players;

@end
