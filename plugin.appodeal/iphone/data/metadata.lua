local metadata =
{
	plugin =
	{
		format = 'staticLibrary',
		staticLibs = { 
			"plugin_appodeal_base",
			"xml2", 
			"z"
		},
		frameworks = { 
			"Appodeal",
			"Security",
			"CoreMedia",
			"CoreGraphics",
			"CoreImage",
			"SystemConfiguration",
			"AVFoundation",
			"MediaPlayer",
			"QuartzCore",
			"UIKit",
			"WebKit",
			"ImageIO",
			"MobileCoreServices",
			"CoreTelephony"
		
		},
		frameworksOptional = {
			"StoreKit", 
			"AdSupport",
			"CoreLocation"
		},
		usesSwift = true
	},
}

return metadata
