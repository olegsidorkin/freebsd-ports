--- lib/freebl/rsa_blind.c.orig	2024-08-01 13:24:30 UTC
+++ lib/freebl/rsa_blind.c
@@ -12,12 +12,12 @@
 
 #include "secerr.h"
 #include "blapi.h"
-#include "mpi.h"
+#include "mpi/mpi.h"
 #include "secitem.h"
 #include "prerr.h"
 #include "blapii.h"
 #include "secmpi.h"
-#include "mpi-priv.h"
+#include "mpi/mpi-priv.h"
 #include "pqg.h"
 
 /*#define RSA_DEBUG*/
