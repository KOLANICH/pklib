buildAndPackageLib("explode"
	NON_RECURSIVE_GLOB
	COMPONENT "decompressor"
	DESCRIPTION "${PROJECT_DESCRIPTION}"
	PRIVATE_INCLUDES ${Include_dir}
	PRIVATE_LIBS "pkwareLUT"
)
if(WITH_TESTS)
	add_subdirectory("test")
endif()
pass_through_cpack_vars()
