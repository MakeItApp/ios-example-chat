//
//  BDArenaConsoleController.h
//  BDArenaConnectorClient
//
//  Created by Salvatore Iodice on 2/24/12.
//  Copyright (c) 2012 ArenaDaemon Srl. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "BDArenaConsoleControllerDelegate.h"

@interface BDArenaConsoleController : UITabBarController

@property (nonatomic, assign) id <BDArenaConsoleControllerDelegate> consoleDelegate;
@property (nonatomic, assign) BOOL isVisible;

@property (nonatomic, retain) UIColor*    baseColor;
@property (nonatomic, retain) UIColor*    buttonColor;
@property (nonatomic, retain) UIColor*    avatarImageBorderColor;
@property (nonatomic, retain) UIColor*    buttonTextColor;
@property (nonatomic, retain) UIColor*    textColor;
@property (nonatomic, retain) UIColor*    privacyPolicyTextColor;
@property (nonatomic, retain) UIColor*    textFieldFontColor;
@property (nonatomic, retain) UIColor*    textFieldBorderColor;
@property (nonatomic, retain) UIColor*    achievementsPercentageRingColor;
@property (nonatomic, retain) NSString*   fontNameNormal;
@property (nonatomic, retain) NSString*   fontNameBold;
@property (nonatomic, assign) CGFloat     fontSize;
@property (nonatomic, retain) UIColor*    popoverColor;

@property (nonatomic, retain) UIImage*    meBackgroundImage;
@property (nonatomic, retain) UIImage*    leaderboardsBackgroundImage;
@property (nonatomic, retain) UIImage*    achievementsBackgroundImage;

@property (nonatomic, retain) UIImage*	  loginLogoutButtonImage;			// 200x40 px
@property (nonatomic, retain) UIImage*	  editRegisterButtonImage;			// 200x40 px
@property (nonatomic, retain) UIImage*	  editSaveButtonImage;				// 200x40 px
@property (nonatomic, retain) UIImage*	  editCancelButtonImage;			// 200x40 px
@property (nonatomic, retain) UIImage*	  passwordEditChangeButtonImage;	// 155x30 px
@property (nonatomic, retain) UIImage*	  ageButtonImage;					// 80x30 px
@property (nonatomic, retain) UIImage*	  genderSwitchBaseImage;			// 80x30 px
@property (nonatomic, retain) UIImage*	  genderSwitchHandleImage;			// 28x28 px

@property (nonatomic, retain) UIImage*    meTabbarIconSelectedImage;
@property (nonatomic, retain) UIImage*    meTabbarIconUnselectedImage;
@property (nonatomic, retain) UIImage*    leaderboardsTabbarIconSelectedImage;
@property (nonatomic, retain) UIImage*    leaderboardsTabbarIconUnselectedImage;
@property (nonatomic, retain) UIImage*    achievementsTabbarIconSelectedImage;
@property (nonatomic, retain) UIImage*    achievementsTabbarIconUnselectedImage;

@property (nonatomic, retain) UIColor*    meTabbarSelectedTextColor;
@property (nonatomic, retain) UIColor*    meTabbarUnselectedTextColor;
@property (nonatomic, retain) UIColor*    leaderboardsTabbarSelectedTextColor;
@property (nonatomic, retain) UIColor*    leaderboardsTabbarUnselectedTextColor;
@property (nonatomic, retain) UIColor*    achievementsTabbarSelectedTextColor;
@property (nonatomic, retain) UIColor*    achievementsTabbarUnselectedTextColor;


@property (nonatomic, assign) BOOL          showMeSection;   // me controller is required
@property (nonatomic, assign) BOOL          showLeaderboardsSection;
@property (nonatomic, assign) BOOL          showAchievementsSection;

@property (nonatomic, assign) BOOL							prefersTranslucentBars;
@property (nonatomic, assign) BOOL							prefersStatusBarHidden;
@property (nonatomic, assign) UIStatusBarStyle				preferredStatusBarStyle;
@property (nonatomic, assign) UIInterfaceOrientationMask	preferredInterfaceOrientationMask;

@property (nonatomic, assign) BOOL			showCloseButton;

+ (BDArenaConsoleController*) getInstance;
+ (BOOL) hasInstance;

- (void) presentConsoleWithBaseViewController:(UIViewController*)parentController;
- (void) dismissConsoleController;

@end
