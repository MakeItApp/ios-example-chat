/*
 *  BDArenaChatConnectorDelegate.h
 *  NCC2
 *
 *  Created by saver on 2/17/12.
 *  Copyright 2012 ArenaDaemon Srl. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import "BDArenaChatConnector.h"

#pragma mark -
#pragma mark BDArenaChatConnectorDelegate

@protocol BDArenaChatConnectorDelegate <NSObject>

@optional

- (void) arenaChat:(BDArenaChatConnector*)connector requestDidFail:(NSError*)error; 

- (void) arenaChatConnectionDidClose;
- (void) arenaChatConnectionEstabilished;
- (void) arenaChatConnectionFailedWithError:(NSError*)error;
- (void) arenaChatLocalPlayerDidLoginFromDifferentDevice;

- (void) arenaChat:(BDArenaChatConnector*)connector roomJoined:(NSString*)roomName numberOfPlayers:(NSInteger)numberOfPlayers playersList:(NSArray*)players;
- (void) arenaChat:(BDArenaChatConnector*)connector roomLeft:(NSString*)roomName;
- (void) arenaChat:(BDArenaChatConnector*)connector roomAlreadyJoined:(NSString*)roomName;
- (void) arenaChat:(BDArenaChatConnector*)connector messageSuccessfullySentInRoom:(NSString*)roomName;
- (void) arenaChat:(BDArenaChatConnector*)connector messageSuccessfullySentToPlayerWithAuid:(NSInteger)destinationAuid;
- (void) arenaChat:(BDArenaChatConnector*)connector roomsListReceived:(NSArray*)roomsArray;
- (void) arenaChat:(BDArenaChatConnector*)connector roomsList:(NSArray*)roomsArray receivedForPlayerWithAuid:(NSInteger)auid;
- (void) arenaChat:(BDArenaChatConnector*)connector numberOfPlayers:(NSInteger)count inRoom:(NSString*)roomName;
- (void) arenaChat:(BDArenaChatConnector*)connector numberOfPlayersGlobal:(NSInteger)count;
- (void) arenaChat:(BDArenaChatConnector*)connector playersList:(NSArray*)players receivedForRoom:(NSString*)roomName;
- (void) arenaChat:(BDArenaChatConnector*)connector status:(ARENA_PLAYER_STATUS)status receivedForPlayerWithAuid:(NSInteger)auid;

- (void) arenaChat:(BDArenaChatConnector*)connector 
newMessageReceived:(NSString*)message 
			inRoom:(NSString*)roomName 
		fromPlayer:(BDArenaPlayerData*)playerData;

- (void) arenaChat:(BDArenaChatConnector*)connector 
newPrivateMessageReceived:(NSString*)message 			
		fromPlayer:(BDArenaPlayerData*)playerData;

- (void) arenaChat:(BDArenaChatConnector*)connector player:(BDArenaPlayerData*)playerData joinedRoom:(NSString*)roomName;
- (void) arenaChat:(BDArenaChatConnector*)connector player:(BDArenaPlayerData*)playerData leftRoom:(NSString*)roomName;

@end

