buildAndPackageLib("pklib_implode_test"
	DO_NOT_ADD_LIB_PREFIX
	COMPONENT "tests"
	DESCRIPTION "Tests for libimplode"
	PUBLIC_INCLUDES ${Include_dir}
	PRIVATE_INCLUDES  ${tests_dir}
	PRIVATE_LIBS "implode" "pklib_tests_generic"
)
