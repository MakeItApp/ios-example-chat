/*
 *  BDArenaDataObjects.h
 *  arenaChatTester
 *
 *  Created by saver on 10/10/11.
 *  Copyright 2011 ArenaDaemon Srl. All rights reserved.
 *
 */
#import "BDArenaTypes.h"
#import "BDArenaPlayerData.h"
#import "BDArenaTableData.h"
#import "BDArenaRoomData.h"
#import "BDArenaMatchData.h"
#import "BDArenaLeaderboardData.h"
#import "BDArenaScoreData.h"
#import "BDArenaAchievementData.h"
#import "BDArenaAdClipConfigData.h"

#define SDK_VERSION         1.0

#define ArenaGateVersion	1.0.0.0
#define ArenaChatVersion	1.0.6.2
#define ArenaPlayVersion	1.0.0.0

#define PING_DELAY_IN_SECS  30

typedef enum {
    ARENA_TASK_IDLE         = 0,
    ARENA_TASK_AUTH,
    ARENA_TASK_UPDATE,
    ARENA_TASK_REGISTER,
    ARENA_TASK_LOGOUT,
    ARENA_TASK_LOGIN,
    ARENA_TASK_GET_PLAYER_INFO,
    ARENA_TASK_GET_PLAYERS_INFO
}ARENA_TASK;

typedef enum {
	ARENA_ERROR_SUCCESS				= 0,
	ARENA_ERROR_NOT_CONNECTED		= -1,
	ARENA_ERROR_EMPTY_MESSAGE		= -2,
	ARENA_ERROR_EMPTY_NICKNAME		= -3,
    ARENA_ERROR_PLAYERS_LIST_EMPTY  = -4,
}ARENA_ERROR;

typedef enum{
    ARENA_CHALLENGE_CANCELLATION_REASON_ORGANIZER_DID_CANCEL        = 1000,
    ARENA_CHALLENGE_CANCELLATION_REASON_ORGANIZER_DID_DISCONNECT    = 1001,
    ARENA_CHALLENGE_CANCELLATION_REASON_ALL_PLAYERS_GONE            = 1002
}ARENA_CHALLENGE_CANCELLATION_REASON;

typedef enum {
	ARENA_DEVICE_MODEL_IPHONE		= 1000
}ARENA_DEVICE_MODEL;

typedef enum {
	ARENA_DEVICE_OS_IOS				= 2000
}ARENA_DEVICE_OS;

typedef enum{
    ARENA_PLAYER_STATUS_NOT_CONNECTED   = 0,
    ARENA_PLAYER_STATUS_ONLINE          = 1,
}ARENA_PLAYER_STATUS;

typedef enum{
    ARENA_ADV_TYPE_BANNER               = 0,
    ARENA_ADV_TYPE_FULLSCREEN_IMAGE     = 1,
    ARENA_ADV_TYPE_FULLSCREEN_CLIP      = 2,
}ARENA_ADV_TYPE;

typedef enum{
    BDArenaAdvBannerFormat320x53        = 1,    // Phones and Tablets
    BDArenaAdvBannerFormat300x250       = 2,    // Tablets
    BDArenaAdvBannerFormat468x60        = 3,    // Tablets
    BDArenaAdvBannerFormat728x90        = 4,    // Tablets
}BDArenaAdvBannerFormat;

typedef enum{
    BDArenaAdvFullscreenBannerSmartphone    = 5,
    BDArenaAdvFullscreenBannerTablet        = 6,
}BDArenaAdvFullscreenBannerFormat;

typedef enum{
    BDArenaAdvAdClipDidFinishReasonPlaybackEnded	= 1,
	BDArenaAdvAdClipDidFinishReasonPlaybackSkipped	= 2,
}BDArenaAdvAdClipDidFinishReason;

// UI elements
#define BDArenaUIBaseColor                      [UIColor colorWithRed:(float)118/255 green:(float)9/255 blue:(float)0/255 alpha:1.0]
#define BDArenaUIButtonBaseColor                [UIColor colorWithRed:(float)118/255 green:(float)9/255 blue:(float)0/255 alpha:1.0]
#define BDArenaUIAvatarImageBorderColor         [UIColor colorWithRed:(float)102/255 green:(float)102/255 blue:(float)102/255 alpha:1.0]
#define BDArenaUIButtonTextBaseColor            [UIColor colorWithRed:(float)255/255 green:(float)255/255 blue:(float)255/255 alpha:1.0]
#define BDArenaUITextColor                      [UIColor colorWithRed:(float)255/255 green:(float)255/255 blue:(float)255/255 alpha:1.0]
#define BDArenaUITextFieldBorderColor           [UIColor colorWithRed:(float)0/255 green:(float)0/255 blue:(float)0/255 alpha:1.0]
#define BDArenaUITabbarItemTextColorSelected    [UIColor colorWithRed:(float)255/255 green:(float)255/255 blue:(float)255/255 alpha:1.0]
#define BDArenaUITabbarItemTextColorUnselected  [UIColor colorWithRed:(float)153/255 green:(float)153/255 blue:(float)153/255 alpha:1.0]
#define BDArenaUITextFieldFontColor             [UIColor blackColor]
#define BDArenaUIAchievementRingColor           [UIColor redColor]
#define BDArenaUIFontNameNormal                 @"Copperplate"
#define BDArenaUIFontNameBold                   @"Copperplate-Bold"
#define BDArenaUIFontSize                       16


