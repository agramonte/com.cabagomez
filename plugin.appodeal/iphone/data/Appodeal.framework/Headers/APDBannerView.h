//
//  APDBannerView.h
//
//  AppodealSDK version 2.7.4
//
//  Copyright © 2020 Appodeal, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Appodeal/APDSdk.h>


@class APDBannerView;

/**
 Declaration of banner view delegate
 */
@protocol APDBannerViewDelegate <NSObject>

@optional
/**
 Method called after any banner was ready to present.
 Maybe called twice for precache banner and usual banner
 @param bannerView Nonnul, ready to show banner
 @param precache Boolean flag indicates that banner is precache
 */
- (void)bannerViewDidLoadAd:(nonnull APDBannerView *)bannerView isPrecache:(BOOL)precache;
/**
 Method called in case that banner mediation failed
 @param bannerView Nonnul failed banner view
 @param error Error occured while mediation
 */
- (void)bannerView:(nonnull APDBannerView *)bannerView didFailToLoadAdWithError:(nonnull NSError *)error;
/**
 Call when user taps on banner
 @param bannerView inteacted banner view
 */
- (void)bannerViewDidInteract:(nonnull APDBannerView *)bannerView;
/**
 Method called after any banner was show
 @param bannerView On screen banner view
 */
- (void)bannerViewDidShow:(nonnull APDBannerView *)bannerView;
/**
 Called in case if banner view was successfully loaded,
 but ad expire before show. Banner will retry to load
 new creative for presentation if autocache enabled
 @param bannerView Expired banner view
 */
- (void)bannerViewExpired:(nonnull APDBannerView *)bannerView;
@end
/**
 Banner view instance class
 */
@interface APDBannerView : UIView
/**
  Set banner view delegate
 */
@property (weak, nonatomic, nullable) IBOutlet id<APDBannerViewDelegate> delegate;
/**
 Set non-null root view controller before loading banner view
 */
@property (weak, nonatomic, nullable) IBOutlet UIViewController *rootViewController;
/**
 Set custom placement, turned on in Appodeal Dashboard
 */
@property (copy, nonatomic, nullable) IBInspectable NSString *placement;
/**
 If this flag is set to YES, banner view will auto-resize after screen rotation
 (It is possible to use the flag only if the application supports one orientation)
 Set to YES by default
 */
@property (assign, nonatomic) IBInspectable BOOL usesSmartSizing;
/**
 Set autocache
 */
@property (assign, nonatomic) IBInspectable BOOL autocache;
/**
 Set valid banner size. Valid values: kAPDAdSize320x50, kAPDAdSize728x90
 */
@property (assign, nonatomic) IBInspectable APDUnitSize adSize;
/**
 Set banner refresh animation
 */
@property (assign, nonatomic) IBInspectable UIViewAnimationOptions refreshAnimation;
/**
 Set banner background visibility
 */
@property (assign, nonatomic) BOOL backgroundVisible __deprecated_msg("This property is deprecated and will be removed in next release");
/**
 Get predicated ecpm
 */
@property (assign, nonatomic, readonly) double predictedEcpm;
/**
 Set custom SDK
 */
@property (weak, nonatomic, nullable) APDSdk *customSdk;
/**
 Get banner availability
 */
@property (assign, nonatomic, readonly, getter=isReady) BOOL ready;
/**
 Create instance banner
 @param adSize kAPDAdSize320x50, kAPDAdSize728x90
 @param rootViewController parent controller
 @param sdk custom sdk
 @param delegate delegate
 @param autocache autocache
 @return Instance of APDBannerView
 */
+ (instancetype _Nonnull)bannerViewWithSize:(CGSize)adSize
                         rootViewController:(nonnull UIViewController *)rootViewController
                                        sdk:(nullable APDSdk *)sdk
                                   delegate:(nullable id<APDBannerViewDelegate>)delegate
                                  autocache:(BOOL)autocache;
/**
 Initializer
 @param adSize kAPDAdSize320x50, kAPDAdSize728x90
 @return Instance of APDBannerView
 */
- (instancetype _Nonnull)initWithSize:(APDUnitSize)adSize;
/**
 Initializer
 @param adSize kAPDAdSize320x50, kAPDAdSize728x90
 @param rootViewController parent controller
 @return Instance of APDBannerView
 */
- (instancetype _Nonnull)initWithSize:(APDUnitSize)adSize
                   rootViewController:(nonnull UIViewController *)rootViewController;
/**
 Start loading
 */
- (void)loadAd;
/**
 Call this method when orientation changes

 @param orientation Current interface orientation
 */
- (void)rotateToOrientation:(UIInterfaceOrientation)orientation __attribute__((deprecated("This method is deprecated and will be removed in future release")));
@end
/**
 Compatibility alias for APDBannerView
 */
@compatibility_alias AppodealBannerView APDBannerView;
/**
 Compatibility alias for APDBannerViewDelegate
 */
@protocol AppodealBannerViewDelegate <APDBannerViewDelegate> @end

