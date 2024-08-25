--- lib/freebl/dh.c.orig	2024-08-01 13:24:30 UTC
+++ lib/freebl/dh.c
@@ -16,7 +16,7 @@
 #include "blapi.h"
 #include "blapii.h"
 #include "secitem.h"
-#include "mpi.h"
+#include "mpi/mpi.h"
 #include "secmpi.h"
 
 #define KEA_DERIVED_SECRET_LEN 128
