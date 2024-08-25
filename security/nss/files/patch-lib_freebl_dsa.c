--- lib/freebl/dsa.c.orig	2024-08-01 13:24:30 UTC
+++ lib/freebl/dsa.c
@@ -17,7 +17,7 @@
 #include "nssilock.h"
 #include "secitem.h"
 #include "blapit.h"
-#include "mpi.h"
+#include "mpi/mpi.h"
 #include "secmpi.h"
 #include "pqg.h"
 
