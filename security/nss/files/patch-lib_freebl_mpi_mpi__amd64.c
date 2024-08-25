--- lib/freebl/mpi/mpi_amd64.c.orig	2024-08-01 13:24:30 UTC
+++ lib/freebl/mpi/mpi_amd64.c
@@ -6,7 +6,7 @@
 #error This file only works on AMD64 platforms.
 #endif
 
-#include <mpi-priv.h>
+#include "mpi-priv.h"
 
 /*
  * MPI glue
