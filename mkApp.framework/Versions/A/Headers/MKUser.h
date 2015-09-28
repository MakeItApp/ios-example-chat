//
//  MKUser.h
//  mkApp
//
//  Created by Mia Srl on 4/2/13.
//  Copyright (c) 2013 MakeItApp.eu. All rights reserved.
//

#import "MKCollection.h"

@interface MKUser : MKCollection

/** Getting User Info */

/**
 The user name
 */
@property (nonatomic, copy, readonly) NSString *userName;

/**
 The user email
 */
@property (nonatomic, copy, readonly) NSString *email;

/**
 The user has been validated
 */
@property (nonatomic, readonly, getter = isValidated) BOOL validated;

/**
 The user gravatar url
 */
@property (nonatomic, copy, readonly) NSString* gravatarUrlString;

/**
 The user global id
 */
@property (nonatomic, copy, readonly) NSString* userGlobalId;

/** @name MKUser methods */


/*!
 Creates a new MKUser object.
 @result Returns a new MKUser object.
 */
+ (MKUser *)user;


/**
 Log out a user
 @param error The error object to be set on error
 @return `YES` on success, `NO` on error
 */
- (BOOL)logout:(NSError **)error;

/**
 Return if the current user is logged
 @param error The error object to be set on error
 @return `YES` on success, `NO` on error
 */
- (BOOL)loggedUser:(NSError **)error;


/*!
 Makes an asynchronous request to log in a user with specified credentials.
 Returns an instance of the successfully logged in MKUser.
 @param username The username of the user.
 @param password The password of the user.
 @param store If YES user will be saved locally on keychain for future login.
 @param block The block to execute.
 */
+ (void)logInWithUsernameInBackground:(NSString *)username
                             password:(NSString *)password
                              service:(BOOL)service
                      storeUserLocaly:(BOOL)store
                                block:(void (^)(MKUser *user, NSError *error))block;

/*!
 Makes an asynchronous request to log in a user with specified credentials.
 Returns an instance of the successfully logged in MKUser.
 @param email The email of the user.
 @param password The password of the user.
 @param block The block to execute.
 */

+ (void)logInWithEmailInBackground:(NSString *)email
                             password:(NSString *)password
                                block:(void (^)(MKUser *user, NSError *error))block __attribute__((deprecated));

/*!
 Makes an asynchronous request to log in a user with specified credentials.
 Returns an instance of the successfully logged in MKUser.
 @param email The email of the user.
 @param password The password of the user.
 @param store If YES user will be saved locally on keychain for future login.
 @param block The block to execute.
 */

+(void)logInWithEmailInBackground:(NSString *)email
                         password:(NSString *)password
                           storeUserLocaly:(BOOL)store
                            block:(void (^)(MKUser *user, NSError *error))block;

/*!
 Makes an asynchronous request to log in with the last user credential.
 Returns an instance of the successfully logged in MKUser, error or YES if there's no connection to internet.
 @param block The block to execute.
 */
+(void)loginWithLocalStoredUser:(void (^)(MKUser *user, NSError *error,BOOL localCredential))block;

/*!
Makes an asynchronous request to recover lost password.
@param block The block to execute: error is nil if recovery email has been successfully sent 
*/

+(void)restoreLostPasswordForUserEmail:(NSString*)email  inBackgroundWithBlock:(void (^)(NSError *error))block;

/*!
 Makes an asynchronous request to resend user verification email.
 @param block The block to execute: error is nil if verification email has been successfully sent
 */

+(void)resendVerificationEmail:(NSString*)email  inBackgroundWithBlock:(void (^)(NSError *error))block;
@end
