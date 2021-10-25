
find_package(GTest)
find_package(fileTestSuite_runner)

message(STATUS "pkgcfg_lib_fileTestSuite_runner_FileTestSuite_runner ${pkgcfg_include_fileTestSuite_runner_FileTestSuite_runner}")
message(STATUS "pkgcfg_lib_fileTestSuite_runner_FileTestSuite_runner ${pkgcfg_lib_fileTestSuite_runner_FileTestSuite_runner}")

buildAndPackageLib("pklib_tests_generic"
	COMPONENT "tests"
	DESCRIPTION "A common library for testing of this lib"
	PUBLIC_INCLUDES ${Include_dir} "${pkgcfg_include_fileTestSuite_runner_FileTestSuite_runner}"
	PRIVATE_LIBS "${pkgcfg_lib_fileTestSuite_runner_FileTestSuite_runner}"
)

#gtest_discover_tests(tests)
