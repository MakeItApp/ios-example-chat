//
//  BDArenaNotificationsManager.h
//  ArenaTester
//
//  Created by saver on 4/16/13.
//  Copyright (c) 2013 ArenaDaemon Srl. All rights reserved.
//

#import <UIKit/UIKit.h>

#define badgesAnimationDuration         0.5
#define badgesStayOnScreenDuration      2.0

@interface BDArenaNotificationsManager : UIViewController{
    UIWindow*       _window;
    UILabel*        label;
    UIImageView*    imageView;
    UIImageView*    outFrame;
    
    CGFloat         yOffset;
    
    CGPoint         authBadgePosition;
    BOOL            isPanelShowing;
    BOOL            isShowAnimationInProgress;
    BOOL            isPanelHiding;
    BOOL            isRotating;
    
    UIInterfaceOrientation currentOrientation;
    
    NSInteger authBadgeHeight;
    NSInteger authBadgeWidthPortrait;
    NSInteger authBadgeWidthLandscape;
    NSInteger authBadgeWidthIPad;

}

- (void) showAuthBadgeWithText:(NSString*)text;
- (void) showAuthBadgeWithText:(NSString*)text withImage:(UIImage*)image;

@end
