//
//  BDArenaGate.h
//  BDArenaConnectorClient
//
//  Created by Salvatore Iodice on 2/27/12.
//  Copyright (c) 2012 ArenaDaemon Srl. All rights reserved.
//

#import <Foundation/Foundation.h>

#define AutoAuthRetryDelayAfterFailure      10.0
#define AutoAuthRetryDelayAfterOffline      10.0

#import "BDArenaConnector.h"
#import "BDArenaGateDelegate.h"

@interface BDArenaGate : NSObject

@property (nonatomic, readonly, assign) NSString* _nickname;
@property (nonatomic, readonly, assign) NSString* _accessToken;
@property (nonatomic, readonly, assign) NSNumber* _auid;
@property (nonatomic, readonly, assign) NSNumber* _registered;

@property (nonatomic, readonly, assign) BOOL isLocalPlayerAuthenticated;
@property (nonatomic, readonly, assign) BOOL isLocalPlayerRegistered;

@property (nonatomic, readonly, assign) BOOL isAuthLoopAlreadyInProgress;

@property (nonatomic, readonly, assign) BDArenaPlayerData* localPlayerData;

@property (nonatomic, assign) id <BDArenaGateDelegate> delegate;
@property (nonatomic, assign) BOOL forceAutoretryIfAuthFails;
           

- (void) authWithUDID;
- (void) registerLocalPlayerProfileInfo:(NSDictionary*)info;
- (void) updateLocalPlayerProfileInfo:(NSDictionary*)info;
- (void) logout;
- (void) loginWithEmail:(NSString*)email andPassword:(NSString*)password;
- (void) getDataForPlayerWithAuid:(NSInteger)auid;
- (void) getDataForPlayersWithAuids:(NSArray*)auids;

- (void) resetLocalPlayerStatus;

@end
