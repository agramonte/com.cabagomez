# solar2d-Amazonlogin-Plugin
Amazonlogin Plugin for solar2d

Notes:
1. Will not work with the Gamecircle plugin.   
2. Security profile and enable amazon login has to be set up on the Amazon Developer portal.

1. Refrence the plugin:
```
local amazonlogin = require("plugin.amazonlogin")
```

2. Init. If player already logged in will fetch profile.
```
amazonlogin.init( 
    <yourListerner> 
)
```

2. Login.
```
    amazonlogin.login()   
```

3. Logout
```
    amazonlogin.logout()   
```  

8. Fetch user profile.
```
    amazonlogin.fetchUserProfile()
```


10. Logs example:

profile fetch
```
amazonlogin:	{
    "name":"amazonlogin",
    "phase":"fetchUserProfile", -- Posible include login, logout, and fetchUserProfile
    "name":"<nameofuser>",
    "email":"<email@of.user>,
    "isError":false -- Error if fails
    "message":"invalid scope" -- Error message if isError = true
}
 
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
