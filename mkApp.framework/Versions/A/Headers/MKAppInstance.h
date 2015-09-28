//
//  MKManager.h
//  mkApp
//
//  Created by FSS
//  Copyright (c) 2012 makeitapp.eu All rights reserved.
//
#import <mkApp/mkApp.h>
@class MKUser;
@class MKCollection;

typedef enum{
    MKProduction,
    MKDevelop,
    MKTest
}MKEndPointType;

typedef NS_ENUM(NSInteger, MKNotificationStytle) {
    MKNotificationStyleDefault,
    MKNotificationStyleError,
    MKNotificationStyleSuccess,
    MKNotificationStyleInfo,
    MKNotificationStyleWarning,
    MKNotificationStyleMia
};

typedef void (^MKNotificationTouchHandler)(void);

/**
 The manager is used to configure mkApp parameters
 */
@interface MKAppInstance : NSObject

@property(strong,atomic) NSString* projectAPIname;

/**
 *  @brief Set JSON Data format in seconds. The default is in millisecondi
 *  @description 'YES' to enable json date format in seconds
 */
@property (assign) BOOL jsonDateFormatInSeconds;

/**
 *  @brief Force collection name to lowercase in REST JSON request and query. The default is 'NO'
 *  @description 'YES' to force lowercase collection name
 */
@property (assign) BOOL jsonCollectionNameLowerCaseOnly;

/**
 *  @brief Force to never show "Welcome Back" notification at user login
 *  @description 'YES' prevent welcome messagge to be displayed
 */
@property (assign) BOOL neverNotifyLogin;


/** @name sharedInstance */

/**
 The singleton instance
 @return Returns the singleton, the first call create it
 @exception nil
 */

+ (MKAppInstance *)sharedInstance;


/** @name getLoggedUser */

/**
 The logged user
 @return Returns the logged User or nil
 @exception nil
 */

-(MKUser*)getLoggedUser;

/** @name refreshLoggedUser: */

/**
 *  If logged User is not nil refreshes the User with data stored on the server
 *  Returns the refreshed logged User or nil
 */

-(void)refreshLoggedUser:(void (^)(MKUser* user, NSError *error))block;

/** @name API Endpoint */

/**
 The API endpoint
 @return Returns the API endpoint absolute URL string
 @exception NSInternalInconsistencyException Raises exception if API endpoint is not set
 */
- (NSString *)APIEndpoint;

/**
 The API secret
 @return Returns the API secret string
 @exception NSInternalInconsistencyException Raises exception if API secret is not set
 */
- (NSString *)APISecret;

/**
 Set the API secret 
 @param secret The API secret
 */
- (void)setAPISecret:(NSString *)secret;

/**
 Set the API endpoint
 @param absoluteString The absolute URL string for the API endpoint
 */
//+ (void)setAPIEndpoint:(NSString *)absoluteString;
-(void)setAPIEndpointType:(MKEndPointType)type;

/**
 Returns the URL for the specified API method
 @param method The method name
 @return The method endpoint URL
 */
- (NSURL *)endpointForMethod:(NSString *)method;


/** @name Serial Request Queue */

/**
 Dispatch queue for API requests
 @return The shared serial dispatch queue for API requests
 */
- (dispatch_queue_t)queue;

/** @name Debug */

/**
 Enables the request log.
 
 This is useful for tracking down performance issues during development
 @param flag `YES` to enable logging, `NO` to disable
 */
- (void)setRequestLogEnabled:(BOOL)flag;

/**
 Returns the request log status
 @return `YES` if the request log is enabled, `NO` otherwise
 */
- (BOOL)requestLogEnabled;


/**
 Rester the device token on the Baas for remote push notification
 @param devToken get this from AppDelegate application:didRegisterForRemoteNotificationsWithDeviceToken:
 @param user the associated user. It's optional insert nil if you don't know the user that own the device
 */
-(void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)devToken forUser:(MKUser*)user __attribute__((deprecated));

/**
 Rester the device token on the Baas for remote push notification
 @param devToken get this from AppDelegate application:didRegisterForRemoteNotificationsWithDeviceToken:
 @param user the associated user. It's optional insert nil if you don't know the user that own the device
 @param block the callback block
 */
-(void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)devToken forUser:(MKUser*)user block:(void (^)(MKCollection *device, NSError *error))block;

/**
 Register the App for RemoteNotification
 Call this method in your AppDelegate application:didFinishLaunchingWithOptions:
 */
+(void)refisterForRemoteNotification;

@end
