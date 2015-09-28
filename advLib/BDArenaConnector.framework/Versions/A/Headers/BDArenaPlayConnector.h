//
//  BDArenaPlayConnector.h
//  ArenaTester
//
//  Created by saver on 1/26/11.
//  Copyright 2011 ArenaDaemon Srl. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <sys/types.h>
#import <sys/socket.h>
#import <stdio.h>
#import <netdb.h>
#import <arpa/inet.h>
#import <netinet/in.h>
#import <unistd.h>
#import <stdlib.h>
#import <string.h>
#import <sys/ioctl.h>
#import <sys/sockio.h>
#import <net/if.h>
#import <net/if_dl.h>
#import <string.h>
#import <sys/ioctl.h>
#import <sys/sockio.h>
#import <fcntl.h>
#import "BDArenaDataObjects.h"

#pragma mark -
#pragma mark Console Logging

#pragma mark -
#pragma mark types definition

#define REQUEST_FAIL_ERROR_INTERNAL	500

#pragma mark -
#pragma mark Arena Internal Commands

typedef enum {
	ARENA_PLAY_METHOD_PING_COMMAND                      = 3000,
	ARENA_PLAY_METHOD_AUTH_WITH_UDID_AND_TOKEN          = 3002,
	ARENA_PLAY_METHOD_GET_TABLES_LIST                   = 3003,
	ARENA_PLAY_METHOD_REGISTER_TO_TABLE                 = 3005,
	ARENA_PLAY_METHOD_UNREGISTER_FROM_TABLE             = 3006,
	ARENA_PLAY_METHOD_LEAVE_MATCH                       = 3007,
	ARENA_PLAY_METHOD_GET_PLAYERS_LIST_FOR_TABLE		= 3010,
	ARENA_PLAY_METHOD_GET_PARAM_FOR_TABLE               = 3011,
	ARENA_PLAY_METHOD_GET_PLAYERS_LIST_FOR_MATCH		= 3012,
	ARENA_PLAY_METHOD_SEND_MESSAGE_TO_PLAYERS_IN_MATCH	= 3013,
	ARENA_PLAY_METHOD_SEND_MESSAGE_TO_PLAYER_IN_MATCH	= 3014,
    ARENA_PLAY_METHOD_PROFILE_DID_UPDATE                = 3015,

    ARENA_PLAY_METHOD_CREATE_CHALLENGE                  = 3016,
    ARENA_PLAY_METHOD_CANCEL_CHALLENGE                  = 3017,
    ARENA_PLAY_METHOD_ACCEPT_CHALLENGE_INVITATION       = 3018,
    ARENA_PLAY_METHOD_REFUSE_CHALLENGE_INVITATION       = 3019,
    ARENA_PLAY_METHOD_LEAVE_CHALLENGE                   = 3020,
    ARENA_PLAY_METHOD_START_CHALLENGE                   = 3021,
    
    ARENA_PLAY_METHOD_GET_STATUS_FOR_PLAYER             = 3022
}ARENA_METHOD;


#pragma mark -
#pragma mark Arena Interface

@protocol BDArenaPlayConnectorDelegate;

@interface BDArenaPlayConnector : NSObject	

@property (assign)	NSMutableArray* delegates;
@property (assign)	NSInteger		_latestPingTime;

@property (nonatomic, retain) NSString*       _host;
@property (nonatomic, assign) NSInteger       _port;    

// connection managment methods
- (void) connect;
- (BOOL) isConnected;
- (void) disconnect;

// tables managment
- (ARENA_ERROR) getTablesList;
- (ARENA_ERROR) getPlayersListForTableWithId:(NSString*)tableID;
- (ARENA_ERROR) getParamStringForTableWithId:(NSString*)tableID;
- (ARENA_ERROR) getPlayersListForMatchWithId:(NSInteger)matchID;
- (ARENA_ERROR) registerToTableWithId:(NSString*)tableID;
- (ARENA_ERROR) unregisterFromTableWithId:(NSString*)tableID;

// match managment
- (ARENA_ERROR) leaveMatchWithId:(NSInteger)matchID;
- (ARENA_ERROR) sendMessageToPlayers:(NSString*)message inMatchWithId:(NSInteger)matchId;
- (ARENA_ERROR) sendMessage:(NSString*)message ToPlayerWithAuid:(NSInteger)auid inMatchWithId:(NSInteger)matchId;

// challenge managment
- (ARENA_ERROR) createChallengeWithName:(NSString*)challengeName withParam:(NSString*)param withPlayersAuid:(NSArray*)playersAuid;
- (ARENA_ERROR) cancelChallengeWithId:(NSString*)challengeId;
- (ARENA_ERROR) acceptInvitationToChallengeWithId:(NSString*)challengeId;
- (ARENA_ERROR) refuseInvitationToChallengeWithId:(NSString*)challengeId;
- (ARENA_ERROR) leaveChallengeWithId:(NSString*)challengeId;
- (ARENA_ERROR) startChallengeWithId:(NSString*)challengeId;

// players info
- (ARENA_ERROR) getStatusForPlayerWithAuid:(NSInteger)auid;

@end


