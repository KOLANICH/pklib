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

add_library(pkwareCommonSizeConstants OBJECT "${CMAKE_CURRENT_SOURCE_DIR}/getCommonSizeConstants.c")
target_include_directories(pkwareCommonSizeConstants PRIVATE ${Include_dir})
target_link_libraries(pkwareLUT PRIVATE pkwareCommonSizeConstants)
