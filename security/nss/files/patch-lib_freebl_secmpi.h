--- lib/freebl/secmpi.h.orig	2024-08-01 13:24:30 UTC
+++ lib/freebl/secmpi.h
@@ -2,7 +2,7 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
-#include "mpi.h"
+#include "mpi/mpi.h"
 
 #define CHECK_SEC_OK(func)         \
     if (SECSuccess != (rv = func)) \
