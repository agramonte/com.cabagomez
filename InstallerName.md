# solar2d-Installer-Name
Installer name for solar2d


1. Activate the plugin here: https://www.solar2dplugins.com. Follow the instructions for the build settings.

2. Require when you are about to use it:  
```
local ipn = require("plugin.installerName")
```  

3. Request installer package name:  
```
local packageName = ipn.getInstallerName()
```
