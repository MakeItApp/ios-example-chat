//
//  BDArenaChatConnector.h
//  arenaChatTester
//
//  Created by saver on 10/2/11.
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

#define REQUEST_FAIL_ERROR_INTERNAL                         500
#define REQUEST_FAIL_ERROR_UNAUTHORIZED                     400
#define REQUEST_FAIL_ERROR_ROOM_DOES_NOT_EXISTS             600
#define REQUEST_FAIL_ERROR_LOCAL_PLAYER_NOT_IN_ROOM         601
#define REQUEST_FAIL_ERROR_PLAYER_NOT_FOUND                 602

typedef enum {
	ARENA_CHAT_METHOD_PING_COMMAND                      = 3000,
	ARENA_CHAT_METHOD_AUTH_WITH_UDID_AND_TOKEN          = 3002,
	ARENA_CHAT_METHOD_JOIN_ROOM                         = 3011,
	ARENA_CHAT_METHOD_SEND_MESSAGE_IN_ROOM              = 3012,
	ARENA_CHAT_METHOD_SEND_MESSAGE_TO_PLAYER            = 3013,
	ARENA_CHAT_METHOD_MESSAGE_RECEIVED_IN_ROOM          = 3014,
	ARENA_CHAT_METHOD_MESSAGE_RECEIVED_FROM_PLAYER      = 3015,
	ARENA_CHAT_METHOD_GET_ROOMS_LIST                    = 3016,
	ARENA_CHAT_METHOD_PLAYER_JOINED_ROOM                = 3017,
	ARENA_CHAT_METHOD_PLAYER_LEFT_ROOM                  = 3018,
	ARENA_CHAT_METHOD_LEAVE_ROOM                        = 3019,
	ARENA_CHAT_METHOD_GET_NUMBER_OF_PLAYERS_IN_ROOM     = 3020,
	ARENA_CHAT_METHOD_GET_NUMBER_OF_PLAYERS_GLOBAL      = 3021,
    ARENA_CHAT_METHOD_GET_PLAYERS_LIST_FOR_ROOM         = 3022,
    ARENA_CHAT_METHOD_GET_ROOMS_FOR_PLAYER              = 3023,
    ARENA_CHAT_METHOD_PROFILE_DID_UPDATE                = 3024,
    ARENA_CHAT_METHOD_GET_STATUS_FOR_PLAYER             = 3025,
    
}ARENA_CHAT_METHOD;

#pragma mark -
#pragma mark Arena Chat Interface

@protocol BDArenaChatConnectorDelegate;

@interface BDArenaChatConnector : NSObject

@property (assign)	NSMutableArray* delegates;
@property (assign)	NSInteger		_latestPingTime;

@property (nonatomic, retain) NSString*       _host;
@property (nonatomic, assign) NSInteger       _port;    


// connection managment methods
- (void) connect;
- (BOOL) isConnected;
- (void) disconnect;

- (ARENA_ERROR) getRoomsList;
- (ARENA_ERROR) joinRoom:(NSString*)roomName returnPlayersList:(BOOL)returnPlayersList;
- (ARENA_ERROR) leaveRoom:(NSString*)roomName;
- (ARENA_ERROR) sendMessage:(NSString*)message inRoom:(NSString*)roomName;
- (ARENA_ERROR) sendPrivateMessage:(NSString*)message toPlayerWithAuid:(NSInteger)auid;
- (ARENA_ERROR) getNumberOfPlayersInRoom:(NSString*)roomName;
- (ARENA_ERROR) getNumberOfPlayersGlobal;
- (ARENA_ERROR) getPlayersListForRoom:(NSString*)roomName;
- (ARENA_ERROR) getRoomsForPlayerWithAuid:(NSInteger)auid;
- (ARENA_ERROR) getStatusForPlayerWithAuid:(NSInteger)auid;

@end

