//
//  MKBannerView.h
//  mkApp
//
//  Created by FSS on 16/02/14.
//  Copyright (c) 2014 MakeItApp.eu. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum  {
    MKAdTypeBanner,
    MKAdTypeMediumRectangle,
    MKAdTypeInterstitial,
    MKAdTypeOfferWall
} MKAdType;

typedef enum  {
    MKNoneCachedInterstitial=-1,
    MKVideoInterstitial,
    MKInterstitial,
    MKNoIncentivatedInterstitial,
    MKVideoRewardInterstitial,
    MKMiaInterstitial =5
} MKInterstitialType;

typedef enum {
    MKUserGenderUndefined = 0,
    MKUserGenderMale,
    MKUserGenderFemale
} MKUserGender;

@class MKBannerView;
@class MKUserData;

@protocol MKBannerViewDelegate <NSObject>
@optional
/*!
 @method bannerView:didFailToReceiveAdWithError:
 @discussion
 Called when a banner view fails to load a new advertisement
 @param banner The banner view that failed to load an advertisement.
 @param error The error object that describes the problem
 */
- (void)bannerView:(MKBannerView *)banner didFailToReceiveAdWithError:(NSError *)error;
/*!
 @method bannerViewActionDidFinish:
 @discussion
 Called after a banner view finishes executing an action that covered your application’s user interface.
 @param banner The banner view that finished executing an action.
 */
- (void)bannerViewActionDidFinish:(MKBannerView *)banner;

/*!
 @method bannerViewActionShouldBegin:willLeaveApplication:
 @discussion
 Called before a banner view executes an action
 @param banner The banner view that the user tapped.
 @param willLeave YES if another application will be launched to execute the action; NO if the action is going to be executed inside your application.
 @return Your delegate returns YES if the banner action should execute; NO to prevent the banner action from executing.
 */
- (BOOL)bannerViewActionShouldBegin:(MKBannerView *)banner willLeaveApplication:(BOOL)willLeave;

/*!
 @method bannerViewDidLoadAd:
 @discussion
 Called when a new banner advertisement is loaded.
 @param banner The banner view that loaded a new advertisement.
 */
- (void)bannerViewDidLoadAd:(MKBannerView *)banner;
/*!
 @method bannerViewWillLoadAd:
 @discussion
 Called before a new banner advertisement is loaded.
 @param banner The banner view that is about to load a new advertisement.
 */
- (void)bannerViewWillLoadAd:(MKBannerView *)banner;

/*!
 @method bannerViewInterstitialIsReady:
 @discussion
 Called when an Interstitial as been loaded and it's ready to be shown
 @param banner The banner interstitial view that is ready
 */
- (void)bannerViewInterstitialIsReady:(MKBannerView *)banner;

/*!
 @method )bannerViewWillShowInterstitial:
 @discussion
 Called before showing a new interstitial
 @param banner The banner view that is about to load a new advertisement.
 */
- (void)bannerViewWillShowInterstitial:(MKBannerView *)banner;

/*!
 @method )bannerViewDidCloseInterstitial:
 @discussion
 User close the interstitial before completition or after but without click it
 @param banner The banner view presented the interstitial
 */
- (void)bannerViewDidCloseInterstitial:(MKBannerView *)banner;

/*!
 @method )bannerViewDidClickInterstitial:
 @discussion
 User click the interstitial adv or complete the video
 @param banner The banner view presented the interstitial
 */
- (void)bannerViewDidClickInterstitial:(MKBannerView *)banner;

/*!
 @method )bannerViewReward:
 @discussion
 User is entitle to get a reward for watched video or Offer Wall or incentivated Click
 @param banner The banner view presented the interstitial
 @param credits The credits earned
 */
- (void)bannerViewReward:(MKBannerView *)banner reward:(NSInteger)credits;

/*!
 @method bannerViewDidDisappearInterstitial:
 @discussion
 Called when interstitial view has been removed
 @param banner The banner view that has shown the interstitial advertisement.
 */
- (void)bannerViewDidDisappearInterstitial:(MKBannerView *)banner;



/*!
 @method bannerView:rewardedVideoAvailable:
 @discussion
 Called when rewarded Video are available after an invocation of checkForRewardedVideoAvailability
 @param banner The banner view that will have rewarded video available.
 @param adUnitsInfo a dictionary containing
    (NSNumber) numOfAdUnits – This represents the amount of available video
    (NSNumber) totalNumberCredits – the number of credits the user will earn from watching all videos
    (NSNumber) firstCampaignCredits – The number of credits the user will earn from watching the first video
 */
-(void)bannerView:(MKBannerView *)banner rewardedVideoAvailable:(NSDictionary *) adUnitsInfo;


/*!
 @method bannerView:rewardedInterstitialAvailable:
 @discussion
 Called after checkForRewardedInterstitialAvailability as been called
 @param banner is the bannerView whose availability has been checked .
 @param available is YES when an Interstitial is ready to be shown
 */
-(void)bannerView:(MKBannerView *)banner rewardedInterstitialAvailable:(BOOL) available;


@end

@interface MKBannerView : UIView

/*!
 * @class MKBannerView
 *
 * @discussion
 * Provides a view for displaying adv for other MIA Apps in an application. ADV are automatically
 * loaded, presented, and refreshed. When a banner view is tapped, the ADV will
 * begin its action.
 *
 * Note: MKBannerViews must be added to a view hierarchy managed by a
 * UIViewController. If view controller containment is being used, the controller
 * managing the banner view must be correctly configured to ensure banner action
 * presentation works correctly.
 */

/*!
* @property delegate
*
* @discussion
* The banner view delegate is notified when events related to the banner view
* and current ad occur, such as when a new ADV is loaded, when errors occur
* while fetching ads, or when banner actions begin and end.
*
* This property is a weak reference and cannot be used with
* objects that modify the behavior of release or retain.
*/
@property(nonatomic, assign) id<MKBannerViewDelegate> delegate;

/*!
 * @property bannerLoaded
 *
 * @discussion
 * YES if an ad is currently loaded, NO otherwise.
 */
@property(nonatomic, getter=isBannerLoaded) BOOL bannerLoaded;

/*!
 * @property bannerViewActionInProgress
 *
 * @discussion
 * YES if the user is currently engaged with a fullscreen interactive ad.
 */
@property (nonatomic, readonly, getter=isBannerViewActionInProgress) BOOL bannerViewActionInProgress;

/*!
 * @property mkadType
 *
 * @discussion
 * The banner view's ad type.
 */
@property (nonatomic) MKAdType adType;

/*!
 * @property miaBannerOnly
 *
 * @discussion
 * The banner will show only adv of MakeItApp App
 */
@property (nonatomic,getter=isMiaBannerOnly) BOOL miaBannerOnly;

/*!
 * @property lastInterstitialType
 *
 * @discussion
 *  The type of last interstitial shown
 */
@property (nonatomic) MKInterstitialType lastInterstitialType;

/*!
 * @property userData
 *
 * @discussion
 *  The mkuserdata information to get targeted ads with higher eCPM
 */
@property (nonatomic,strong) MKUserData* userData;

/*!
 * @property supportedInterstitialInterfaceOrientations
 *
 * @discussion
 *  The default behaviour of the Interstitial Adv is rotate for all the orientations.
 * If you want to change this you should set an array in this property with the
 * desired orientations.
 *
 * Example:
 * mkbannerview.supportedInterfaceOrientations = @[ @(UIInterfaceOrientationPortrait) ];
 */
@property(nonatomic, strong) NSArray *supportedInterstitialInterfaceOrientations;


/*!
 Creates a new MKBannerView
 @param type The type of banner to load
 @return The initialized MKBannerView
 */
-(id)initWithAdType:(MKAdType)type;


/*!
 Creates a Splash Interstitial if invoked from within the app delegate's
 application:didFinishLaunchingWithOptions:
 @param window The root windows
 @param image The strating splash image
 @param delegate The optional delegate to be invoked by Interstitial event
 */
+(void)loadAndDisplaySplashInterstitial:(UIWindow*)window
                           initialImage:(UIImage*)image
                               delegate:(NSObject<MKBannerViewDelegate>*)delegate;

/*!
 * @method cancelBannerViewAction
 *
 * @discussion
 * Cancels the current in-progress banner view action. This should only be used
 * in cases where the user's attention is required immediately.
 */
- (void)cancelBannerViewAction;

/*!
 * @method checkForAdv
 *
 * @discussion
 * Force Banner to check for available Adv
 *
 */
- (void)checkForAdv;


/*!
 * @method cacheInterstitial
 * Cache an interstitial adv
 *
 * @discussion
 * Force Banner to cache an Interstitial ADV
 *
 */
- (void)cacheInterstitial;

/*!
 * @method hasCacheInterstitial
 * Check if an Interstitial is ready to be shown
 *
 * @return TRUE if ready
 *
 */
- (BOOL)hasCacheInterstitial;

/*!
 * @method showInterstitial
 * Show the interstitial adv full screen
 *
 */
-(void)showInterstitial;

/*!
 * @method cacheInterstitialType
 * Return the type of cachedinterstitial
 * @return the type of intestitial cached
 */
-(MKInterstitialType)cacheInterstitialType;

/*!
 * @method cancelCachedInterstitial
 * Reset the interstitial cached
 *
 */
-(void)cancelCachedInterstitial;

/*!
 * @method getMissingVideosPerReward
 * Return the number of video adv that user must see to get entitle for a reward
 * @return the number off missing video
 */
-(NSInteger)getMissingVideosPerReward;


/*!
 * @method getMissingVideosPerReward
 * User decline to see rewarded video
 * 
 */
-(void)declineVideoRewarded;


/*!
 * @method checkForRewardedVideoAvailability
 * Check for Rewarded Video availability. It's used to insert rewarded video botton in Store section of your app
 * after the call of this method the answer  will be received throught delegate's method bannerView:rewardedVideoAvailable:
 * after a positive answer use showRewardedVideo to present the video to final user
 */

-(void)checkForRewardedVideoAvailability;

/*!
 * @method checkForRewardedInterstitialAvailability
 * Check for Rewarded Interstitial availability. It's used to insert rewarded interstitial botton in Store section of your app
 * after the call of this method the answer  will be received throught delegate's method bannerView:rewardedInterstitialAvailable:
 * after a positive answer use showRewardedInterstitial to present the interstitial to final user
 */
-(void)checkForRewardedInterstitialAvailability;

/*!
 * @method showOfferWall
 * Check for Offer Wall  availability and show it. It's used to insert offer wall botton in Store section of your app
 * after the call of this method you will get info of user actions as usual throught delegate's methods for interstitial
 *
 */
-(void)showOfferWall;

/*!
 * @method showRewardedVideo
 * Used to present Rewarded Video. Call it after a positive invocation of checkForRewardedVideoAvailability.
 * If there are no available video you will be notified througth delegate's method bannerView:didFailToReceiveAdWithError:
 *
 */
-(void)showRewardedVideo;

/*!
 * @method showRewardedInterstitial
 * Used to present Rewarded Interstitial. Call it after a positive invocation of checkForRewardedInterstitialAvailability.
 * If there are no available interstitial you will be notified througth delegate's method bannerView:didFailToReceiveAdWithError:
 *
 */
-(void)showRewardedInterstitial;


@end

@interface MKUserData : NSObject

/*!
 * @class MKUserData
 *
 * @discussion
 * Provides information about the user in order to get targeted ads with higher eCPM.
 *
 */

/*!
 * @property userGender
 *
 * @discussion
 * This property is used to set the user gender in order to get targeted ads with higher eCPM.
 *
 */
@property (nonatomic, assign) MKUserGender userGender;

/*!
 * @property userAgeRangeMin
 *
 * @discussion
 * This property is used to set the minumum of user age range in order to get targeted ads with higher eCPM.
 * You should set also set userAgeRangeMax or alternatively set userBirthday
 */
@property (nonatomic, assign) NSUInteger userAgeRangeMin;

/*!
 * @property userAgeRangeMax
 *
 * @discussion
 * This property is used to set the maximum of user age range in order to get targeted ads with higher eCPM.
 * You should set also set userAgeRangeMin or alternatively set userBirthday.
 */
@property (nonatomic, assign) NSUInteger userAgeRangeMax;

/*!
 * @property userBirthday
 *
 * @discussion
 * This property is used to set user age in order to get targeted ads with higher eCPM.
 * Alternatively you can set userAgeRangeMin and userAgeRangeMin.
 */
@property (nonatomic, strong) NSDate *userBirthday;

/*!
 * @property userInterests
 *
 * @discussion
 * This property is used to set user insterests in order to get targeted ads with higher eCPM.
 * You should pass an NSArray with NSStrings.
 */
@property (nonatomic, strong) NSArray *userInterests;

/*!
 * @property userPage
 *
 * @discussion
 * This property is used to set user page in order to get targeted ads with higher eCPM.
 * You should pass an NSStrings for a user page. Example user facebook page
 */
@property (nonatomic, strong) NSString *userPage;

/*!
 * @property userLatitude
 *
 * @discussion
 * This property is readonly containing the Latitude coordinate
 */
@property (nonatomic, assign, readonly) double userLatitude;


/*!
 * @property userLongitude
 *
 * @discussion
 * This property is readonly containing the Longitude coordinate
 */
@property (nonatomic, assign, readonly) double userLongitude;

/*!
 * @property userAccuracy
 *
 * @discussion
 * This property is readonly containing the coordinates accuracy
 */
@property (nonatomic, assign, readonly) double userAccuracy;

/*!
 * @property userName
 *
 * @discussion
 * This property is used to track the user name
 *
 */
@property (nonatomic, strong) NSString *userName;

/*!
 * @property userName
 *
 * @discussion
 * This property is used to display a readable user name
 *
 */
@property (nonatomic, strong) NSString *userAlias;

/*!
 * @method setUserLatitude:userLongitude:userAccuracy:
 *
 * @param userLatitude a double values for user latitude
 * @param userLongitude a double values for user longitude
 * @param userAccuracy a double values for current accuracy
 *
 * @discussion
 * This method is used to set user location in order to get targeted ads with higher eCPM.
 * You should pass double values for the user latitude, longitude and accuracy.
 *
 *
 * Example of usage:
 *
 * CLLocation *location = self.locationManager.location;
 *
 * [self.locationManager setDistanceFilter: kCLDistanceFilterNone];
 * [self.locationManager setDesiredAccuracy: kCLLocationAccuracyHundredMeters];
 * [self.locationManager startUpdatingLocation];
 * 
 * MKUserData* usData = [[MKUserData alloc] init];
 * [usData setUserLatitude: location.coordinate.latitude
 *         userLongitude: location.coordinate.longitude
 *         userAccuracy: location.horizontalAccuracy];
 */
- (void)setUserLatitude:(double)userLatitude userLongitude: (double)userLongitude userAccuracy: (double)userAccuracy;


@end
