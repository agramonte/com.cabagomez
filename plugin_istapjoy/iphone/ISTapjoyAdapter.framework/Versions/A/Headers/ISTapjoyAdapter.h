//
//  ISTapjoyAdapter.h
//  ISTapjoyAdapter
//
//  Created by Daniil Bystrov on 4/13/16.
//  Copyright © 2016 IronSource. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IronSource/ISBaseAdapter+Internal.h"

static NSString * const TapjoyAdapterVersion = @"4.1.14";
static NSString * GitHash = @"28519dd8b";

//System Frameworks For Tapjoy Adapter

@import AdSupport;
@import CoreData;
@import CFNetwork;
@import CoreGraphics;
@import CoreLocation;
@import CoreMotion;
@import CoreTelephony;
@import Foundation;
@import ImageIO;
@import MapKit;
@import MediaPlayer;
@import MobileCoreServices;
@import QuartzCore;
@import Security;
@import StoreKit;
@import SystemConfiguration;
@import UIKit;
@import WebKit;

@interface ISTapjoyAdapter : ISBaseAdapter

@end
