//
//  APDRewardProtocol.h
//  Appodeal
//
//  AppodealSDK version 2.7.4
//
//  Copyright © 2020 Appodeal, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 Declaration of Appodeal reward protocol object
 */
@protocol APDReward <NSObject>
/**
 App currency name. For example @"Coins", @"Stars"
 */
@property (copy, nonatomic, readonly, nullable) NSString *currencyName;
/**
 App currency amount
 */
@property (assign, nonatomic, readonly) float amount;

@end
