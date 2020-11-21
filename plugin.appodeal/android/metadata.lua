local metadata =
{
	plugin =
	{
		format = "jar",
		manifest =
		{
			permissions = {},

			usesPermissions =
			{
				"android.permission.INTERNET",
				"android.permission.ACCESS_NETWORK_STATE"
			},

			usesFeatures =
			{
				{ name="android.hardware.location", required=false },
				{ name="android.hardware.location.network", required=false },
				{ name="android.hardware.location.gps", required=false }
			},

			applicationChildElements =
			{
                [[
                    <meta-data android:name="com.appodeal.framework" android:value="corona" />
                ]]
            },
            
            manifestChildElements = 
            {
                -- Array of strings
                [[
                <uses-sdk tools:overrideLibrary="com.mopub.mobileads,com.mopub.mobileads.banner, com.mopub.mobileads.rewarded_video, com.mopub.mobileads.interstitial, com.mopub.mobileads.native_static, com.mopub.mobileads.base"/>
                ]]
            },
		}
	}
}

return metadata
