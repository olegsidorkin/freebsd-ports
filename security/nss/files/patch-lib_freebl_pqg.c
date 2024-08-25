--- lib/freebl/pqg.c.orig	2024-08-01 13:24:30 UTC
+++ lib/freebl/pqg.c
@@ -15,9 +15,9 @@
 #include "prtypes.h"
 #include "blapi.h"
 #include "secitem.h"
-#include "mpi.h"
-#include "mpprime.h"
-#include "mplogic.h"
+#include "mpi/mpi.h"
+#include "mpi/mpprime.h"
+#include "mpi/mplogic.h"
 #include "secmpi.h"
 
 #define MAX_ITERATIONS 1000 /* Maximum number of iterations of primegen */
