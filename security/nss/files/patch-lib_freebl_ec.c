--- lib/freebl/ec.c.orig	2024-08-01 13:24:30 UTC
+++ lib/freebl/ec.c
@@ -12,7 +12,7 @@
 #include "secerr.h"
 #include "secmpi.h"
 #include "secitem.h"
-#include "mplogic.h"
+#include "mpi/mplogic.h"
 #include "ec.h"
 #include "ecl.h"
 #include "verified/Hacl_P384.h"
