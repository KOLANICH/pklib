buildAndPackageLib("implode"
	NON_RECURSIVE_GLOB
	COMPONENT "compressor"
	DESCRIPTION "${PROJECT_DESCRIPTION}"
	PRIVATE_INCLUDES ${Include_dir}
	PRIVATE_LIBS "pkwareLUT"
)
pass_through_cpack_vars()
