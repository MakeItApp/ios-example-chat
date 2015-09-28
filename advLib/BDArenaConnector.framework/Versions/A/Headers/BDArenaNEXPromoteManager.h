//
//  NEXPromoteManager.h
//  PromoteSDK
//
//  Copyright (c) 2014 Nextology. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, BDArenaLogLevel) {
    BDArenaLogLevelNone = 0,
    BDArenaLogLevelActive,
    BDArenaLogLevelVerbose
};

typedef NS_ENUM(NSInteger, BDArenaPromoteType) {
    BDArenaPromoteTypeAlert = 0
};

@class BDArenaPromoteManager;

@protocol BDArenaPromoteManagerDelegate <NSObject>

@optional

/*!
 *  @brief Tell the delegate that the last request is failed with the given error.
 *  @param manager The manager whom invoke this method.
 *  @param type The type of the adv that had failed.
 *  @param error The error object with the description of the failure.
 */
- (void)promoteManager:(BDArenaPromoteManager *)manager didFailForType:(BDArenaPromoteType)type withError:(NSError *)error;
/*!
 *  @brief Tell the delegate that the last request is ended successfully.
 *  @param manager The manager whom invoke this method.
 *  @param type The type of the adv that has finish to load.
 */
- (void)promoteManager:(BDArenaPromoteManager *)manager didLoadDataWithType:(BDArenaPromoteType)type;

/*!
 *  @brief Tell the delegate that the promote adv is going to be showed.
 *  @param manager The manager whom invoke this method.
 *  @param type The type of the adv that will be shown.
 */
- (void)promoteManager:(BDArenaPromoteManager *)manager willShowPromoteWithType:(BDArenaPromoteType)type;
/*!
 *  @brief Tell the delegate that the promote adv was dismissed.
 *  @param manager The manager whom invoke this method.
  *  @param type The type of the adv that was shown.
 */
- (void)promoteManager:(BDArenaPromoteManager *)manager didClosePromoteWithType:(BDArenaPromoteType)type;
/*!
 *  @brief Tell the delegate that the promote adv is going to open a link outside the app.
 *  @param manager The manager whom invoke this method.
 *  @param type The type of the adv that trigger the event.
 */
- (void)promoteManager:(BDArenaPromoteManager *)manager willLeaveTheAppWithType:(BDArenaPromoteType)type;

@end

@interface BDArenaPromoteManager : NSObject

@property (nonatomic, weak) id <BDArenaPromoteManagerDelegate> delegate;

/*!
 *  @brief Initialize the shared instance.
 *  @discussion Call this method as early as possible. Likely in application:didFinishLaunchingWithOptions: of UIApplicationDelegate.
 *  @param publisherID The unique string that identifies you.
 *  @param propertyID The unique string that identifies your property.
 */
+ (void)startWithPublisherID:(NSString *)publisherID propertyID:(NSString *)propertyID;
/*!
 *  @brief Change the log level. Default is BDArenaLogLevelNone. Call before all other code for better results.
 *  @param logLevel The new log level.
 */
+ (void)setLogLevel:(BDArenaLogLevel)logLevel;

/*!
 *  @brief Return the shared instance. Don't ever call alloc init to create the object.
 *  @discussion If you don't ever call the startWithClientID:secret: method this will return nil.
 */
+ (instancetype)sharedInstance;

/*!
 *  @brief Enable the debug requests.
 *  @warning Do not leave this call to YES in production.
 *  @param flag Indicate if enable or disable the debug mode.
 */
- (void)setDebug:(BOOL)flag;
/*!
 *  @brief Call this method to load new data for the alert adv.
 */
- (void)startAlertRequest;
/*!
 *  @brief Return if an alert is available to be shown.
 */
- (BOOL)isAlertAvailable;
/*!
 *  @brief Call this method to open the alert with the current adv available.
 */
- (void)showAlert;
/*!
 *  @brief Call this method in applicationDidEnterBackground: of the UIApplicationDelegate.
 */
- (void)handleDidEnterBackground;

@end
