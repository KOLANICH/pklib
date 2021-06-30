buildAndPackageLib("pkwareLUT"
	COMPONENT "LUT"
	DESCRIPTION "${PROJECT_DESCRIPTION}"
	PRIVATE_INCLUDES ${Include_dir}
)
pass_through_cpack_vars()
