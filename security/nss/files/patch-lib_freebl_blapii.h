--- lib/freebl/blapii.h.orig	2024-08-01 13:24:30 UTC
+++ lib/freebl/blapii.h
@@ -9,7 +9,7 @@
 #define _BLAPII_H_
 
 #include "blapit.h"
-#include "mpi.h"
+#include "mpi/mpi.h"
 #include "hasht.h"
 
 /* max block size of supported block ciphers */
