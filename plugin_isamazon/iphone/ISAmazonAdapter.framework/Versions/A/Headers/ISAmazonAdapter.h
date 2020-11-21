//
//  ISAmazonAdapter.h
//  ISAmazonAdapter
//
//  Created by Guy Lis on 25/03/2019.
//

#import <Foundation/Foundation.h>
#import "IronSource/ISBaseAdapter+Internal.h"

static NSString * const AmazonAdapterVersion = @"4.3.4";
static NSString * GitHash = @"cb32404f2";

//System Frameworks For Amazon Adapter

@import AdSupport;
@import CoreLocation;
@import CoreTelephony;
@import EventKit;
@import EventKitUI;
@import JavaScriptCore;
@import MediaPlayer;
@import SafariServices;
@import QuartzCore;
@import StoreKit;
@import SystemConfiguration;

@interface ISAmazonAdapter : ISBaseAdapter

@end
