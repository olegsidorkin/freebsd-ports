--- lib/freebl/rijndael.c.orig	2024-08-01 13:24:30 UTC
+++ lib/freebl/rijndael.c
@@ -19,7 +19,7 @@
 #include "cts.h"
 #include "ctr.h"
 #include "gcm.h"
-#include "mpi.h"
+#include "mpi/mpi.h"
 
 #if !defined(IS_LITTLE_ENDIAN) && !defined(NSS_X86_OR_X64)
 // not test yet on big endian platform of arm
