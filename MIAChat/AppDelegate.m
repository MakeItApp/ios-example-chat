//
//  AppDelegate.m
//  MIAChat
//
//  Created by Jacopo Giola on 02/04/15.
//  Copyright (c) 2015 MIA Srl. All rights reserved.
//

#import "AppDelegate.h"
#import "MIAChatViewController.h"
#import <mkApp/mkApp.h>

@interface AppDelegate ()

@end

@implementation AppDelegate

#pragma mark - Application Life Cycle

- (BOOL)application:(UIApplication *)application willFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    return YES;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [[MKAppInstance sharedInstance] setProjectAPIname:@"miachat"];
    [[MKAppInstance sharedInstance] setAPISecret:@"fc5d6a93690eeb15d4e1add60f9ebb40afb331d21ebc8d5419de405a03791a02a35649482512ee606d79c49030e5e054a7fc975a3e60407dcf2638c08e13522ef8358c3bfa73c1f2a0df03fc151f7ee21c1313aed795804a3a80e5ef51f615846045935e03cd9cfbc4bbb0daa9fad1f987b47584e05669c8a630a05f0bed82e5ab58ed201430ee2fe6d1f773792bcbda89fc4a6b61eb4368d686bd722c0c9fcb65452a1cc5d839672a9394b4baeb861fbe877fa09bb9036a6099786407e34b4d4797ee372220ceb48fa8a0e47cfe01713cf64042a5e318f189c5d0cc0c9162b9dbde641fa15b5aff17aad094b7002f701d5f8288347ea78120c1b2ebd533c069"];
    [[MKAppInstance sharedInstance] setAPIEndpointType:MKProduction];

    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    application.applicationIconBadgeNumber = 0;
}

- (void)applicationWillTerminate:(UIApplication *)application
{
}

#pragma mark - Push Handling

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    MKUser *user = [[MKAppInstance sharedInstance] getLoggedUser];
    [[MKAppInstance sharedInstance] didRegisterForRemoteNotificationsWithDeviceToken:deviceToken forUser:user block:NULL];
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error
{

}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{
    application.applicationIconBadgeNumber = 0;
    [[NSNotificationCenter defaultCenter] postNotificationName:kRemoteNotificationReceived object:nil];
}

@end
