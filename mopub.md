# solar2d-Mopub-Plugin
Mupub Plugin for solar2d / Android & Amazon only.

1. Plugin supports Android 19 and above. Add to your build settings file:
```
minSdkVersion = "19",
```
2. Refrence the plugin:
```
local mopub = require("plugin.mopub")
```   
3. Add refrence to build settings:   
```   
["plugin_mopub"] = 
        {
            publisherId = "com.cabagomez",
            supportedPlatforms = { android = true, ["android-kindle"]=false } 
        },
```   
4. For "advance bidding networks" you have to init the network before initializing mobpub (all the pre-initialize network supported). You don't need to do it this if you are not doing advance bidding. 
```   
    mopub.initMediationNetwork("tapjoy", <tapjoyapikey> )
    mopub.initMediationNetwork("pangle", <appid>, <appname> )
    mopub.initMediationNetwork("adcolony", <appId>,<placementId1>,<placementId2>,<placementId3>,<placementId4>)
```   
5. Init.   
```   
mopub.init( 
    adProvider.adListener, { 
    interUnit = <mopubInterstialUnitId>, -- Required even if not serving interstitial. Used to init.
    bannerUnit = <mopubBannerUnitId>, -- Optional.
    rewardUnit = <mopubRewardUnitId>, -- Optional.
    hasUserConsent = false -- Optional. False = GDPR consent. Ignored outside of GDPR countries.
    ccpaDoNotSell = false -- Optional. False = Sell the data. True = do not sell. Default is false.
    coppaUnderAge = false -- Optional. False (default). Mark true if player is under 13.
    gdprUnderAge = false -- Optional. False (default). Mark true if player is under 16.
    showDebugLog = true,
    isAutoLoad = true  -- Optional. True = Banner and Interstitial will autoload. Default is true.
} )
```   
Setting either of the 2 underage options to true will result in:  
Adcolony's GDPR set to "0" and Adcolony COPPA to true.   
Tapjoy's setBelowConsentAge to true.   
Applovin's isAgeRestrictivedUser to true.   

Setting ccpa to true:   
Adcolony's CCPA to "0".     
Chartboost's CCPA to "OPT_OUT_SALE".    
Applovin's setDoNotSell to true.   

Setting hasUserConsent to false (GDPR users only):   
Chartboost's GDPR to "NON_BEHAVIORAL".   
Adcolony's GDPR set to "0".   
Aplovin's setHasUserConsent to false.   

6. Load (only for interstitial and rewarded).   
```
    mopub.load("<adtype>", -- Ad type. Valid values are: "interstitial", "rewardedVideo"
    )
```   
7. Show.   
```   
    mopub.show("<adtype>", -- Ad type. Valid values are: "interstitial", "rewardedVideo", "banner"
        {
            y=<bannerPosition>, -- Optional. Valid for banner. Valid values are "top" and "bottom". Defaults to "bottom".
        } -- Optional table.
    )
```   
8. Is Available.   
```   
    mopub.isAvailable("<adtype>",
    ) -- Ad type. Valid values are: "interstitial", "rewardedVideo", "banner"
```  
9. Hide.   
```   
    mopub.hide() -- Only functions for banner.
```   
10. Load.   
```   
   mopub.load( "<adType>" ) -- Ad type. Valid values are: "interstitial", "banner".
```   
11. Is subject to GDPR laws. Retuns true or false.   
```   
    mopub.shouldShowConsent()
```   

Android versions:   
'com.adcolony:sdk:4.5.0'   
'com.mopub.mediation:adcolony:4.5.0.0'   

'com.chartboost:chartboost-sdk:8.2.0'   
'com.mopub.mediation:chartboost:8.2.0.3'   

'com.facebook.android:audience-network-sdk:6.3.0'   
'com.mopub.mediation:facebookaudiencenetwork:6.3.0.0'   

'com.mopub.mediation:admob:19.6.0.1'   

'com.tapjoy:tapjoy-android-sdk:12.8.0@aar'   
'com.mopub.mediation:tapjoy:12.8.0.0'      

'com.unity3d.ads:unity-ads:3.7.1'   
'com.mopub.mediation:unityads:3.7.1.0'   

'com.applovin:applovin-sdk:10.1.2'   
'com.mopub.mediation:applovin:10.1.2.0'   

'com.vungle:publisher-sdk-android:6.9.1'   
'com.mopub.mediation:vungle:6.9.1.0'   

 'com.ironsource.sdk:mediationsdk:7.1.5'   
 'com.mopub.mediation:ironsource:7.1.5.0'   

 'com.pollfish:pollfish:5.6.0:googleplayRelease@aar'   
 'com.pollfish.mediation:pollfish-mopub:5.6.0.0'   

'com.smaato.android.sdk:mopub-banner-adapter-5-13:21.5.8'   
'com.smaato.android.sdk:smaato-sdk-banner:21.5.8'   

'com.smaato.android.sdk:mopub-interstitial-adapter-5-13:21.5.8'   
'com.smaato.android.sdk:smaato-sdk-interstitial:21.5.8'   

 'com.smaato.android.sdk:mopub-rewarded-video-adapter-5-13:21.5.8'   
 'com.smaato.android.sdk:smaato-sdk-rewarded-ads:21.5.8'   

 'com.verizon.ads:android-vas-standard-edition:1.9.0'   
 'com.mopub.mediation:verizon:1.9.0.1'   


Amazon:   
  
'com.adcolony:sdk:4.5.0'   
'com.mopub.mediation:adcolony:4.5.0.1'   

'com.chartboost:chartboost-sdk:8.2.0'   
'com.mopub.mediation:chartboost:8.2.0.3'   

'com.google.android.gms:play-services-ads:20.1.0'   
'com.mopub.mediation:admob:20.1.0.0'   
    
'com.tapjoy:tapjoy-android-sdk:12.8.0@aar'   
'com.mopub.mediation:tapjoy:12.8.0.0'   

'com.vungle:publisher-sdk-android:6.9.1'   
'com.mopub.mediation:vungle:6.9.1.0'   

'com.smaato.android.sdk:mopub-banner-adapter-5-13:21.5.9'   
'com.smaato.android.sdk:smaato-sdk-banner:21.5.9'   

'com.smaato.android.sdk:mopub-interstitial-adapter-5-13:21.5.9'   
'com.smaato.android.sdk:smaato-sdk-interstitial:21.5.9'   

'com.smaato.android.sdk:mopub-rewarded-video-adapter-5-13:21.5.9'   
'com.smaato.android.sdk:smaato-sdk-rewarded-ads:21.5.9'   

'com.applovin:applovin-sdk:10.2.1'   
'com.mopub.mediation:applovin:10.2.1.0'   

'com.verizon.ads:android-vas-standard-edition:1.9.0'     
'com.mopub.mediation:verizon:1.9.0.1'   



THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
