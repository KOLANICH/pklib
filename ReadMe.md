pklib (modified for better packaging)
=====
**We have moved to https://codeberg.org/implode-compression-impls/pklib, grab new versions there.**

Under the disguise of "better security" Micro$oft-owned GitHub has [discriminated users of 1FA passwords](https://github.blog/2023-03-09-raising-the-bar-for-software-security-github-2fa-begins-march-13/) while having commercial interest in success of [FIDO 1FA specifications](https://fidoalliance.org/specifications/download/) and [Windows Hello implementation](https://support.microsoft.com/en-us/windows/passkeys-in-windows-301c8944-5ea2-452b-9886-97e4d2ef4422) which [it promotes as a replacement for passwords](https://github.blog/2023-07-12-introducing-passwordless-authentication-on-github-com/). It will result in dire consequencies and is competely inacceptable, [read why](https://codeberg.org/KOLANICH/Fuck-GuanTEEnomo).

If you don't want to participate in harming yourself, it is recommended to follow the lead and migrate somewhere away of GitHub and Micro$oft. Here is [the list of alternatives and rationales to do it](https://github.com/orgs/community/discussions/49869). If they delete the discussion, there are certain well-known places where you can get a copy of it. [Read why you should also leave GitHub](https://codeberg.org/KOLANICH/Fuck-GuanTEEnomo).

---

It is the modified version of [Ladislav Zezula](https://github.com/ladislav-zezula)'s [`pklib`](https://github.com/ladislav-zezula/StormLib/tree/master/src/pklib), ripped out of [`StormLib`](https://github.com/ladislav-zezula/StormLib), which is a free open-source compressor for PKWare DCL.


Modifications:

* splitted into a separate git repo for the convenience of ones who want to inline it as a submodule
* Splitted look-up tables (LUTs) into a separate shared lib used by both compressor and decompressor
* changed repo layout for convenience and clarity: each lib is within own dir, and test for it in its subdir
* implemented building with CMake, packaging with CPack and other stuff usin [Boilerplate.cmake](https://codeberg.org/KOLANICH-libs/Boilerplate.cmake)
* implemented testing using [`fileTestSuite`](https://codeberg.org/fileTestSuite/fileTestSuite)
