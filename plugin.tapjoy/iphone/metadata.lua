local metadata =
{
	plugin =
	{
		format = 'staticLibrary',
		staticLibs = { 'plugin_tapjoy', },
		frameworks = {
			'Tapjoy',
		'AdSupport',
		'CFNetwork',
		'CoreGraphics',
		'Foundation',
		'ImageIO'

		},
		frameworksOptional = {'CoreTelephony', },
	},
}

return metadata
