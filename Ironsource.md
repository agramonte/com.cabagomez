# solar2d-Ironsource-Plugin
Ironsource Plugin for solar2d

1. Activate the plugin here: https://www.solar2dplugins.com. Follow the instructions for the build settings.

2. According to the ironsource documentation for iOS. Need to add the transport security exception to the build settings and also any attribution keys for iOS 14. The full list of keys currently avalable for ironsource can be found here: https://developers.ironsrc.com/ironsource-mobile/ios/ios-14-network-support/
```
plist = {
            NSAppTransportSecurity = { NSAllowsArbitraryLoads=true },
            SKAdNetworkItems = 
            {
                { SKAdNetworkIdentifier = "SU67R6K2V3.skadnetwork" },
                { SKAdNetworkIdentifier = "cstr6suwn9.skadnetwork" }
            },
}
```
4. Add any adapters if needed. Again from https://www.solar2dplugins.com.

5. Plugin supports Android 16 and above. Add to your build settings file:
```
minSdkVersion = "16",
```
6. Refrence the plugin:
```
local ironsource = require("plugin.ironsource")
```

7. Init. 
```
ironsource.init(
    adListerner, -- Listerner. Required.
        {
            key=<replace with your key>, -- Your ironsource app key. Required.
            showDebugLog=false, -- Optional debug param. Defaults to false. Show extended logs.
            showValidateIntegrationUI=false, -- Optional. Shows integration validation UI. Defaults to false.
            userId="xsdsfsd", -- Optional. UserId. If not provided ironsource will autogenerate one.
            hasUserConsent=false, -- Optional. Targeted ads. Defaults to false.
            ccpaDoNotSell=false, -- Optional. False = Sell the data. True = do not sell. Default is false.
            isAutoLoad = true -- Optional. True = Banner and Interstitial will autoload. Default is true. (beta only).
        } -- Table with options.
    )
```

8. Show.
```
    ironsource.show("<adtype>", -- Ad type. Valid values are: "interstitial", "rewardedVideo", "banner", "offerWall"
        {
            y=<bannerPosition>, -- Optional. Valid for banner. Valid values are "top" and "bottom". Defaults to "bottom".
            placementName=<placement name> -- Optional. Valid for "rewardedVideo", "offerwall", "interstitial". (beta only).
        } -- Optional table.
    )
```

9. Is Available.
```
    ironsource.isAvailable("<adtype>",
        {
            placementName=<placement name> -- Optional. Valid for "rewardedVideo", "interstitial". (beta only).
        } -- Optional table.
    
    ) -- Ad type. Valid values are: "interstitial", "rewardedVideo", "offerWall"
    -- "banner" also available in beta android.
```  
10. Hide.
```
    ironsource.hide() -- Only functions for banner.
```

11. Load.
```
   ironsource.load( "<adType>" ) -- Ad type. Valid values are: "interstitial", "banner".
   -- Ironsource autoloads rewarded ads and the offerwall.
```

12. Logs example:

loaded ("interstitial", "banner")
```
ironsource:	{
    "data":"",
    "name":"ironsource",
    "phase":"loaded",
    "provider":"ironsource",
    "response":"", -- If error. The error reason would be here.
    "type":"<adType>",
    "isError":false -- Always true for show and offerwalls.
}
```

show ("offerwall"-on error, "rewardedVideo"-on error, "interstitial")
```
ironsource:	{
    "data":"",
    "name":"ironsource",
    "phase":"show",
    "provider":"ironsource",
    "response":"", -- If error. The error reason would be here. Always populated for rewarded and offerwall.
    "type":"<adType>",
    "isError":false -- Always true for rewarded and offerwall.
}
```

available ("rewardedVideo", "offerWall")
```
ironsource:	{
    "data":"",
    "name":"ironsource",
    "phase":"available",
    "provider":"ironsource",
    "response":"<isAvailable>", -- true it is currently available and loaded. If the ad expires you will get a similar event but false.
    "type":"<adType>",
    "isError":false -- Would be true if it couldn't load.
}
```

reward ( "offerWall", "rewardedVideo )
```
ironsource:	{
    "data":"",
    "name":"ironsource",
    "phase":"reward",
    "provider":"ironsource",
    "response":"<>", -- error string if isError = true or awarded credit as string. Only populated for offerwall.
    "type":"<adtype>",
    "isError":false -- No error available for rewardedVideo.
}
```

opened      ("rewardedVideo", "interstitial", "offerWall")

closed      ("rewardedVideo", "interstitial", "offerWall")

started     ("rewardedVideo" ) 

ended       ("rewardedVideo" )

presented   ("banner")

dismissed   ("banner")

adLeftApp   ("banner")

```
ironsource:	{
    "data":"",
    "name":"ironsource",
    "phase":"opened",
    "provider":"ironsource",
    "response":"", -- Never filled for these phases.
    "type":"rewardedVideo", 
    "isError":false -- Always false for these phases.
}
```


clicked ("rewardedVideo", "interstitial", "banner")
```
ironsource:	{
    "data":"",
    "name":"ironsource",
    "phase":"clicked",
    "provider":"ironsource",
    "response":"<placementname>", -- Placement name. Rewarded only.
    "type":"<adType>",
    "isError":false
}
```
 

