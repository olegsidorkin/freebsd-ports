--- lib/freebl/secmpi.c.orig	2024-08-01 13:24:30 UTC
+++ lib/freebl/secmpi.c
@@ -1,7 +1,7 @@
 #include "blapi.h"
 
-#include "mpi.h"
-#include "mpprime.h"
+#include "mpi/mpi.h"
+#include "mpi/mpprime.h"
 
 mp_err
 mpp_random_secure(mp_int *a)
