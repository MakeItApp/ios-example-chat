//
//  BDArenaConnector.h
//  BDArenaConnectorClient
//
//  Created by Salvatore Iodice on 2/27/12.
//  Copyright (c) 2012 ArenaDaemon S.r.l. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BDArenaGate.h"
#import "BDArenaGateDelegate.h"

#import "BDArenaNotificationsManager.h"

#import "BDArenaPlayConnector.h"
#import "BDArenaChatConnector.h"
#import "BDArenaCustomAdvConnector.h"
#import "BDArenaAdvConnector.h"
#import "BDArenaLeaderboards.h"
#import "BDArenaAchievements.h"

#import "BDArenaConnectorDelegate.h"

@interface BDArenaConnector : NSObject <BDArenaGateDelegate, BDArenaAdvConnectorDelegate, BDArenaLeaderboardsDelegate>

@property (readonly, assign) ARENA_TASK                         taskInProgress;
@property (readonly, assign) BOOL                               isOffline;
@property (readonly, assign) NSString*                          appKey;
@property (nonatomic, assign) BOOL                              forceAutoretryIfAuthFails;
@property (nonatomic, assign) BOOL                              showNotificationPanel;
@property (nonatomic, readonly) BDArenaPlayConnector*           playConnector;
@property (nonatomic, readonly) BDArenaChatConnector*           chatConnector;
@property (nonatomic, readonly) BDArenaLeaderboards*            leaderboardsConnector;
@property (nonatomic, readonly) BDArenaAchievements*            achievementsConnector;
@property (nonatomic, readonly) BDArenaNotificationsManager*    notificationsManager;
@property (nonatomic, readonly) BOOL                            runInSandbox;


#pragma mark - Initializations

+ (BDArenaConnector*) getInstance;
+ (BOOL)hasInstance;
+ (BDArenaConnector*) initializeWithAppKey:(NSString*)_appKey runInSandboxEnvironment:(BOOL)_runInSandbox;

#pragma mark - Auth local Player and events observers

- (void) requestAuth;
- (void) registerEventsObserver:(id)observer;
- (void) unregisterEventsObserver:(id)observer;

#pragma mark - Player infos managment

- (BOOL) isLocalPlayerAuthenticated;
- (BOOL) isLocalPlayerRegistered;

- (NSString*) getAccessToken;
- (BDArenaPlayerData*) getLocalPlayerData;
- (void) getDataForPlayerWithAuid:(NSInteger)auid;
- (void) getDataForPlayersWithAuids:(NSArray*)auids;

- (void) registerLocalPlayerProfileWithEmail:(NSString*)email
                                    nickname:(NSString*)nickname
                                    password:(NSString*)password
                                 dateOfBirth:(NSInteger)dateOfBirth
                                      isMale:(BOOL)isMale
                                   imageData:(NSData*)imageData;

- (void) updateLocalPlayerProfileWithNickname:(NSString*)nickname
                                  newPassword:(NSString*)newPassword
                                  oldPassword:(NSString*)oldPassword
                                  dateOfBirth:(NSInteger)dateOfBirth
                                       isMale:(BOOL)isMale
                                    imageData:(NSData*)imageData;
- (void) logout;
- (void) loginWithEmail:(NSString*)email andPassword:(NSString*)password;

#pragma mark - Adv

- (void) advBannerStartRotation;
- (void) advBannerStopRotation;

- (void) advEnableRotationForBannerFormat:(BDArenaAdvBannerFormat)bannerformat;
- (void) advDisableRotationForBannerFormat:(BDArenaAdvBannerFormat)bannerformat;

- (BOOL) advIsBannerRotationActive;

- (UIView*) advGetBannerViewForAdFormat:(BDArenaAdvBannerFormat)bannerFormat;
- (UIView*) advGetFullscreenSmartphoneBannerView;
- (UIView*) advGetFullscreenTabletBannerView;

- (void) advRequestBannerWithFormat:(BDArenaAdvBannerFormat)bannerFormat;
- (void) advRequestBannerInView:(UIView*)bannerView withFormat:(BDArenaAdvBannerFormat)bannerFormat;
- (void) advRequestSmartphoneFullscreenBanner;
- (void) advRequestTabletFullscreenBanner;

// INCLUDE_CLIP_ADS
- (void) advRequestAdClipInView:(UIView*)clipContainerView withConfiguration:(BDArenaAdClipConfigData*)config;
- (void) advRequestAdClipInView:(UIView*)clipContainerView;
- (void) advPlayAdClipInView:(UIView*)clipContainerView;
// INCLUDE_CLIP_ADS -eof-

@end
