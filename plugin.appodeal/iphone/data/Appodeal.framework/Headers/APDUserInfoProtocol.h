//
//  APDUserInfoProtocol.h
//  Appodeal
//
//  AppodealSDK version 2.7.4
//
//  Copyright © 2020 Appodeal, Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <Appodeal/APDDefines.h>

@protocol APDUserInfo <NSObject>
/**
 Age
 */
@property (assign, nonatomic, readonly) NSUInteger age;
/**
 Gender
 */
@property (assign, nonatomic, readonly) APDUserGender gender;
/**
 UserId
 */
@property (copy, nonatomic, readonly, nullable) NSString *userId;
/**
 Ext
 */
@property (copy, nonatomic, readonly, nullable) NSDictionary *ext;


@end
