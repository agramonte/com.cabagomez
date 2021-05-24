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
4. For whatever reason I have better luck getting impressions by pre-initializing the network. Do this before the init call for the networks you are using:
```   
    mopub.initMediationNetwork("chartboost", <appId>, <signature>)
    mopub.initMediationNetwork("verizon", <siteId>)
    mopub.initMediationNetwork("ironsource", <appId>)
    mopub.initMediationNetwork("tapjoy", <tapjoyapikey> )
    mopub.initMediationNetwork("adcolony", <appId>,<placementId1>,<placementId2>,<placementId3>,<placementId4>)
    mopub.initMediationNetwork("unity", <gameId>)
    mopub.initMediationNetwork("vungle", <appId>)
    mopub.initMediationNetwork("pangle", <appId>)
    mopub.initMediationNetwork("inmobi", <appkey>)
    
    
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

Latest version for both:
    TapjoyAdapterConfiguration: Adapter version 12.8.0.0, SDK version 12.8.0 (Verfied working.)
    ChartboostAdapterConfiguration: Adapter version 8.2.0.3, SDK version 8.2.0  (Verfied working.)
    FacebookAdapterConfiguration: Adapter version 6.5.0.0, SDK version 6.5.0  (Verfied working.)
    IronSourceAdapterConfiguration: Adapter version 7.1.5.1.1, SDK version 7.1.5.1 (Requests. No responses.)
    VerizonAdapterConfiguration: Adapter version 1.9.0.1, SDK version 1.9.0 (Requests. No responses.)
    InMobiAdapterConfiguration: Adapter version 9.1.9.0, SDK version 9.1.9  (Verfied working.)
    AdColonyAdapterConfiguration: Adapter version 4.5.0.1, SDK version 4.5.0  (Verfied working.)
    GooglePlayServicesAdapterConfiguration: Adapter version 20.1.0.0, SDK version 20.1.0  (Verfied working.)
    AppLovinAdapterConfiguration: Adapter version 10.2.1.0, SDK version 10.2.1  (Verfied working.)
    PangleAdapterConfiguration: Adapter version 3.5.1.1.0, SDK version 3.5.1.1  (No requests.)
    VungleAdapterConfiguration: Adapter version 6.9.1.0, SDK version 6.9.1  (Verfied working.)
    UnityAdsAdapterConfiguration: Adapter version 3.7.1.1, SDK version 3.7.1  (Verfied working.)

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
