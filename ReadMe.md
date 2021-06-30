pklib (modified for better packaging)
=====

It is the modified version of [Ladislav Zezula](https://github.com/ladislav-zezula)'s [`pklib`](https://github.com/ladislav-zezula/StormLib/tree/master/src/pklib), ripped out of [`StormLib`](https://github.com/ladislav-zezula/StormLib), which is a free open-source compressor for PKWare DCL.


Modifications:

* splitted into a separate git repo for the convenience of ones who want to inline it as a submodule
* Splitted look-up tables (LUTs) into a separate shared lib used by both compressor and decompressor
* changed repo layout for convenience and clarity: each lib is within own dir, and test for it in its subdir
* implemented building with CMake, packaging with CPack and other stuff usin [Boilerplate.cmake](https://github.com/KOLANICH-libs/Boilerplate.cmake)
* implemented testing using [`fileTestSuite`](https://github.com/fileTestSuite/fileTestSuite)
