# com.cabagomez

These are my local plugin folder. There is absolutely no support but you can use them. If you find an issue please open up a ticket here, but don't expect a response. 

There is what I call cadence to when these plugin get updated. I have a number of apps I mentain. These plugins get updated everytime a new version of an app that uses a particular plugin is updated. I suggest that if you don't want to keep up with the latest versions, to clone the repo and then just pull from origin when you are ready to upgrade.

Current plugins and why some have been removed:   
Appodeal: (source is now available from Solar2d removed from here).    
Ironsource   
Mopub: Currently not being updated since Applovin purchased the company.   
Amazon Login   
Verify Signature   
Installer Name   
Tapjoy Install (No longer in use. No updates.)   


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.   

Use: 
1. Clone this repo to the location of your plugins. On a typical mac this would be "/Users/yourname/Solar2DPlugins/". The content of this repo should be at the root of "/Users/yourname/Solar2DPlugins/com.cabagomez/". Not sure of the location on a pc.   
2. Now add the particular plugin you want to use by adding this to your build settings. For example for the base of ironsource:
```
["plugin_ironsource"] = 
        {
            publisherId = "com.cabagomez"
        },

```




