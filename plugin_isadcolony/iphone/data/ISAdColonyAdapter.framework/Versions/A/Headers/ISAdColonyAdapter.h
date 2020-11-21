//
//  Copyright (c) 2015 IronSource. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IronSource/ISBaseAdapter+Internal.h"

static NSString * const AdColonyAdapterVersion = @"4.3.4";
static NSString * GitHash = @"35405aec2";

//System Frameworks For AdColony Adapter

@import AdSupport;
@import AudioToolbox;
@import AVFoundation;
@import CoreMedia;
@import CoreTelephony;
@import JavaScriptCore;
@import MessageUI;
@import CoreServices;
@import SafariServices;
@import Social;
@import StoreKit;
@import SystemConfiguration;
@import WatchConnectivity;
@import WebKit;

@interface ISAdColonyAdapter : ISBaseAdapter

@end
