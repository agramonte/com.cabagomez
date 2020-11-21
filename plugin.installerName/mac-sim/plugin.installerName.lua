local Library = require "CoronaLibrary"

-- Create library
local lib = Library:new{ name="plugin.installerName", publisherId="com.cabagomez", version=1}

local function showWarning()
    print( " WARNING: plugin.installerName plugin is only supported on Android devices.")
end

function lib.getInstallerName()
    showWarning()
    return ""
end

-------------------------------------------------------------------------------
-- END
-------------------------------------------------------------------------------

-- Return an instance
return lib
