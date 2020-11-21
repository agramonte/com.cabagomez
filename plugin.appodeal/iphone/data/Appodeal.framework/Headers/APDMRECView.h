//
//  APDMRECView.h
//  Appodeal
//
//  AppodealSDK 2.7.4
//
//  Copyright © 2020 Appodeal, Inc. All rights reserved.
//

#import <Appodeal/APDBannerView.h>

/**
 Instance of this class returns rectangular banner of size 300x250
 All methods/properties besides initializer similar to APDBannerView
 */
@interface APDMRECView : APDBannerView
/**
 Use -init method to create instance APDMRECView
 @return Instance of APDMRECView
 */
- (instancetype)init;

@end
/**
 Compatibility alias APDMRECView
 */
@compatibility_alias AppodealMRECView APDMRECView;
