//
//  BDArenaAdvConnectorDelegate.h
//  
//
//  Created by saver on 3/25/13.
//  Copyright (c) 2013 ArenaDaemon Srl. All rights reserved.
//

#ifndef BDArenaConnectorClient_BDArenaAdvConnectorDelegate_h
#define BDArenaConnectorClient_BDArenaAdvConnectorDelegate_h

#import <Foundation/Foundation.h>
#import "BDArenaDataObjects.h"

@class BDArenaAdvConnector;

@protocol BDArenaAdvConnectorDelegate <NSObject>

@optional

- (void) arenaAdvConnector:(BDArenaAdvConnector*)connector willStartRequestForFullscreenBannerView:(UIView*)fullscreenBannerView;
- (void) arenaAdvConnector:(BDArenaAdvConnector*)connector willStartRequestForBannerView:(UIView*)bannerView;

- (void) arenaAdvConnector:(BDArenaAdvConnector*)connector didReceiveAdForBannerView:(UIView*)bannerView;
- (void) arenaAdvConnector:(BDArenaAdvConnector*)connector didReceiveAdForFullscreenBannerView:(UIView*)fullscreenBannerView;

- (void) arenaAdvConnector:(BDArenaAdvConnector*)connector didFailToReceiveAdForBannerView:(UIView*)bannerView withError:(NSError*)error;
- (void) arenaAdvConnector:(BDArenaAdvConnector*)connector didFailToReceiveAdForFullscreenBannerView:(UIView*)fullscreenBannerView withError:(NSError*)error;

// fullscreen clip
- (void) arenaAdvConnector:(BDArenaAdvConnector*)connector didFailToReceiveFullscreenClipWithError:(NSError*)error;
- (void) arenaAdvConnector:(BDArenaAdvConnector*)connector didReceiveFullscreenClipAd:(UIView*)fullscreenClipView;

// landing
- (void) arenaAdvConnector:(BDArenaAdvConnector*)connector willPresentLandingScreen:(UIView*)bannerView;
- (void) arenaAdvConnector:(BDArenaAdvConnector*)connector willDismissLandingScreen:(UIView*)bannerView;
- (void) arenaAdvConnector:(BDArenaAdvConnector*)connector didDismissLandingScreen:(UIView*)bannerView;

- (void) arenaAdvConnector:(BDArenaAdvConnector*)connector clipReadyToPlayInView:(UIView*)clipContainerView;
- (void) arenaAdvConnector:(BDArenaAdvConnector*)connector clipInView:(UIView*)clipContainerView didUpdateAdPlaybackTime:(NSTimeInterval)playbackTime adDuration:(NSTimeInterval)duration;
- (void) arenaAdvConnector:(BDArenaAdvConnector*)connector clipInView:(UIView*)clipContainerView didFailToReceiveAdWithError:(NSError*)error;
- (void) arenaAdvConnector:(BDArenaAdvConnector*)connector clipInView:(UIView*)clipContainerView didFinishPlaybackWithReason:(BDArenaAdvAdClipDidFinishReason)reason;

@end

#endif
