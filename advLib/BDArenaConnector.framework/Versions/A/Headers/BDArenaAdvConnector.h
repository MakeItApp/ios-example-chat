//
//  BDArenaAdvConnector.h
//  BDArenaConnectorSDK
//
//  Created by saver on 3/12/13.
//  Copyright (c) 2013 ArenaDaemon Srl. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BDArenaDataObjects.h"
#import "BDArenaAdvConnectorDelegate.h"

@interface BDArenaBannerWebView : UIWebView

@property (nonatomic, retain) NSString* frequencyCapSlotIdentifier;

@end

@interface BDArenaAdvConnector : UIViewController <UIWebViewDelegate, BDArenaAdvConnectorDelegate> {
    BOOL        isRotationActive;
    BOOL        isRotationForBanner320x53Enabled;
    BOOL        isRotationForBanner300x250Enabled;
    BOOL        isRotationForBanner468x60Enabled;
    BOOL        isRotationForBanner728x90Enabled;
    
    NSThread*   rotationThread;
    NSString*   userAgent;
    NSString*   bannerTargetUrl;
	
    id <BDArenaAdvConnectorDelegate> delegate;
    
    // sockets
    BOOL    isBanner320x53RequestInAction;
    BOOL    isBanner300x250RequestInAction;
    BOOL    isBanner468x60RequestInAction;
    BOOL    isBanner728x90RequestInAction;
    
    BOOL    isFullscreenBannerSmartphoneRequestInAction;
    BOOL    isFullscreenBannerTabletRequestInAction;
    BOOL    isFullscreenClipRequestInAction;
    
    // views
    UIView*     bannerView320x53;
    UIView*     bannerView300x250;
    UIView*     bannerView468x60;
    UIView*     bannerView728x90;
    
    BDArenaBannerWebView*  bannerWebView320x53;
    BDArenaBannerWebView*  bannerWebView300x250;
    BDArenaBannerWebView*  bannerWebView468x60;
    BDArenaBannerWebView*  bannerWebView728x90;
    
    UIView*					fullscreenSmartphoneBannerView;
    UIView*					fullscreenTabletBannerView;
    BDArenaBannerWebView*	fullscreenSmartphoneWebView;
    BDArenaBannerWebView*	fullscreenTabletWebView;
	
	NSMutableArray*	clipControllersArray;
}

@property (nonatomic, assign) id <BDArenaAdvConnectorDelegate>  delegate;

// INCLUDE_CLIP_ADS -eof-
- (void) requestAdClipInView:(NSDictionary*)param;
- (void) playAdClipInView:(UIView*)clipContainerView;
// INCLUDE_CLIP_ADS -eof-

- (void) startBannerRotation;
- (void) stopBannerRotation;
- (BOOL) isAdvBannerRotationActive;

- (void) requestBannerWithFormat:(NSNumber*)bannerFormatObject;
- (void) requestFullscreenBannerAdWithFormat:(NSNumber*)bannerFormatObject;

- (UIView*) getBannerViewForFormat320x53;
- (UIView*) getBannerViewForFormat300x250;
- (UIView*) getBannerViewForFormat468x60;
- (UIView*) getBannerViewForFormat728x90;

- (UIView*) getFullscreenSmartphoneBannerView;
- (UIView*) getFullscreenTabletBannerView;

- (BOOL) isRotationActiveForBannerFormat:(BDArenaAdvBannerFormat)bannerFormat;
- (void) enableRotationForBannerFormat:(BDArenaAdvBannerFormat)bannerFormat;
- (void) disableRotationForBannerFormat:(BDArenaAdvBannerFormat)bannerFormat;

@end
