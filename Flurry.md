# solar2d-Flurry-Plugin
Flurry Plugin for solar2d


Versions:  
platform | version | 
--- | --- |
ios | 11.0.0 |


1. Require when you are about to use it:  
```
local flurryAnalytics = require( "plugin.cgflurry" )
```  

2. Init is backward compatable with solar2d flurry.analytics plugin:  
```
flurryAnalytics.init( listener, params )
```  
But you can also use the following params or params options:  
    a. loglevel can be set to "none".  
    b. notifications can be set to true/false. Default is false. When true you can send notification from flurry as long as you have it set-up.  
    c. doNotSell can be set to true/false. Default is false. When set to true flurry will not sell the customer's data. This is for CCPA compliance.  

3. Log event, startTimedEvent, and endTimedEvent are the same as the solar2d plugin:  
```
flurryAnalytics.logEvent( event [, params] )
```  
```  
flurryAnalytics.startTimedEvent( event [, params] )
```  
```  
flurryAnalytics.endTimedEvent( event [, params] )
```  

4. Reciept validation. All parameters are strings. Please check Flurry documentation for detail on parameters. Method will now return event with result of validation.  
```
flurryAnalytics.logPaymentTransaction({ 
    transactionId = "<transactionId>",
    productId = "<productId>",
    quantity = "<quantity>",
    price = "<price>",
    currency = "<currency>",
    productName = "<productName>",
    transactionState = "<trasactionState>" 
    }
 )
```  

5. Log errors.  
```
flurryAnalytics.logError( {
    error = "<error string>",
    message = "<message string>"
    }
)
```  
6. SKA Event.
```
flurryAnalytics.updateConversionValue( <int value> ) -- corresponding to flurryUpdateConversionValue Flurry method.
```  
or
```
flurryAnalytics.updateConversionValue( "noEvent" ) -- Valid options are "registration", "login", "subscription", "inAppPurchase", or "noEvent". "noEvent" is default.
```

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.