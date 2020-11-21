//
//  APDSdk.h
//  Appodeal
//
//  AppodealSDK version 2.7.4
//
//  Copyright © 2020 Appodeal, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Appodeal/APDUserInfo.h>
#import <Appodeal/APDDefines.h>

#if __has_include(<StackConsentManager/StackConsentManager.h>)
#import <StackConsentManager/StackConsentManager.h>
#endif

/**
 Main SDK object, that managed network request, ad modules and statistics data.
 You should initialize the SDK before you start loading any ad types.
 You can do this in
 <pre> - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions </pre>
 for example.
 
 @note For example initialization code can be something like this:
 <pre>
 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
 [[APDSdk sharedSdkWithApiKey: YOUR_API_KEY] initializeForAdTypes: APDAdTypeInterstitialAd];
 return YES;
 }
 </pre>
 
 After SDK initialization, you can get an instance of SDK by calling [APDSdk sharedSdk];
 You can additionally set other SDK settings before/after SDK initialization
 
 @warning You must call sharedSdkWithApiKey:(NSString *)apiKey firstly.
 */
@interface APDSdk : NSObject
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
 Singleton instance of APDSdk
 @note Objective-C <pre> [APDSdk sharedSdkWithApiKey:@"API_KEY"]; </pre>
 @note Swift <pre> APDSdk.sharedSdkWithApiKey("API_KEY") </pre>
 @param apiKey String API key parameter from Appodeal Dashboard
 @return Singleton instance of APDSdk
 */
+ (instancetype _Nonnull)sharedSdkWithApiKey:(nonnull NSString *)apiKey;
/**
 Always returns same instance SDK returned by first call of
 @see <pre> +sharedSdkWithApiKey: </pre>
 @note Objective-C <pre> [APDSdk sharedSdk]; </pre>
 @note Swift <pre> APDSdk.sharedSdk() </pre>
 @return Instance of APDSdk
 */
+ (instancetype _Nonnull)sharedSdk;
/**
 Call this method to specify framework before initialization
 @note Objective-C <pre> [[APDSdk sharedSdk] setFramework:APDFrameworkNative version:@"5.1"]; </pre>
 @note Swift <pre> APDSdk.sharedSdk().setFramework(APDFramework.native, "5.1") </pre>
 @param framework Type of framework. Default is native iOS SDK
 @param version Framework version. Default nill
 */
- (void)setFramework:(APDFramework)framework version:(nullable NSString *)version;
/**
 User has given consent to the processing of personal data relating to him or her.
 @param userConsent Boolean flag that indicates that user give consent on personal data processing
 */
- (void)setUserConsent:(BOOL)userConsent;
/**
 Call this method to specify framework before initialization
 @param pluginVersion NSString version plugin
 */
- (void)setPluginVersion:(nonnull NSString *)pluginVersion;
/**
 Set custom extra data for sdk
 @param extras NSDictionary with NSString key and JSON encodable value
 */
- (void)setExtras:(nullable NSDictionary <NSString *, id> *)extras;
/**
 Initialization of SDK for types
 @note Objective-C <pre> [[APDSdk sharedSdk] initializeForAdTypes:AppodealAdTypeInterstitial | AppodealAdTypeRewardedVideo]; </pre>
 @note Swift
 <pre>
 let adTypes: AppodealAdType = [.banner, .interstitial]
 APDSdk.sharedSdk().initializeForAdTypes(adTypes)
 </pre>
 @param adTypes APDAdTypeInterstitialAd, APDAdTypeBanner, APDAdTypeNativeAd, APDAdTypeRewardedVideo, APDAdTypeMREC
 */
- (void)initializeForAdTypes:(APDAdType)adTypes;
/**
 Check that SDK is initialized for ad type
 @note Objective-C <pre> [[APDSdk sharedSdk] isInitializedForAdType:AppodealAdTypeInterstitial]; </pre>
 @note Swift <pre> APDSdk.sharedSdk().isInitializedForAdType(APDAdType.interstitial) </pre>
 @param adType APDAdType value
 @return YES if SDK initialized for this type, or NO if not
 */
- (BOOL)isInitializedForAdType:(APDAdType)adType;
/**
 If you set YES to this method you get only
 test ad with 0$ eCPM
 @note Objective-C <pre> [[APDSdk sharedSdk] setTestingMode:YES]; </pre>
 @note Swift <pre> APDSdk.sharedSdk().setTesingMode(true) </pre>
 @warning use this method before initilized sdk
 @param enabled Boolean flag
 */
- (void)setTestingMode:(BOOL)enabled;
/**
 Set targeting for more relevant ads
 @note Objective-C
 <pre>
 APDUserInfo * userInfo = [APDUserInfo new];
 userInfo.age = 25;
 [[APDSdk sharedSdk] setUserInfo:userInfo];
 </pre>
 @note Swift
 <pre>
 let userInfo = APDUserInfo()
 userInfo.age = 25
 APDSdk.sharedSdk().setUserInfo(userInfo)
 </pre>
 @param userInfo Instance of APDUserInfo class
 */
- (void)setUserInfo:(nonnull APDUserInfo *)userInfo;
/**
 You can set custom rules by using this method.
 Configure rules for segments in <b>Appodeal Dashboard</b>.
 @note For example, if you want to create a segment of users who complete 20 or more levels,
 you create a rule in the dashboard with name "completedLevels" of type Int,
 operator GreaterThanOrEqualTo and value 10, now you implement following code:
 @note Objective-C
 <pre>
 NSDictionary * segmentFilter = {@"completedLevels" : CURRENT_NUMBER_OF_COMPLETED_LEVELS};
 [[APDSdk sharedSdk] setSegmentFilter: customRule];
 </pre>
 @note Swift
 And then CURRENT_NUMBER_OF_COMPLETED_LEVELS becomes 10 or greater
 Your segments settings become available
 @param segmentFilter NSDictionary instance with keys that are similar to  keys that you turn on in Appodeal Dashboard's Segment settings block and values of similar types
 */
- (void)setSegmentFilter:(nonnull NSDictionary <NSString *, id> *)segmentFilter __deprecated_msg("This method is deprecated. Use -setCustomState: instead");
/**
 You can set custom segments/placement filters by using this method.
 Configure rules for segments in <b>Appodeal Dashboard</b>.
 @note For example, if you want to create a segment of users who complete 20 or more levels,
 you create a rule in the dashboard with name "completedLevels" of type Int,
 operator GreaterThanOrEqualTo and value 10, now you implement following code:
 @note Objective-C
 <pre>
 NSDictionary *state = {
    @"completedLevels" : CURRENT_NUMBER_OF_COMPLETED_LEVELS
 };
 [[APDSdk sharedSdk] setCustomState:state];
 </pre>
 @note Swift
 And then CURRENT_NUMBER_OF_COMPLETED_LEVELS becomes 10 or greater
 Your segments settings become available
 @param customState NSDictionary instance with keys that are similar to  keys that you turn on in Appodeal Dashboard's Segment settings block and values of similar types
 */
- (void)setCustomState:(nonnull NSDictionary <NSString *, id> *)customState;
/**
 Appodeal SDK supports multiple log level for internal logging,
 and ONLY one (VERBOSE) log level for third party ad networks.
 To enable third party ad networks logging, set log level to APDLogLevelVerbose.
 If the log level is something other than APDLogLevelVerbose, all third party ad networks logging will be suppressed (if possible).
 @param logLevel APDLogLevel value
 */
+ (void)setLogLevel:(APDLogLevel)logLevel;
/**
 Disabling/enabling location tracking
 @param enabled Set to NO by default
 */
- (void)setLocationTracking:(BOOL)enabled;
/**
 Disabling/enabling child app
 @param childDirectedTreatment Set to NO by default
 */
- (void)setChildDirectedTreatment:(BOOL)childDirectedTreatment;

@end


@interface APDSdk (InAppPurchase)
/**
 In-app purchase tracking.
 Call this method after user makes an in-app purchase
 @param amount Amount of in-app purchase, for example @0.99
 @param currency In-app purchase currency, for example @"USD"
 */
- (void)trackInAppPurchase:(nonnull NSNumber *)amount currency:(nonnull NSString *)currency;

@end

#if __has_include(<StackConsentManager/StackConsentManager.h>)
@interface APDSdk (ConsentManager)
/**
  User has update consent through Stack Consent Manager.
  @param consentReport Consent report object from Stack Consent Manager
*/
- (void)setConsentReport:(nonnull id<STKConsent>)consentReport;
@end
#endif
