//
//  AMALoggingHelper.h
//  AmazonMobileAdsSDK
//
//  Created by Krivopaltsev, Eugene on 5/24/18.
//

#import <Foundation/Foundation.h>

/**
 * Log Flags
 */
typedef NS_OPTIONS(NSUInteger, AMALogFlag)
{
    AMALogFlagFatal     = (1 << 0),
    AMALogFlagError     = (1 << 1),
    AMALogFlagWarning   = (1 << 2),
    AMALogFlagInfo      = (1 << 3),
    AMALogFlagDebug     = (1 << 4)
};

/**
 * Application implements this protocol if further manipulations besides NSLog are required
 *
 */
@protocol AMALogDelegate
/**
 * delegate is call with a message originated from DTBLog
 */
-(void)onMessageLogged:(NSString * _Nonnull) message;

@end

/**
 * Log Levels
 */
typedef NS_ENUM(NSUInteger, AMALogLevel)
{
    // No Logs
    AMALogLevelOff      = 0,
    
    // Fatal logs only
    AMALogLevelFatal    = (AMALogFlagFatal),
    
    // Fatal & Error logs
    AMALogLevelError    = (AMALogLevelFatal | AMALogFlagError),
    
    // Fatal, Error & Warning logs
    AMALogLevelWarning  = (AMALogLevelError | AMALogFlagWarning),
    
    // Fatal, Error, Warning & Info logs
    AMALogLevelInfo     = (AMALogLevelWarning | AMALogFlagInfo),
    
    // Fatal, Error, Warning, Info & Debug logs
    AMALogLevelDebug    = (AMALogLevelInfo | AMALogFlagDebug),
    
    // Logs all levels
    AMALogLevelAll      = NSUIntegerMax
};


@interface AMALoggingHelper : NSObject

+ (void) setLogLevel:(AMALogLevel) logLevel;

+ (void) setLogDelegate:(id<AMALogDelegate> _Nullable)delegate;
@end
