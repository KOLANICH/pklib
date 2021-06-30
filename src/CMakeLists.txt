add_subdirectory("PKWareLUT")
add_subdirectory("explode")
add_subdirectory("implode")

buildAndPackageLib("pkware"
	COMPONENT "dev"
	DESCRIPTION "${PROJECT_DESCRIPTION}"
	PUBLIC_INCLUDES ${Include_dir}
	TYPE INTERFACE
)

pass_through_cpack_vars()
