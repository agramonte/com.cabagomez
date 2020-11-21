local metadata =
{
	plugin =
	{
		format = 'staticLibrary',
		staticLibs = {
			"APDFacebookAudienceAdapter",
			"APDVungleAdapter"
		},
		frameworks = {
			"FBAudienceNetwork",
			"FBSDKCoreKit",
			"VungleSDK",
			-- Required frameworks
			"AdSupport",
			"CoreLocation",
			"Foundation",
			"MessageUI",
			"SafariServices",
			"StoreKit"

		},
		usesSwift = true
	},
}

return metadata
