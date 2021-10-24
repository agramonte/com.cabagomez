# solar2d-HyperBid-Plugin
HyperBid Plugin for solar2d (Beta)

Please note:   
1. HyperBid is GameAnalytics new ad mediation platform.   
2. This plugin is not the official HyperBid plugin. I imagine that at somepoint they'll release a solar2d version since they have supported solar2d for a very long time.   
3. The iOS plugin crashes on devices running anything under iOS 10.   

Integration steps:   
1. Register for Hyperbid https://app.hyperbid.com.   

2. For iOS add plist:   
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
3. Plugin supports Android 16 and above. Add to your build settings file:
```
minSdkVersion = "16",
```   
4. Refrence the plugin:
```
local hyperbid = require( "plugin.hyperbid" )
```   
5. Init. 
```
hyperbid.init(
    adListerner, -- Listerner. Required.
        {
            hyperBidAppID = <appId>, -- Replace with your appId.
            hyperBidAppKey = <appKey>, -- Replace with your key.
            showDebugLog=false, -- Optional debug param. Defaults to false. Show extended logs.
            coppaUnderAge=false, -- Optional. Defaults to false.
            gdprUnderAge=false, -- Optional. Defaults to false.
            userId="xsdsfsd", -- Optional. UserId. If not provided hyperbid will autogenerate one.
            hasUserConsent=false, -- Optional. Targeted ads. Defaults to false.
            ccpaDoNotSell=false, -- Optional. False = Sell the data. True = do not sell. Default is false.
            channel = <anything> -- Optional. String value to use as a segment.
        } -- Table with options.
    )
```   
6. Show.
```
    hyperbid.show("<adtype>", -- Ad type. Valid values are: "interstitial", "rewardedVideo", "banner"
        {
            y=<bannerPosition>, -- Optional. Valid for banner. Valid values are "top" and "bottom". Defaults to "bottom".
            placementId=<placementId> -- Required.
        } -- Optional table.
    )
```

7. Is Available.
```
    hyperbid.isAvailable("<adtype>") -- Ad type. Valid values are: "interstitial", "banner", "rewardedVideo".
```  
8. Hide.
```
    hyperbid.hide() -- Only functions for banner.
```

9. Load.
```
   hyperbid.load( "<adType>", -- Ad type. Valid values are: "interstitial", "banner", "rewardedVideo".
        {
            placementId=<placement id> -- Required.
        } 
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

iOS mediation networks:   
    HyperBidBanner:5.7.53    	
    AdColony:4.3.9   
    AppLovinSDK:4.3.27   
    Chartboost:4.3.8   
    UnityAds:3.7.5   
    TapJoy:12.8.1 -- No placement work but the startup placement works.   
    VungleSDK:6.10.3   
    IronSource:5.94 -- Can't get it to show any ads.   
    GoogleMobileAds:4.3.27   
    FBAudienceNetwork:4.3.29    

Android mediation networks:   
    com.hyperbid.sdk:core:5.7.53   
    com.facebook.android:audience-network-sdk:6.7.0     
    com.google.android.gms:play-services-ads:20.4.0    
    com.unity3d.ads:unity-ads:3.7.5    
    com.chartboost:chartboost-sdk:8.2.1   
    com.chartboost:helium:2.2.1  
    com.tapjoy:tapjoy-android-sdk:12.8.1
    com.adcolony:sdk:4.6.4
    com.vungle:publisher-sdk-android:6.10.2
    com.applovin:applovin-sdk:10.3.4


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
