# idVerifySig-corona-plugin
iOS Corona plugin to generate signature of local user (implementation of generateIdentityVerificationSignatureWithCompletionHandler). Before starting this guide you will need to activate the plugin here: https://www.solar2dplugins.com/plugins/verification-signature

1. Add the plugin to the build.settings as instructed on the page.

2. Add require statement

```lua
local idVerify = require( "plugin.idVerifySig" )
```
3. Init the library providing a listener.
```lua
idVerify.init( listener )
```
4. Call method to request signature. Data in a form of a lua table will be returned in the listerner specified in the init. Note that user has to be signed in to GameCenter for this to work (please look at implementation in sample app).
```lua
idVerify.getSignature()
```
Sample data returned. In case of error isError will be true.
```json
 {
  "keyURL":"<keyURL>",
  "name":"IdVerifySigEvent",
  "salt":"<salt>",
  "signature":"<signature>",
  "timestamp":12345678,
  "isError":false
}
```


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
