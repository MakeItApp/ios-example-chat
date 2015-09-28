    //
//  MKLoginDelegate.h
//  mkApp
//
//  Created by Francesco Soncini Sessa on 20/07/14.
//  Copyright (c) 2014 MakeItApp.eu. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MKUser;
@class MKLoginViewController;
@class MKRegisterViewController;

@protocol MKLoginDelegate <NSObject>

- (void)loginViewControllerDidCancelLogin:(MKLoginViewController *)logInController;
- (void)loginViewController:(MKLoginViewController *)loginController didLogInUser:(MKUser *)user;
- (void)loginViewController:(MKLoginViewController *)loginController didFailLogin:(NSError *)error;

- (void)registerViewController:(MKRegisterViewController *)registerController didCreateUser:(MKUser *)user;
- (void)registerViewController:(MKRegisterViewController *)registerController didFailCreateUser:(NSError *)error;

@optional

- (BOOL)loginViewController:(MKLoginViewController *)loginController shouldBeginLoginWithUsername:(NSString *)username;
- (BOOL)registerViewController:(MKRegisterViewController *)registerController shouldBeginCreateUsername:(NSString *)username;

@end
