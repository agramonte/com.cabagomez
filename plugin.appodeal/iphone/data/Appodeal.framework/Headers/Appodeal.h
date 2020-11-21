//
//  Appodeal.h
//  Appodeal
//
//  AppodealSDK version 2.7.4
//
//  Copyright (c) 2020 Appodeal, Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <Appodeal/APDDefines.h>
#import <Appodeal/APDSdk.h>

#import <Appodeal/APDInterstitialAd.h>
#import <Appodeal/APDRewardProtocol.h>
#import <Appodeal/APDRewardedVideo.h>

#import <Appodeal/APDMRECView.h>
#import <Appodeal/APDBannerView.h>

#import <Appodeal/APDNativeAdViewProtocol.h>
#import <Appodeal/APDNativeAdQueue.h>
#import <Appodeal/APDNativeAd.h>
#import <Appodeal/APDImage.h>

#if __has_include(<StackConsentManager/StackConsentManager.h>)
#import <StackConsentManager/StackConsentManager.h>
#endif
/**
 Appodeal ads SDK
 */
@interface Appodeal : NSObject
/**
 Unavailable initializer
 @return nil
 */
+ (instancetype _Nonnull)alloc NS_UNAVAILABLE;
/**
 Unavailable initializer
 @return nil
 */
- (instancetype _Nonnull)init NS_UNAVAILABLE;
/**
 Unavailable initializer
 @return nil
 */
+ (instancetype _Nonnull)new NS_UNAVAILABLE;
/**
 Return all registred networks name
 @note Objective-C
 <pre> [Appodeal registeredNetworkNames]; </pre>
 @note Swift
 <pre> Appodeal.registeredNetworkNames() </pre>
 @return registred networks name
 */
+ (NSArray <NSString *>*_Nonnull)registeredNetworkNames;
/**
 To disable a networks use this method
 @note Objective-C
 <pre> [Appodeal disableNetworks:@[@"YOUR_NETWORK_NAME"]]; </pre>
 @note Swift
 <pre> Appodeal.disableNetwork(["YOUR_NETWORK_NAME"]) </pre>
 @warning Use method before initialization!
 @param networks Array of Networks name
 */
+ (void)disableNetworks:(NSArray <NSString *>* _Nullable)networks;
/**
 To disable a networks of type use this method
 @note Objective-C
 <pre> [Appodeal disableNetworks:@[@"YOUR_NETWORK_NAME"] forAdType:AppodealAdType]; </pre>
 @note Swift
 <pre> Appodeal.disableNetwork(["YOUR_NETWORK_NAME"], adType:AppodealAdType) </pre>
 @warning Use method before initialization!
 @param networks Array of Networks name
 @param adType AppodealAdTypeInterstitial, AppodealAdTypeBanner, AppodealAdTypeNativeAd, AppodealAdTypeRewardedVideo, AppodealAdTypeMREC, AppodealAdTypeNonSkippableVideo
 */
+ (void)disableNetworks:(NSArray <NSString *>* _Nullable)networks forAdType:(AppodealAdType)adType;
/**
 To disable a network use this method
 @note Objective-C
 <pre> [Appodeal disableNetwork:@"YOUR_NETWORK_NAME"]; </pre>
 @note Swift
 <pre> Appodeal.disableNetwork("YOUR_NETWORK_NAME") </pre>
 @warning Use method before initialization!
 @param networkName Network name to disable
 */
+ (void)disableNetwork:(nonnull NSString *)networkName;
/**
 To disable a network use this method
 @note Objective-C
 <pre> [Appodeal disableNetworkForAdType:AppodealAdTypeInterstitial name:@"YOUR_NETWORK_NAME"]; </pre>
 @note Swift
 <pre> Appodeal.disableNetworkForAdType(AppodealAdType.Interstitial, name: "YOUR") </pre>
 @warning Use method before initialization!
 @param adType AppodealAdTypeInterstitial, AppodealAdTypeBanner, AppodealAdTypeNativeAd, AppodealAdTypeRewardedVideo, AppodealAdTypeMREC, AppodealAdTypeNonSkippableVideo
 @param networkName Use network name
 */
+ (void)disableNetworkForAdType:(AppodealAdType)adType name:(nonnull NSString *)networkName;
/**
 Get predicted eCPM for type
 @param type AppodealAdTypeInterstitial, AppodealAdTypeBanner, AppodealAdTypeNativeAd, AppodealAdTypeRewardedVideo, AppodealAdTypeNonSkippableVideo
 @return predicated ecpm
 */
+ (double)predictedEcpmForAdType:(AppodealAdType)type;
/**
 Set flag NO if you have disabled locationTracking, and YES that enabled
 @note To disable location check, use this method
 @note Objective-C
 <pre> [Appodeal setLocationTracking:YES]; </pre>
 @note Swift
 <pre> Appodeal.setLocationTracking(true) </pre>
 @warning Use method before initialization!
 @param enabled flag
 */
+ (void)setLocationTracking:(BOOL)enabled;
/**
 Enable/disable autocache
 @note After initializing the SDK, start caching ads of those types that were enabled as autocache
 Default autocache enabled for AppodealAdTypeInterstitial, AppodealAdTypeBanner, AppodealAdTypeRewardedVideo or AppodealAdTypeNonSkippableVideo
 Also you can do something like this to disable autocache:
 @note Objective-C
 <pre> [Appodeal setAutocache: NO types: AppodealAdTypeInterstitial | AppodealAdTypeRewardedVideo] </pre>
 @note Swift
 <pre> Appodeal.setAutocache(false, types: AppodealAdType.Interstitial) </pre>
 @warning Use method before initialization!
 @param autocache Bolean flag
 @param types AppodealAdTypeRewardedVideo or AppodealAdTypeNonSkippableVideo, AppodealAdTypeInterstitial, AppodealAdTypeSkippableVideo
 */
+ (void)setAutocache:(BOOL)autocache types:(AppodealAdType)types;
/**
 Get autocache enablement
 @note Objective-C
 <pre> [Appodeal isAutocacheEnabled:AppodealAdTypeInterstitial]; </pre>
 @note Swift
 <pre> Appodeal.isAutocacheEnabled(AppodealAdType.Interstitial) </pre>
 @warning After initialization!
 @param types AppodealAdTypeRewardedVideo, AppodealAdTypeInterstitial, AppodealAdTypeSkippableVideo
 @return If enabled return YES or NO if not
 */
+ (BOOL)isAutocacheEnabled:(AppodealAdType)types;
/**
 Initialize method. To initialize Appodeal with several types you
 can do something like this:
 @note Objective-C
 <pre> [Appodeal initializeWithApiKey:YOUR_API_KEY types: AppodealAdTypeInterstitial | AppodealAdTypeRewardedVideo hasConsent:YES]; </pre>
 @note Swift
 <pre>
 let adTypes: AppodealAdType = [.banner, .interstitial]
 Appodeal.initialize(withApiKey: "API_KEY", types: adTypes, hasConsent: true) </pre>
 @param apiKey Your api key from Appodeal Dashboard
 @param types  Appodeal ad type
 @param consent User has given consent to the processing of personal data relating to him or her. https://www.eugdpr.org/
 */
+ (void)initializeWithApiKey:(nonnull NSString *)apiKey types:(AppodealAdType)types hasConsent:(BOOL)consent;
/**
 Initialize method. To initialize Appodeal with several types you
 user consent on personal data processing assumes to be true
 can do something like this:
 @note Objective-C
 <pre> [Appodeal initializeWithApiKey:YOUR_API_KEY types: AppodealAdTypeInterstitial | AppodealAdTypeRewardedVideo]; </pre>
 @note Swift
 <pre>
 let adTypes: AppodealAdType = [.banner, .interstitial]
 Appodeal.initialize(withApiKey: "API_KEY", types: adTypes) </pre>
 @param apiKey Your api key from Appodeal Dashboard
 @param types  Appodeal ad type
 */
+ (void)initializeWithApiKey:(nonnull NSString *)apiKey types:(AppodealAdType)types;
/**
 Disable calls of precache callbacks
 @note Objective-C
 <pre> [Appodeal setTriggerPrecacheCallbacks:YES]; </pre>
 @note Swift
 <pre> Appodeal.setTriggerPrecacheCallbacks(true) </pre>
 @param shouldTrigger Bolean flag indicates that precache callbacks are disabled or not
 */
+ (void)setTriggerPrecacheCallbacks:(BOOL)shouldTrigger;
/**
 Get that SDK initialized
 @note Objective-C
 <pre> [Appodeal isInitalizedForAdType:AppodealAdTypeInterstitial]; </pre>
 @note Swift
 <pre> isInitalizedForAdType(.Interstitial) </pre>
 @warning Use method after initialization!
 @param type Type you want to check on initialisation.
 @return YES if sdk initialized or NO if not. In this method used strict compare!
 */
+ (BOOL)isInitalizedForAdType:(AppodealAdType)type;
/**
 Appodeal supports multiple log levels for internal logging,
 and ONLY one (VERBOSE) log level for third party ad networks.
 To enable third party ad networks logging, set log level to APDLogLevelVerbose.
 If log level other than APDLogLevelVerbose, all third party ad networks logging will be suppressed (if possible).
 *
 @param logLevel APDLogLevel value
 */
+ (void)setLogLevel:(APDLogLevel)logLevel;
/**
 Set framework type before initialization!
 @note Objective-C
 <pre> [Appodeal setFramework:APDFrameworkNative version:@"5.1"]; </pre>
 @note Swift
 <pre> Appodeal.setFramework(APDFramework.native, "5.1") </pre>
 @param framework Framework type, default is iOS Native SDK
 @param version Framework version. Default nill
 */
+ (void)setFramework:(APDFramework)framework version:(nullable NSString *)version;
/**
 Set plugin version use before initialization!
 @note Objective-C
 <pre> [Appodeal setPluginVersion:@"1.0.0"]; </pre>
 @note Swift
 <pre> Appodeal.setPluginVersion("1.0.0") </pre>
 @param pluginVersion -  NSString value, default nil
 */
+ (void)setPluginVersion:(nonnull NSString *)pluginVersion;
/**
 Set custom extra data for sdk
 @param extras NSDictionary with NSString key and JSON encodable object
 */
+ (void)setExtras:(nullable NSDictionary <NSString *, id> *)extras;
/**
 Set interstitial delegate to get callbacks
 @note Objective-C
 <pre> [Appodeal setInterstitialDelegate:self]; </pre>
 @note Swift
 <pre> Appodeal.setInterstitialDelegate(self) </pre>
 @warning Use method before or after initialization!
 @param interstitialDelegate Object that implement AppodealInterstitialDelegate protocol
 */
+ (void)setInterstitialDelegate:(nullable id<AppodealInterstitialDelegate>)interstitialDelegate;
/**
 Set banner delegate to get callbacks
 @note Objective-C
 <pre> [Appodeal setBannerDelegate:self]; </pre>
 @note Swift
 <pre> Appodeal.setBannerDelegate(self) </pre>
 @warning Use method before or after initialization!
 @param bannerDelegate Object that implements AppodealBannerDelegate protocol
 */
+ (void)setBannerDelegate:(nullable id<AppodealBannerDelegate>)bannerDelegate;
/**
 Set rewarded video delegate to get callbacks
 @note Objective-C
 <pre> [Appodeal setRewardedVideoDelegate:self]; </pre>
 @note Swift
 <pre> Appodeal.setRewardedVideoDelegate(self) </pre>
 @warning Use method before or after initialization!
 @param rewardedVideoDelegate Object that implements AppodealRewardedVideoDelegate protocol
 */
+ (void)setRewardedVideoDelegate:(nullable id<AppodealRewardedVideoDelegate>)rewardedVideoDelegate;
/**
 Set non skippable video delegate to get callbacks
 @note Objective-C
 <pre> [Appodeal setNonSkippableVideoDelegate:self]; </pre>
 @note Swift
 <pre> Appodeal.setNonSkippableVideoDelegate(self) </pre>
 @warning Use method before or after initialization!
 @param nonSkippableVideoDelegate Object that implements AppodealNonSkippableVideoDelegate protocol
 */
+ (void)setNonSkippableVideoDelegate:(nullable id<AppodealNonSkippableVideoDelegate>)nonSkippableVideoDelegate;
/**
 *  Setup preferred banner size for show styles AppodealShowStyleBannerBottom, AppodealShowStyleBannerTop
 *  method not affect APDBannerView or AppodealBannerView. Method can be called before Appodeal initialisation
 *  by defualt preferred banner size is kAppodealUnitSize_320x50 for phones and kAppodealUnitSize_728x90 for tab
 *  @warning If method was called after initialisation, sdk doesn't clear any caches and can show already cached banner
 *  @discussion Objective-C
 *  @code [Appodeal setPreferredBannerAdSize:kAppodealUnitSize_320x50]; @endcode
 *  @discussion Swift
 *  @code Appodeal.setPreferredBannerAdSize(kAppodealUnitSize_320x50) @endcode
 *  @param adSize - Preferred banner size
 */
+ (void)setPreferredBannerAdSize:(APDUnitSize)adSize;
/**
 Appodeal banner view to custom placement
 @note Objective-C
 <pre> [Appodeal banner]; </pre>
 @note Swift
 <pre> Appodeal.banner() </pre>
 @warning We highly recommend to use APDSdk and APDBannerView if you want to get custom placement of banner ads in your app
 @return View that contains banner ad
 */
+ (nullable UIView *)banner;
/**
 If an ad of this type is ready, the ad shows at once. But if not, an ad starts caching and shows after caching, if it has time to within 3 seconds.
 @note Objective-C
 <pre> [Appodeal showAd:AppodealAdTypeInterstitial rootViewController:UIViewController]; </pre>
 @note Swift
 <pre> Appodeal.showAd(AppodealShowStyle.Interstitial, rootViewController: UIViewController!) </pre>
 @param style              AppodealAdTypeInterstitial, AppodealAdTypeSkippableVideo, AppodealAdTypeBanner, AppodealAdTypeNativeAd, AppodealAdTypeRewardedVideo, AppodealAdTypeMREC, AppodealAdTypeNonSkippableVideo
 @param rootViewController Controller for present ads. If contoller is nil SDK will use own window for present fullscreen ad and root controller of key window for in line ads
 @return YES if possible to show or NO if not
 */
+ (BOOL)showAd:(AppodealShowStyle)style rootViewController:(nullable UIViewController *)rootViewController;
/**
 If an ad of this type is ready, the ad shows at once. But if not, an ad starts caching and shows after caching, if it has time to within 3 seconds.
 @see <pre> + (BOOL)showAd:(AppodealShowStyle)style rootViewController:(UIViewController *)rootViewController;</pre>
 @note Objective-C
 <pre> [Appodeal showAd:AppodealAdTypeInterstitial forPlacement:@"PLACEMENT" rootViewController:UIViewController]; </pre>
 @note Swift
 <pre> Appodeal.showAd(AppodealShowStyle.Interstitial, forPlacement: String!, rootViewController: UIViewController!) </pre>
 @param style AppodealAdTypeInterstitial, AppodealAdTypeSkippableVideo, AppodealAdTypeBanner, AppodealAdTypeNativeAd, AppodealAdTypeRewardedVideo, AppodealAdTypeMREC, AppodealAdTypeNonSkippableVideo
 @param placement Placement name configured in segments settings on Appodeal Dashboard
 @param rootViewController Controller for present ads. If contoller is nil SDK will use own window for present fullscreen ad and root controller of key window for in line ads
 @return YES if possible to show or NO if not
 */
+ (BOOL)showAd:(AppodealShowStyle)style forPlacement:(nonnull NSString *)placement rootViewController:(nullable UIViewController *)rootViewController;
/**
 Checker for ad is ready and can be shown by current placement
 @note Objective-C
 <pre> [Appodeal canShow:AppodealAdTypeInterstitial forPlacement:MY_PLACEMENT]; </pre>
 @note Swift
 <pre> Appodeal.canShowAd(AppodealShowStyle.Interstitial, forPlacement:MY_PLACEMENT) </pre>
 @param type AppodealAdTypeInterstitial, AppodealAdTypeRewardedVideo, AppodealAdTypeBanner, etc
 @param placement String placement name from dashboard
 @return YES if possible to show or NO if not
 */
+ (BOOL)canShow:(AppodealAdType)type forPlacement:(nonnull NSString *)placement;
/**
 Return reward object currencyName as NSString, and amount as NSUInteger
 */
+ (nonnull id<APDReward>)rewardForPlacement:(nonnull NSString *)placement;
/**
 Start caching an ad for type; if autocache is disabled,
 start loading for default placement
 Ad will not be shown after loading
 @note Objective-C
 <pre> [Appodeal cacheAd:AppodealAdTypeInterstitial]; </pre>
 @note Swift
 <pre> Appodeal.cacheAd(AppodealAdType.Interstitial) </pre>
 @param type AppodealAdTypeInterstitial, AppodealAdTypeBanner, AppodealAdTypeNativeAd, AppodealAdTypeRewardedVideo, AppodealAdTypeMREC, AppodealAdTypeNonSkippableVideo
 */
+ (void)cacheAd:(AppodealAdType)type;
/**
 Hide banner if on screen
 @note Objective-C
 <pre> [Appodeal hideBanner]; </pre>
 @note Swift
 <pre> Appodeal.hideBanner() </pre>
 */
+ (void)hideBanner;
/**
 Enable testing mode.
 In this mode you will get a test ad with <b>eCPM = 0$</b>
 @note Objective-C
 <pre> [Appodeal setTestingEnabled:YES]; </pre>
 @note Swift
 <pre> Appodeal.setTestingEnabled(true) </pre>
 @warning Use method before initialization!
 @param testingEnabled Bolean flag
 */
+ (void)setTestingEnabled:(BOOL)testingEnabled;
/**
 In-app purchase tracking.
 Call this method after user makes an in-app purchase
 @param amount Amount of in-app purchase, for example @0.99
 @param currency In-app purchase currency, for example @"USD"
 */
+ (void)trackInAppPurchase:(nonnull NSNumber *)amount currency:(nonnull NSString *)currency;
/**
 Get current SDK version
 @note Objective-C
 <pre> [Appodeal getVersion]; </pre>
 @note Swift
 <pre> Appodeal.getVersion() </pre>
 @return Current SDK version
 */
+ (nonnull NSString *)getVersion;
/**
 Check that ad is ready to show
 @note Objective-C
 <pre> [Appodeal isReadyForShowWithStyle:AppodealShowStyleInterstitial]; </pre>
 @note Swift
 <pre> Appodeal.isReadyForShowWithStyle(AppodealShowStyle.Interstitial) </pre>
 @param showStyle AppodealShowStyleInterstitial, AppodealShowStyleVideoOrInterstitial, AppodealShowStyleBannerTop, AppodealShowStyleBannerBottom, AppodealShowStyleRewardedVideo, AppodealShowStyleNonSkippableVideo
 @return YES if ready or NO if not
 */
+ (BOOL)isReadyForShowWithStyle:(AppodealShowStyle)showStyle;
/**
 Check that ad is precache ad or not
 @note Objective-C
 <pre> [Appodeal isPrecacheAd:AppodealAdTypeInterstitial]; </pre>
 @note Swift
 <pre> Appodeal.isPrecacheAd(.Interstitial) </pre>
 @param adType one of supported ad type. Not pass mask that contains several types!
 @return YES if loaded ad is precache or NO if ad not loaded or loaded simple ad
 */
+ (BOOL)isPrecacheAd:(AppodealAdType)adType;
/**
 You can set custom rule by using this method.
 Configure rules for segments in <b>Appodeal Dashboard</b>.
 @note For example, you want to create a segment of users who complete 20 or more levels
 You create a rule in the dashboard with name "completedLevels" of type Int,
 operator GreaterThanOrEqualTo and value 10, and then you implement the following code:
 @note Objective-C
 <pre>
 NSDictionary * customRule = {@"completedLevels" : CURRENT_NUMBER_OF_COMPLETED_LEVELS};
 [[APDSdk sharedSdk] setSegmentFilter: segmentFilter];
 </pre>
 @note Swift
 <pre>
 let customRule = ["completedLevels" : CURRENT_NUMBER_OF_COMPLETED_LEVELS]
 APDSdk .sharedSdk().setSegmentFilter(segmentFilter)
 </pre>
 Call this method any time you want, segments change dynamically
 @note And then CURRENT_NUMBER_OF_COMPLETED_LEVELS become 10 or greater
 Your segments settings become available
 @param segmentFilter NSDictionary instance with keys that are similar to keys that you turn on in Appodeal Dashboard's Segment settings block and values of similar types
 */
+ (void)setSegmentFilter:(nonnull NSDictionary *)segmentFilter __deprecated_msg("This method is deprecated. Use +setCustomState: instead");
/**
You can set custom rule by using this method.
Configure filters for segments/placements in <b>Appodeal Dashboard</b>.
@note For example, you want to create a segment of users who complete 20 or more levels
You create a rule in the dashboard with name "completedLevels" of type Int,
operator GreaterThanOrEqualTo and value 10, and then you implement the following code:
@note Objective-C
<pre>
NSDictionary *customState = {
 @"completedLevels" : CURRENT_NUMBER_OF_COMPLETED_LEVELS
};
[Appodeal setCustomState:customState];
</pre>
@note Swift
<pre>
let customState = [
 "completedLevels" : CURRENT_NUMBER_OF_COMPLETED_LEVELS
]
Appodeal.setCustomState(customState)
</pre>
Call this method any time you want, segments change dynamically
@note And then CURRENT_NUMBER_OF_COMPLETED_LEVELS become 10 or greater
Your segments settings become available
@param customState NSDictionary instance with keys that are similar to keys that you turn on in Appodeal Dashboard's Segment settings block and values of similar types
*/
+ (void)setCustomState:(nonnull NSDictionary *)customState;
/**
 Autoresized banner support. Default set to YES;
 @warning Call this method before caching banners!
 @note Objective-C
 <pre> [Appodeal setSmartBannersEnabled:YES]; </pre>
 @note Swift
 <pre> Appodeal.setSmartBannersEnabled(true) </pre>
 @param smartBannerEnabled If YES, the banner will resize depending on screen size. If NO, the banner has a fixed size (320x50 on iPhone and 728x90 on iPad)
 */
+ (void)setSmartBannersEnabled:(BOOL)smartBannerEnabled;
/**
 Banner background visibility setter. Default set to NO.
 @note Objective-C
 <pre> [Appodeal setBannerBackgroundVisible:YES]; </pre>
 @note Swift
 <pre> Appodeal.setBannerBackgroundVisible(true) </pre>
 @warning Call this method before caching banners!
 @param bannerBackgroundVisible If YES, the banner will have a background. If NO, the banner background will be transparent
 */
+ (void)setBannerBackgroundVisible:(BOOL)bannerBackgroundVisible __deprecated_msg("This method is deprecated and will be removed in next release");
/**
 Banner animation setter. Default set to YES
 @note Objective-C
 <pre> [Appodeal setBannerAnimationEnabled:YES]; </pre>
 @note Swift
 <pre> Appodeal.setBannerAnimationEnabled(true) </pre>
 @warning Call this method before caching banners!
 @param bannerAnimationEnabled If YES, the banner will refresh with animation (UIViewAnimationOptionTransitionCrossDissolve). If NO, the banner will refresh without animation;
 */
+ (void)setBannerAnimationEnabled:(BOOL)bannerAnimationEnabled;
/**
Banner rotation angles for left and right show styles. Default leftRotationAngleDegrees equals to 90,
rightRotationAngleDegrees equals to 270
@note Objective-C
<pre> [Appodeal setBannerLeftRotationAngleDegrees:-90 rightRotationAngleDegrees: 90]; </pre>
@warning Call this method before caching banners!
@param leftRotationAngleDegrees Angle for rotation transform of banner for AppodealShowStyleBannerLeft
@param rightRotationAngleDegrees Angle for rotation transform of banner for AppodealShowStyleBannerRight
*/
+ (void)setBannerLeftRotationAngleDegrees:(CGFloat)leftRotationAngleDegrees
                rightRotationAngleDegrees:(CGFloat)rightRotationAngleDegrees;
/**
 Enable COPPA setting flag. By defualt this setting is false
 @param childDirectedTreatment Boolean flag inficates that app for kids.
 */
+ (void)setChildDirectedTreatment:(BOOL)childDirectedTreatment;
/**
  User has given consent to the processing of personal data relating to him or her.
  @param consent Boolean flag that indicates that user give consent on personal data processing
*/
+ (void)updateConsent:(BOOL)consent;
/**
 Pause all curent sdk work. All mediation task will invalidate asap and your get
 callbacks on fail to load. If SDK currently has loaded ad - it will
 be release and sdk fire expire events. Also autocache will be disabled.
 Call this method to reduce RAM and CPU
 usage in high load placec in your app.
 */
+ (void)pause NS_UNAVAILABLE;
/**
 Resume SDK work after pause. Autocache state turn back.
 */
+ (void)resume NS_UNAVAILABLE;
/**
 Release any loaded resiurces, that depended in sdk work.
 @warning SDK work can recover only in next app session
 */
+ (void)stop NS_UNAVAILABLE;
/**
 Unavailable method
 */
+ (void)deinitialize NS_UNAVAILABLE;

@end
/**
 Set user metadata for relevant ad targeting
 */
@interface Appodeal (UserMetadata)
/**
 User ID setter
 @note Objective-C
 <pre> [Appodeal setUserId:@"USER_ID"]; </pre>
 @note Swift
 <pre> Appodeal.setUserId("USER_ID") </pre>
 @param userId Set userId as string
 */
+ (void)setUserId:(nonnull NSString *)userId;
/**
 User age setter
 @note Objective-C
 <pre> [Appodeal setUserAge:25]; </pre>
 @note Swift
 <pre> Appodeal.setUserAge(25) </pre>
 @param age Set age as integer value
 */
+ (void)setUserAge:(NSUInteger)age;
/**
 User gender setter
 @note Objective-C
 <pre> [Appodeal setUserGender:AppodealUserGenderMale]; </pre>
 @note Swift
 <pre> Appodeal.setUserGender(AppodealUserGender.male) </pre>
 @param gender AppodealUserGenderOther, AppodealUserGenderMale, AppodealUserGenderFemale
 */
+ (void)setUserGender:(AppodealUserGender)gender;
 @end


#if __has_include(<StackConsentManager/StackConsentManager.h>)
@interface Appodeal (ConsentManager)
/**
 Initialize method. To initialize Appodeal with several types you
 can do something like this:
 @note Objective-C
 <pre> [Appodeal initializeWithApiKey:YOUR_API_KEY types: AppodealAdTypeInterstitial | AppodealAdTypeRewardedVideo consentReport:consentReport]; </pre>
 @note Swift
 <pre>
 let adTypes: AppodealAdType = [.banner, .interstitial]
 Appodeal.initialize(withApiKey: "API_KEY", types: adTypes, consentReport: consentReport) </pre>
 @param apiKey Your api key from Appodeal Dashboard
 @param types  Appodeal ad type
 @param consentReport Consent report object from Stack Consent Manager
*/
+ (void)initializeWithApiKey:(nonnull NSString *)apiKey
                       types:(AppodealAdType)types
               consentReport:(nonnull id <STKConsent>)consentReport;
/**
  User has update consent through Stack Consent Manager .
  @param consentReport Consent report object from Stack Consent Manager
*/
+ (void)updateConsentReport:(nonnull id<STKConsent>)consentReport;
@end
#endif
