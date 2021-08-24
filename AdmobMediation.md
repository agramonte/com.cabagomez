Ads following networks to Admob:

Applovin (Bidding)
AdColony (Bidding)
Tapjoy (Bidding)
Facebook (Bidding)
Chartboost 
Unity
Tappx

1. Clone the repo to the your repo cache:
2. Add this to the build settings:
```
["plugin_admobtapjoy"] = {
    publisherId = "com.cabagomez"
},
["plugin_admobadcolony"] = {
    publisherId = "com.cabagomez"
},
["plugin_admobapplovin"] = {
    publisherId = "com.cabagomez"
},
["plugin_admobfacebook"] = {
    publisherId = "com.cabagomez"
},
["plugin_admobchartboost"] = {
    publisherId = "com.cabagomez"
},
-- Works on Amazon but shows Google Play ads.
["plugin_admobunity"] = {
    publisherId = "com.cabagomez",
    supportedPlatforms = { iphone = true, android = true, ["android-kindle"]=false } 
},
-- Only Android
-- Currently not working opened a ticket with Tappx
["plugin_admobtappx"] = {
    publisherId = "com.cabagomez",
    supportedPlatforms = { android = true, ["android-kindle"]=true } 
}
```
3. Set up mediation on the Admob console.   
4. The tapjoy adapter also supports these calls:   
```
local admobTapjoy = require( "plugin.admobtapjoy" )
admobTapjoy.setDebug(true) -- Or false.
admobTapjoy.setGcmSender() -- Have not tested this in a while. Suspect that it still works.
admobTapjoy.setUserLevel() -- Have not tested this in a while. Suspect that it still works.
admobTapjoy.setUserID( "fsdfsdf" )
admobTapjoy.setPrivacy( {
    underAge = true, 
    subjectToConsent = false, --subject to GDPR consent
    hasUserConsent = false -- required if subjectToConsent is true.
    } 
)


```






THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.