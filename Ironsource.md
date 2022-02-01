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
            coppaUnderAge=false, -- Optional. Defaults to false.
            gdprUnderAge=false, -- Optional. Defaults to false.
            showValidateIntegrationUI=false, -- Optional. Shows integration validation UI. Defaults to false.
            userId="xsdsfsd", -- Optional. UserId. If not provided ironsource will autogenerate one.
            hasUserConsent=false, -- Optional. Targeted ads. Defaults to false.
            ccpaDoNotSell=false, -- Optional. False = Sell the data. True = do not sell. Default is false.
            isAutoLoad = true, -- Optional. True = Banner and Interstitial will autoload. Default is true.
            consentView = false -- Optional. True = send consent view events. iOS only. Default is false.
        } -- Table with options.
    )
```

Setting coppaUnder age to true will result in the following changes:   
    "AdMob_TFCD" value:true  
    "AppLovin_AgeRestrictedUser" value:true  
    "AdColony_COPPA" value:true   
    "Pangle_COPPA" value:true   
    "is_child_directed" value:true  

Setting gdprUnderAge age to true will result in the following changes:
    "AdMob_TFUA" value:true   
    "AppLovin_AgeRestrictedUser" value:true   
    "is_child_directed" value:true  

6. Show.
```
    ironsource.show("<adtype>", -- Ad type. Valid values are: "interstitial", "rewardedVideo", "banner", "offerWall","consentView"
        {
            y=<bannerPosition>, -- Optional. Valid for banner. Valid values are "top" and "bottom". Defaults to "bottom".
            placementName=<placement name> -- Optional. Valid for "rewardedVideo", "offerwall", "interstitial".
        } -- Optional table.
    )
```

7. Is Available.
```
    ironsource.isAvailable("<adtype>",
        {
            placementName=<placement name> -- Optional. Valid for "rewardedVideo", "interstitial", "banner".
        } -- Optional table.
    
    )
```  
8. Hide.
```
    ironsource.hide() -- Only functions for banner.
```

9. Load.
```
   ironsource.load( "<adType>" ) -- Ad type. Valid values are: "interstitial", "banner", "consentView"ß.
   -- Ironsource autoloads rewarded ads and the offerwall.
```

10. Set custom properties.   
```
ironsource.setCustomProperty(
    "<keyName>", 
    "<keyValue>"
)
```  
11. If using:   
AdColony add these schemes (iOS only):   
```
    LSApplicationQueriesSchemes = 
    {   
            "fb",
            "instagram",
            "tumblr",
            "twitter"
    }
```    
12. If using Facebook. Facebook requires this call before initializing Ironsource (iOS only). In the build settings add the plugin:   
```
["plugin_isfacebook"] = 
{
  publisherId = "com.cabagomez"
},
```   
Then after recieving the value from ATT:   
```
    local isfacebook = require("plugin.isfacebook")
    isfacebook.setPrivacy( {
        advertiserTrackingEnabled = <true or false>, -- Result of the ATT privacy question.
        ccpaDoNotSell = <true or false> -- CCPA do not sell question.
        }
    )

```   
13. Logs example:

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
Adapter VERIFIED
SDK - Version 4.6.1.0    
Adapter - Version 4.3.9    
--------------- Google (AdMob and Ad Manager) --------------    
SDK - Version afma-sdk-i-v8.9.0    
Adapter - Version 4.3.27    
--------------- InMobi --------------    
Adapter VERIFIED
SDK - Version 10.0.1    
Adapter - Version 4.3.13    
--------------- IronSource --------------    
Adapter VERIFIED
SDK - Version 5.98    
Adapter - Version 7.1.14    
--------------- Meta --------------    
Adapter VERIFIED
SDK - Version 6.9.0    
Adapter - Version 4.3.33    
--------------- Tapjoy --------------    
Adapter VERIFIED
SDK - Version 12.8.1    
Adapter - Version 4.1.18    
--------------- UnityAds --------------    
Adapter VERIFIED
SDK - Version 4.0.0    
Adapter - Version 4.3.19    
--------------- Vungle --------------    
Adapter VERIFIED
SDK - Version 6.10.5    
Adapter - Version 4.3.16    


Current versions Android:   
--------------- AdColony --------------   
Adapter 4.3.10
--------------- AdMob --------------   
Adapter 4.3.23
--------------- AppLovin --------------   
Adapter 4.3.28  
SDK Version - 10.3.2   
--------------- Chartboost --------------   
Adapter 4.3.7   
SDK Version - 8.2.1   
--------------- Facebook --------------   
Adapter 4.3.34   
SDK Version - 6.8.0   
--------------- Inmobi --------------   
Adapter 4.3.13   
SDK Version - 10.0.1   
--------------- IronSource  --------------   
Adapter 7.1.13 
SDK Version - 5.109  
--------------- Pangle --------------   
Adapter 4.3.9  
SDK Version - 4.1.1.5  
--------------- Tapjoy --------------   
Adapter 4.1.19   
SDK Version - 12.8.1  
--------------- UnityAds --------------   
Adapter 4.3.14  
SDK Version - 3.7.5   
--------------- Vungle --------------   
Adapter 4.3.13
SDK Version - 6.10.3   
--------------- Yahoo --------------   
Adapter 4.3.0  



THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
