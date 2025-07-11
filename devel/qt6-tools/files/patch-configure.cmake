Fix detection of zstd.

CMake Error at /usr/local/lib/cmake/zstd/zstdTargets.cmake:42 (message):
  Some (but not all) targets in this export set were already defined.

  Targets Defined: zstd::libzstd_shared

  Targets not yet defined: zstd::libzstd_static

Call Stack (most recent call first):
  /usr/local/lib/cmake/zstd/zstdConfig.cmake:1 (include)
  /usr/local/lib/cmake/Qt6/FindWrapZSTD.cmake:24 (find_package)
  /usr/local/lib/cmake/Qt6/QtFindPackageHelpers.cmake:156 (find_package)
  src/designer/src/lib/CMakeLists.txt:415 (qt_find_package)

Regressed by: https://code.qt.io/cgit/qt/qttools.git/commit/?h=6.6.0&id=ff5c080c2eb9267c43da6fafe953bf50076443c4

--- configure.cmake.orig	2025-02-19 09:54:25 UTC
+++ configure.cmake
@@ -1,6 +1,11 @@
 # Copyright (C) 2022 The Qt Company Ltd.
 # SPDX-License-Identifier: BSD-3-Clause
 
+#### Libraries
+
+qt_find_package(WrapZSTD 1.3 PROVIDED_TARGETS WrapZSTD::WrapZSTD MODULE_NAME designer)
+
+
 #### Tests
 
 qt_find_package(WrapLibClang 8 PROVIDED_TARGETS WrapLibClang::WrapLibClang)
@@ -8,7 +13,6 @@ endif()
 if(TARGET WrapLibClang::WrapLibClang)
     set(TEST_libclang "ON" CACHE BOOL "Required libclang version found." FORCE)
 endif()
-
 
 
 #### Features
