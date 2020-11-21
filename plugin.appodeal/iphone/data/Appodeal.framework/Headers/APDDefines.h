//
//  APDDefines.h
//  Appodeal
//
//  AppodealSDK version 2.7.4
//
//  Copyright © 2020 Appodeal, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

FOUNDATION_EXPORT NSString * _Nonnull const kAPDBuildIdendtifier;
typedef CGSize APDUnitSize;
FOUNDATION_EXPORT const APDUnitSize kAppodealUnitSize_320x50;
FOUNDATION_EXPORT const APDUnitSize kAppodealUnitSize_728x90;
/**
 Array of available ad sizes

 @return Ad sizes array boxed into NSVAlue
 */
FOUNDATION_EXPORT NSArray * _Nonnull AppodealAvailableUnitSizes(void);
/**
 Check that size is on of supported

 @param size Size
 @param supportedSizes Array of sizes boxed into NSValue
 @return Flag that indicates size can be use as ad size
 */
FOUNDATION_EXPORT BOOL AppodealIsUnitSizeSupported(const CGSize size, NSArray * _Nonnull supportedSizes);
/**
 Check that rect size can be use as aad size

 @param size Real view size
 @return Flag that indicates size can be use as ad size
 */
FOUNDATION_EXPORT BOOL AppodealIsUnitSizeAvailable(const CGSize size);
/**
 Сhoose nearers ad size for given real view rect size

 @param size Real view size
 @return Nearest ad size
 */
FOUNDATION_EXPORT CGSize AppodealNearestUnitSizeForSize(CGSize size);
/**
 Appodeal ads types

 - AppodealAdTypeInterstitial: Interstitial ads. Includes video and static formats
 - AppodealAdTypeBanner: Banner ad
 - AppodealAdTypeNativeAd: Native ads
 - AppodealAdTypeRewardedVideo: Rewarded video (return reward parameter in finish callback, can not be skipped by user)
 - AppodealAdTypeMREC: Rectangle banner of size 300 x 250
 - AppodealAdTypeNonSkippableVideo: Non-skippable video (does not return reward parameter in finish callback, can not be skipped by user)
 */
typedef NS_OPTIONS(NSInteger, AppodealAdType) {
    AppodealAdTypeInterstitial      = 1 << 0,
    AppodealAdTypeBanner            = 1 << 2,
    AppodealAdTypeNativeAd          = 1 << 3,
    AppodealAdTypeRewardedVideo     = 1 << 4,
    AppodealAdTypeMREC              = 1 << 5,
    AppodealAdTypeNonSkippableVideo = 1 << 6,
};
/**
 APDSdk supported ad types bit mask. You can initialize sdk with
 several ad types, by usage binary operand |
 For example: APDAdTypeInterstitialAd | APDAdTypeSkippableVideo

 - APDAdTypeInterstitialAd: Interstital ad
 - APDAdTypeBanner: Banner ad
 - APDAdTypeNativeAd: Native ad
 - APDAdTypeRewardedVideo: Rewarded ad
 - APDAdTypeMREC: Rectangle ad of size 300x250
 */
typedef NS_OPTIONS(NSUInteger, APDAdType) {
    APDAdTypeInterstitialAd = AppodealAdTypeInterstitial,
    APDAdTypeBanner         = AppodealAdTypeBanner,
    APDAdTypeNativeAd       = AppodealAdTypeNativeAd,
    APDAdTypeRewardedVideo  = AppodealAdTypeRewardedVideo,
    APDAdTypeMREC           = AppodealAdTypeMREC
};
/**
 Appodeal show styles bit masks

 - AppodealShowStyleInterstitial: Show interstitial ad
 - AppodealShowStyleBannerTop: Show banner ad at the top of screen
 - AppodealShowStyleBannerBottom: Show banner ad at the bottom of screen
 - AppodealShowStyleRewardedVideo: Show rewarded video
 - AppodealShowStyleNonSkippableVideo: Show non skippable video
 */
typedef NS_OPTIONS(NSInteger, AppodealShowStyle) {
    AppodealShowStyleInterstitial       = 1 << 0,
    AppodealShowStyleBannerTop          = 1 << 2,
    AppodealShowStyleBannerBottom       = 1 << 3,
    AppodealShowStyleRewardedVideo      = 1 << 4,
    AppodealShowStyleNonSkippableVideo  = 1 << 5,
    AppodealShowStyleBannerLeft         = 1 << 6,
    AppodealShowStyleBannerRight        = 1 << 7
};
/**
 User gender

 - AppodealUserGenderOther: User not define gender
 - AppodealUserGenderFemale: Female
 - AppodealUserGenderMale: Male
 */
typedef NS_ENUM(NSUInteger, AppodealUserGender) {
    AppodealUserGenderOther = 0,
    AppodealUserGenderFemale,
    AppodealUserGenderMale
};
/**
 Declaration of banner delegate
 */
@protocol AppodealBannerDelegate <NSObject>
@optional
/**
 Method called when precached or usual banner view loads
 *
 @param precache If precache is YES it means that precached ad loaded
 */
- (void)bannerDidLoadAdIsPrecache:(BOOL)precache;
/**
 Method called if banner mediation failed
 */
- (void)bannerDidFailToLoadAd;
/**
 Method called when banner view did fail to load
 */
- (void)bannerDidExpired;
/**
 Method called when user taps on banner
 */
- (void)bannerDidClick;
/**
 Method called when banner shows or refreshes
 */
- (void)bannerDidShow;

@end
/**
 Interstital delegate declaration
 */
@protocol AppodealInterstitialDelegate <NSObject>
@optional
/**
 Method called when precached or usual interstitial view loads
 @warning If you want show only expensive ads, ignore this callback call with precache equal to YES
 *
 @param precache If precache is YES it means that precached ad loaded
 */
- (void)interstitialDidLoadAdIsPrecache:(BOOL)precache;
/**
 Method called if interstitial mediation failed
 */
- (void)interstitialDidFailToLoadAd;
/**
 Method called if loaded interstital ad expired by timeout
 */
- (void)interstitialDidExpired;
/**
 Method called if interstitial mediation was successful, but ready ad network can't show ad or
 ad presentation was too frequent according to your placement settings
 */
- (void)interstitialDidFailToPresent;
/**
 Method called when interstitial displays on screen
 */
- (void)interstitialWillPresent;
/**
 Method called after interstitial leaves the screen
 */
- (void)interstitialDidDismiss;
/**
 Method called when user taps on interstitial
 */
- (void)interstitialDidClick;
@end
/**
 Rewarded video delegate declaration
 */
@protocol AppodealRewardedVideoDelegate <NSObject>
@optional
/**
 Method called when rewarded video loads
 @param precache If precache is YES it means that precached ad loaded
 */
- (void)rewardedVideoDidLoadAdIsPrecache:(BOOL)precache;
/**
 Method called if rewarded video mediation failed
 */
- (void)rewardedVideoDidFailToLoadAd;
/**
 Method called if loaded ad creative expired by timeout
 */
- (void)rewardedVideoDidExpired;
/**
 Method called if interstitial mediation was successful, but ready ad network can't show ad or
 ad presentation was too frequent according to your placement settings
 @param error Error object that indicates error reason
 */
- (void)rewardedVideoDidFailToPresentWithError:(nonnull NSError *)error;
/**
 Method called after rewarded video starts displaying
 */
- (void)rewardedVideoDidPresent;
/**
 Method called before rewarded video leaves screen
 @param wasFullyWatched boolean flag indicated that user watch video fully
 */
- (void)rewardedVideoWillDismissAndWasFullyWatched:(BOOL)wasFullyWatched;
/**
 Method called after completion of video
 @warning After calling this method, rewarded video can stay on screen and show postbanner
 *
 @param rewardAmount Amount of app currency turned on in Appodeal Dashboard
 @param rewardName Name of app currency set on in Appodeal Dashboard
 */
- (void)rewardedVideoDidFinish:(float)rewardAmount name:(nullable NSString *)rewardName;
/**
 Method called when user taps on rewarded video
 */
- (void)rewardedVideoDidClick;
@end
/**
 Non-skippable video delegate
 */
@protocol AppodealNonSkippableVideoDelegate <NSObject>
@optional
/**
 Method called when non skippable video loads
 @param precache If precache is YES it means that precached ad loaded
 */
- (void)nonSkippableVideoDidLoadAdIsPrecache:(BOOL)precache;
/**
 Mehtod called if non-skippable video mediation failed
 */
- (void)nonSkippableVideoDidFailToLoadAd;
/**
 Method called if non-skippable video did load but expired by timeout
 */
- (void)nonSkippableVideoDidExpired;
/**
 Method called after non-skippable video starts displaying
 */
- (void)nonSkippableVideoDidPresent;
/**
 Method called if non-skippable mediation was successful, but ready ad network can't show ad or
 ad presentation was too frequent according to your placement settings
 @param error Error object that indicates error reason
 */
- (void)nonSkippableVideoDidFailToPresentWithError:(nonnull NSError *)error;
/**
 Method called before rewarded video leaves screen
 @param wasFullyWatched boolean flag indicated that user watch video fully
 */
- (void)nonSkippableVideoWillDismissAndWasFullyWatched:(BOOL)wasFullyWatched;
/**
 Method called after completion of video
 @warning After calling this method, non-skippable video can stay on screen and show postbanner
 *
 */
- (void)nonSkippableVideoDidFinish;
/**
 Method called when user taps on non skippable video
 */
- (void)nonSkippableVideoDidClick;
@end
/**
 Delegate of native ads
 */
@protocol AppodealNativeAdDelegate <NSObject>
/**
 Method called after native ads load
 */
- (void)didLoadNativeAds:(NSInteger)count;
/**
 Method called if native ads get some error while loading
 */
- (void)didFailToLoadNativeAdsWithError:(nonnull NSError *)error;
@end
/**
 Extra Keys defines
 */
FOUNDATION_EXPORT NSString * _Nonnull const kAPDAppsFlyerIdExtrasKey;
/**
 Network defines
 */
FOUNDATION_EXPORT NSString * _Nonnull const kAPDMRAIDJSTagNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDTapsenseNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDInnerActiveNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDSmaatoNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDAppNexusNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDOpenXNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDVungleNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDUnityNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDAdColonyNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDAmazonNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDAppLovinNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDAvocarrotNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDChartboostNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDFacebookNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDAdMobNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDMyTargetNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDMoPubNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDPubnativeNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDStartAppNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDYandexNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDMillenialNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDTapjoyNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDZplayNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDInMobiNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDIronSourceNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDAppnextNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDCheetahNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDRevMobNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDMintegralNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDIVengoNetworkName;
FOUNDATION_EXPORT NSString * _Nonnull const kAPDOguryNetworkName;
/**
 Size defines
 */
extern const CGSize kAPDAdSize320x50;
extern const CGSize kAPDAdSize728x90;
extern const CGSize kAPDAdSize300x250;
/**
 Used in native ad image
 Equals to CGSizeZero
 */
extern const CGSize kAPDImageSizeUndefined;
/**
 Size validation
 @param size kAPDAdSize320x50, kAPDAdSize728x90, kAPDAdSize300x250
 @return BOOL
 */
extern BOOL APDIsAdSizeValid(const CGSize size);
/**
 Get nearest valid Appodeal size
 @param size CGSize
 @return kAPDAdSize320x50, kAPDAdSize728x90, kAPDAdSize300x250
 */
extern CGSize APDNearestValidAdSizeForCGSize(const CGSize size);
/**
 Get current SDK version
 @return current SDK version
 */
NSString  *_Nonnull  APDSdkVersionString(void);
extern NSString *_Nonnull const kAPDErrorDomain;
/**
 Appodeal SDK error codes
 - APDErrorCodeUnknown: Any unknown error
 - APDErrorCodeMediationFailed: Indicates that mediation was failed in no fill or other cases
 - APDErrorCodeNoConnection: Inicates that device hasn't connection on some sdk action attempt
 - APDErrorCodePresentationFailed: Indicates that sdk can't show ad in current state
 - APDErrorCodeInitialisationFailed: Indicates that some error occured while sdk trying to initialise
 - APDErrorCodeDenied: Indicates that sdk deny some action
 */
typedef NS_ENUM(NSInteger, APDErrorCode) {
    APDErrorCodeUnknown = 195944097,
    APDErrorCodeMediationFailed,
    APDErrorCodeNoConnection,
    APDErrorCodePresentationFailed,
    APDErrorCodeInitialisationFailed,
    APDErrorCodeDenied
};

/**
 Log flags

 - APDLogFlagError: Only error messages are written to console. If you see this message, you must check your integration
 - APDLogFlagWarning: Warning and error messages are written to console. Different warnings occur while the SDK works
 - APDLogFlagInfo: Error, warning and information messages are written to console.
 - APDLogFlagDebug: Debug messages written to console
 - APDlogFlagVerbose:
 */
typedef NS_OPTIONS(NSUInteger, APDLogFlag) {
    APDLogFlagError   = 1 << 0,
    APDLogFlagWarning = 1 << 1,
    APDLogFlagInfo    = 1 << 2,
    APDLogFlagDebug   = 1 << 3,
    APDlogFlagVerbose = 1 << 4
};
/**
 Log levels. Set some value to [APDSdk setLogLevel:]

 - APDLogLevelOff: Disable all logs
 - APDLogLevelError: Only error messages are written to console. If you see this message, you must check your integration
 - APDLogLevelWarning: Warning and error messages are written to console. Different warnings occur while the SDK works
 - APDLogLevelInfo: Error, warning and information messages are written to console.
 - APDLogLevelDebug: Debug messages written to console
 - APDLogLevelVerbose:  All SDK messages written to console. It includes third party ad network sdk logs
 */
typedef NS_ENUM(NSUInteger, APDLogLevel) {
    APDLogLevelOff     = 0,
    APDLogLevelError   = APDLogFlagError,
    APDLogLevelWarning = APDLogLevelError   | APDLogFlagWarning,
    APDLogLevelInfo    = APDLogLevelWarning | APDLogFlagInfo,
    APDLogLevelDebug   = APDLogLevelInfo    | APDLogFlagDebug,
    APDLogLevelVerbose = APDLogLevelDebug   | APDlogFlagVerbose
};
/**
 Native ad types

 - APDNativeAdTypeAuto: Native ad loaded can contain video. It depends on filled ad’s network
 - APDNativeAdTypeVideo: Native ad contains video
 - APDNativeAdTypeNoVideo: Native ad does not contain video
 */
typedef NS_ENUM(NSUInteger, APDNativeAdType) {
    APDNativeAdTypeAuto = 0,
    APDNativeAdTypeVideo,
    APDNativeAdTypeNoVideo
};

/**
 User gender. type alias AppodealUserGender
 
 - APDUserGenderOther: User not define gender
 - APDUserGenderFemale: Female
 - APDUserGenderMale: Male
 */
typedef NS_ENUM(NSUInteger, APDUserGender) {
    APDUserGenderOther = AppodealUserGenderOther,
    APDUserGenderFemale = AppodealUserGenderFemale,
    APDUserGenderMale = AppodealUserGenderMale
};
/**
 Framework constants

 - APDFrameworkNative: Native platform
 - APDFrameworkUnity: Unity
 - APDFrameworkCocos2d: Cocos2d
 - APDFrameworkMarmalade: Marmalade
 - APDFrameworkPhoneGap: Phone Gap
 - APDFrameworkGiderosMobile: Gideros
 - APDFrameworkAdobeAir: Adobe Air
 - APDFrameworkCordova: Cordova
 - APDFrameworkXamarin: Xamarin
 - APDFrameworkGameMaker: Game Maker
 - APDFrameworkMonkeyX: MonkeyX
 - APDFrameworkSC2: SC 2
 - APDFrameworkLibGDX: LibGDX
 - APDFrameworkQt: QT
 - APDFrameworkUE4: Unreal Engine 4
 - APDFrameworkReactNative: React Native
 - APDFrameworkCorona: Corona
 - APDFrameworkStencyl: Stencyl
 - APDFrameworkSDKBox: SDK Box
 - APDFrameworkDefold: Defold
 - APDFrameworkBuildBox: Build Box
 */
typedef NS_ENUM(NSUInteger, APDFramework) {
    APDFrameworkNative = 1,
    APDFrameworkUnity,
    APDFrameworkCocos2d,
    APDFrameworkMarmalade,
    APDFrameworkPhoneGap,
    APDFrameworkGiderosMobile,
    APDFrameworkAdobeAir,
    APDFrameworkCordova,
    APDFrameworkXamarin,
    APDFrameworkGameMaker,
    APDFrameworkMonkeyX,
    APDFrameworkSC2,
    APDFrameworkLibGDX,
    APDFrameworkQt,
    APDFrameworkUE4,
    APDFrameworkReactNative,
    APDFrameworkCorona,
    APDFrameworkStencyl,
    APDFrameworkSDKBox,
    APDFrameworkDefold,
    APDFrameworkBuildBox
};


