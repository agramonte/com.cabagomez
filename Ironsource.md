# solar2d-Ironsource-Plugin
Ironsource Plugin for solar2d


1. The full list of keys currently avalable for ironsource can be found here: https://developers.ironsrc.com/ironsource-mobile/ios/ios-14-network-support/
```
plist = {
            NSAppTransportSecurity = { NSAllowsArbitraryLoads=true },
            SKAdNetworkItems = 
            {
                { SKAdNetworkIdentifier = "xxxx-lowercasealphanumeric-xxxx.skadnetwork" },
                { SKAdNetworkIdentifier = "xxxx-lowercasealphanumeric-xxxx.skadnetwork" }
            },
}
```   
They have to be in lower case and my current list can be found here:   
https://gist.github.com/agramonte/f972018e94ea152d8e2db531e8a307f5   

2. Add any adapters.

3. Plugin supports Android 16 and above. Add to your build settings file:
```
minSdkVersion = "16",
```
4. Refrence the plugin:
```
local ironsource = require("plugin.ironsource")
```

5. Init. 
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

6. Show.
```
    ironsource.show("<adtype>", -- Ad type. Valid values are: "interstitial", "rewardedVideo", "banner", "offerWall"
        {
            y=<bannerPosition>, -- Optional. Valid for banner. Valid values are "top" and "bottom". Defaults to "bottom".
            placementName=<placement name> -- Optional. Valid for "rewardedVideo", "offerwall", "interstitial". (beta only).
        } -- Optional table.
    )
```

7. Is Available.
```
    ironsource.isAvailable("<adtype>",
        {
            placementName=<placement name> -- Optional. Valid for "rewardedVideo", "interstitial". (beta only).
        } -- Optional table.
    
    ) -- Ad type. Valid values are: "interstitial", "rewardedVideo", "offerWall"
    -- "banner" also available in beta android.
```  
8. Hide.
```
    ironsource.hide() -- Only functions for banner.
```

9. Load.
```
   ironsource.load( "<adType>" ) -- Ad type. Valid values are: "interstitial", "banner".
   -- Ironsource autoloads rewarded ads and the offerwall.
```

10. Set custom properties.   
```
ironsource.setCustomProperty(
    "<keyName>", 
    "<keyValue>"
)
```   

11. Logs example:

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

segmentReceived -- Segment being used by this particular user     
```
ironsource:	{
      "data":"",
      "name":"ironsource",
      "phase":"segmentReceived",
      "provider":"ironsource",
      "response":"<segmentName>",
      "type":"segment",
      "isError":false
    }   
```   

Current versions iOS:   
--------------- AdColony --------------   
SDK - Version 4.6.0.0   
Adapter - Version 4.3.9   
--------------- AdMob --------------   
SDK - Version afma-sdk-i-v8.4.0   
Adapter - Version 4.3.21   
--------------- Amazon --------------   
SDK - Version amznAdSDK-ios-3.1.0   
Adapter - Version 4.3.5   
--------------- AppLovin --------------   
SDK - Version 10.1.1   
Adapter - Version 4.3.24   
--------------- Chartboost --------------   
SDK - Version 8.4.1   
Adapter - Version 4.3.6   
--------------- Facebook --------------   
SDK - Version 6.4.1   
Adapter - Version 4.3.25   
--------------- InMobi --------------   
SDK - Version 9.1.5   
Adapter - Version 4.3.9   
--------------- IronSource --------------   
SDK - Version 5.88   
Adapter - Version 7.1.5   
--------------- Smaato --------------   
SDK - Version 21.6.11   
Adapter - Version 4.3.1   
--------------- Tapjoy --------------   
SDK - Version 12.8.0   
Adapter - Version 4.1.16   
--------------- UnityAds --------------   
SDK - Version 3.7.1   
Adapter - Version 4.3.9   
--------------- Vungle --------------   
SDK - Version 6.9.2   
Adapter - Version 4.3.10   
 

Current versions Android:   
--------------- AdColony --------------   
Adapter 4.3.8   
--------------- AdMob --------------   
Adapter 4.3.17   
--------------- Amazon --------------   
Adapter 4.3.3   
SDK Version - amznAdSDK-android-6.0.0   
--------------- AppLovin --------------   
Adapter 4.3.24   
SDK Version - 10.1.2   
--------------- Chartboost --------------   
Adapter 4.3.5   
SDK Version - 8.2.0   
--------------- Facebook --------------   
Adapter 4.3.26   
SDK Version - 6.4.0   
--------------- InMobi --------------   
Adapter 4.3.9   
SDK Version - 9.1.6   
--------------- IronSource  --------------   
Adapter 7.1.5.1   
SDK Version - 5.99   
--------------- Pangle --------------   
Adapter 4.3.1   
SDK Version - 3.4.1.1   
--------------- Smaato --------------   
Adapter 4.3.1   
SDK Version - 21.5.7   
--------------- Tapjoy --------------   
Adapter 4.1.16   
SDK Version - 12.8.0   
--------------- UnityAds --------------   
Adapter 4.3.10   
SDK Version - 3.6.0   
--------------- Vungle --------------   
Adapter 4.3.8   
SDK Version - 6.9.1   



THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
