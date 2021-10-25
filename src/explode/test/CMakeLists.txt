buildAndPackageLib("pklib_explode_test"
	DO_NOT_ADD_LIB_PREFIX
	COMPONENT "tests"
	DESCRIPTION "Tests for libexplode"
	PUBLIC_INCLUDES ${Include_dir}
	PRIVATE_INCLUDES  ${tests_dir}
	PRIVATE_LIBS "explode" "pklib_tests_generic"
)
