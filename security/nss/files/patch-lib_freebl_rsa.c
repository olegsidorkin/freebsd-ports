--- lib/freebl/rsa.c.orig	2024-08-01 13:24:30 UTC
+++ lib/freebl/rsa.c
@@ -15,9 +15,9 @@
 #include "nssilock.h"
 #include "prinit.h"
 #include "blapi.h"
-#include "mpi.h"
-#include "mpprime.h"
-#include "mplogic.h"
+#include "mpi/mpi.h"
+#include "mpi/mpprime.h"
+#include "mpi/mplogic.h"
 #include "secmpi.h"
 #include "secitem.h"
 #include "blapii.h"
