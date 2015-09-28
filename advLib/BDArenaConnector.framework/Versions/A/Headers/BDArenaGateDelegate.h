//
//  BDarenaGateDelegate.h
//  BDArenaConnectorClient
//
//  Created by Salvatore Iodice on 2/27/12.
//  Copyright (c) 2012 ArenaDaemon Srl. All rights reserved.
//

#ifndef BDArenaConnectorClient_BDArenaGateDelegate_h
#define BDArenaConnectorClient_BDArenaGateDelegate_h

#import "BDArenaPlayerData.h"
#import "BDArenaDataObjects.h"

@class BDArenaGate;

@protocol BDArenaGateDelegate <NSObject>

@optional

// start task delegate

- (void) arenaGateConnectionFailed;
- (void) arenaGate:(BDArenaGate*)gate didStartTask:(ARENA_TASK)task;

// auth delegates
- (void) arenaGate:(BDArenaGate*)gate authReceivedForLocalPlayerWithData:(BDArenaPlayerData*)playerData alreadyMet:(BOOL)alreadyMet isOffline:(BOOL)isOffline;
- (void) arenaGate:(BDArenaGate*)gate authFailedForLocalPlayerWithError:(NSError*)error;

// update delegates
- (void) arenaGate:(BDArenaGate*)gate updateProfileSuccessForLocalPlayerWithData:(BDArenaPlayerData*)playerData;
- (void) arenaGate:(BDArenaGate*)gate updateProfileFailedForLocalPlayerWithError:(NSError*)error;

// logout delegate
- (void) arenaGateLogoutSuccess;
- (void) arenaGate:(BDArenaGate*)gate logoutFailedForLocalPlayerWithError:(NSError*)error;

// login delegate
- (void) arenaGate:(BDArenaGate*)gate loginSuccessForLocalPlayerWithData:(BDArenaPlayerData*)playerData;
- (void) arenaGate:(BDArenaGate*)gate loginFailedForLocalPlayerWithError:(NSError*)error;

// app_data 
- (void) arenaGate:(BDArenaGate*)gate appDataReceived:(NSDictionary*)appData;

// player info
- (void) arenaGate:(BDArenaGate*)gate getPlayerDataFailedWithError:(NSError*)error;
- (void) arenaGate:(BDArenaGate*)gate getPlayerDataSuccessfullyCompleted:(BDArenaPlayerData*)playerData;

- (void) arenaGate:(BDArenaGate*)gate getPlayersDataFailedWithError:(NSError*)error;
- (void) arenaGate:(BDArenaGate*)gate getPlayersDataSuccessfullyCompletedWithArray:(NSArray*)playersArray;

@end

#endif
