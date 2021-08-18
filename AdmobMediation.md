Ads following networks to Admob for bidding:

Applovin
AdColony
Tapjoy
Facebook

1. Clone the repo to the your repo cache:
2. Add this to the build settings:   
```
["plugin_admobtapjoy"] = {
    publisherId = "com.cabagomez",
    supportedPlatforms = { iphone=true, android = true }
},
["plugin_admobadcolony"] = {
    publisherId = "com.cabagomez",
    supportedPlatforms = { iphone=true, android = true }
},
["plugin_admobapplovin"] = {
    publisherId = "com.cabagomez",
    supportedPlatforms = { iphone=true, android = true }
},
["plugin_admobfacebook"] = {
    publisherId = "com.cabagomez",
    supportedPlatforms = { iphone=true, android = true }
}
```
3. Set up mediation on the Admob console.   






THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.