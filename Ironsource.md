# solar2d-Ironsource-Plugin
Ironsource Plugin for solar2d


1. The full list of keys currently avalable for ironsource can be found here: https://developers.ironsrc.com/ironsource-mobile/ios/ios-14-network-support/
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

10. Logs example:

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

Current versions iOS:   
--------------- AdColony --------------   
SDK - Version 4.4.0.0   
Adapter - Version 4.3.5	   
--------------- AdMob --------------   		
SDK - Version afma-sdk-i-v7.69.0   	
Adapter - Version 4.3.18   	
--------------- Amazon --------------   		
SDK - Version amznAdSDK-ios-3.1.0   	
Adapter - Version 4.3.4	   
--------------- AppLovin --------------	   	
SDK - Version 6.14.6	   
Adapter - Version 4.3.20	   
--------------- Chartboost --------------	   	
SDK - Version 8.3.1	   
Adapter - Version 4.3.4	   
--------------- IronSource --------------	   	
SDK - Version 5.82	   
Adapter - Version 7.0.4	   
--------------- Tapjoy --------------	   	
SDK - Version 12.7.1	   
Adapter - Version 4.1.15   	
--------------- UnityAds --------------		   
SDK - Version 3.5.1	   
Adapter - Version 4.3.6	   
--------------- Vungle --------------	   	
SDK - Version 6.8.1	   
Adapter - Version 4.3.8	   



Current versions Android:
 --------------- AdColony --------------   
 Adapter 4.3.4   
 --------------- AdMob --------------   
 Adapter 4.3.15   
 --------------- Amazon --------------   
 Adapter 4.3.2    
 SDK Version - amznAdSDK-android-5.9.0   
 --------------- AppLovin --------------   
 Adapter 4.3.20    
 SDK Version - 9.14.6   
 --------------- Chartboost --------------   
 Adapter 4.3.4    
 SDK Version - 8.1.0   
--------------- Facebook --------------   
Adapter 4.3.23   
SDK Version - 6.2.0   
--------------- IronSource  --------------   
 Adapter 7.0.3.1    
 SDK Version - 5.89   
 --------------- Tapjoy --------------   
 Adapter 4.1.15    
 SDK Version - 12.7.1   
 --------------- UnityAds --------------   
 Adapter 4.3.8    
 SDK Version - 3.5.1   
 --------------- Vungle --------------   
 Adapter 4.3.7    
 SDK Version - 6.8.1   
 
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
