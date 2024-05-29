--- libs/python/src/exec.cpp.orig	2019-12-10 00:19:45 UTC
+++ libs/python/src/exec.cpp
@@ -106,7 +106,7 @@ object BOOST_PYTHON_DECL exec_file(char const *filenam
   char *f = const_cast<char *>(filename);
   // Let python open the file to avoid potential binary incompatibilities.
 #if PY_VERSION_HEX >= 0x03040000
-  FILE *fs = _Py_fopen(f, "r");
+  FILE *fs = fopen(f, "r");
 #elif PY_VERSION_HEX >= 0x03000000
   PyObject *fo = Py_BuildValue("s", f);
   FILE *fs = _Py_fopen(fo, "r");
