//
//  BDArenaConnectorDelegate.h
//  BDArenaConnectorClient
//
//  Created by Salvatore Iodice on 3/2/12.
//  Copyright (c) 2012 ArenaDaemon Srl. All rights reserved.
//

#ifndef BDArenaConnectorClient_BDArenaConnectorDelegate_h
#define BDArenaConnectorClient_BDArenaConnectorDelegate_h

#import "BDArenaConnector.h"

@class BDArenaConnector;

@protocol BDArenaConnectorDelegate <NSObject>

@optional

- (void) arenaConnector:(BDArenaConnector*)connector didStartTask:(ARENA_TASK)task;

// auth player
- (void) arenaConnector:(BDArenaConnector*)connector authReceivedForLocalPlayerWithData:(BDArenaPlayerData*)playerData alreadyMet:(BOOL)alreadyMet isOffline:(BOOL)isOffline;
- (void) arenaConnector:(BDArenaConnector*)connector authFailedForLocalPlayerWithError:(NSError*)error;

// register player
- (void) arenaConnector:(BDArenaConnector*)connector registerProfileSuccessForLocalPlayerWithData:(BDArenaPlayerData*)playerData;
- (void) arenaConnector:(BDArenaConnector*)connector registerProfileFailedForLocalPlayerWithError:(NSError*)error;

// update player info
- (void) arenaConnector:(BDArenaConnector*)connector updateProfileSuccessForLocalPlayerWithData:(BDArenaPlayerData*)playerData;
- (void) arenaConnector:(BDArenaConnector*)connector updateProfileFailedForLocalPlayerWithError:(NSError*)error;

// logout delegate
- (void) arenaConnectorLogoutSuccess;
- (void) arenaConnector:(BDArenaConnector*)connector logoutFailedForLocalPlayerWithError:(NSError*)error;

// login delegate
- (void) arenaConnector:(BDArenaConnector*)connector loginSuccessForLocalPlayerWithData:(BDArenaPlayerData*)playerData;
- (void) arenaConnector:(BDArenaConnector*)connector loginFailedForLocalPlayerWithError:(NSError*)error;

// remote player did updateProfile
- (void) arenaConnector:(BDArenaConnector*)connector profileDidChangeForPlayer:(BDArenaPlayerData*)playerData;

// remote player data
- (void) arenaConnector:(BDArenaConnector*)connector getPlayerDataFailedWithError:(NSError*)error;
- (void) arenaConnector:(BDArenaConnector*)connector getPlayerDataSuccessfullyCompleted:(BDArenaPlayerData*)playerData;
- (void) arenaConnector:(BDArenaConnector*)connector getPlayersDataFailedWithError:(NSError*)error;
- (void) arenaConnector:(BDArenaConnector*)connector getPlayersDataSuccessfullyCompletedWithArray:(NSArray*)playersArray;

// adv
- (void) arenaConnector:(BDArenaConnector*)connector willStartRequestForFullscreenBannerView:(UIView*)fullscreenBannerView;
- (void) arenaConnector:(BDArenaConnector*)connector willStartRequestForBannerView:(UIView*)bannerView;

- (void) arenaConnector:(BDArenaConnector*)connector didReceiveAdForBannerView:(UIView*)bannerView;
- (void) arenaConnector:(BDArenaConnector*)connector didReceiveAdForFullscreenBannerView:(UIView*)fullscreenBannerView;


- (void) arenaConnector:(BDArenaConnector*)connector didFailToReceiveAdForBannerView:(UIView*)bannerView withError:(NSError*)error;
- (void) arenaConnector:(BDArenaConnector*)connector didFailToReceiveAdForFullscreenBannerView:(UIView*)fullscreenBannerView withError:(NSError*)error;

- (void) arenaConnector:(BDArenaConnector*)connector willPresentLandingScreen:(UIView*)bannerView;
- (void) arenaConnector:(BDArenaConnector*)connector willDismissLandingScreen:(UIView*)bannerView;
- (void) arenaConnector:(BDArenaConnector*)connector didDismissLandingScreen:(UIView*)bannerView;

- (void) arenaConnector:(BDArenaConnector*)connector clipReadyToPlayInView:(UIView*)clipContainerView;
- (void) arenaConnector:(BDArenaConnector*)connector clipInView:(UIView*)clipContainerView didUpdateAdPlaybackTime:(NSTimeInterval)playbackTime adDuration:(NSTimeInterval)duration;
- (void) arenaConnector:(BDArenaConnector*)connector clipInView:(UIView*)clipContainerView didFailToReceiveAdWithError:(NSError*)error;
- (void) arenaConnector:(BDArenaConnector*)connector clipInView:(UIView*)clipContainerView didFinishPlaybackWithReason:(BDArenaAdvAdClipDidFinishReason)reason;

@end

#endif
