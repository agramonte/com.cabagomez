local metadata =
{
	plugin =
	{
		format = "staticLibrary",

		-- This is the name without the 'lib' prefix.
		-- In this case, the static library is called: libSTATIC_LIB_NAME.a
		staticLibs = { "plugin_pollfish", }, 

		frameworks = { "SystemConfiguration", "AdSupport", "CoreTelephony", "WebKit", "pollfish"},
		frameworksOptional = {},
	}
}

return metadata
