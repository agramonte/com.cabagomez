local metadata =
{
	plugin =
	{
		format = 'staticLibrary',
		staticLibs = { 
			"plugin_appodealadapters",
			-- Other static.
			"xml2", 
			"z",
		},
		frameworks = { 
			"AmazonAd",
			"AppLovinSDK",
			"GoogleAppMeasurement",
			"GoogleMobileAds",
			"GoogleUtilities",
			"nanopb",
			"PromisesObjC",
			"UserMessagingPlatform"
		},
		frameworksOptional = {"StoreKit", "AdSupport","CoreLocation"},
		usesSwift = true
	},
}

return metadata
