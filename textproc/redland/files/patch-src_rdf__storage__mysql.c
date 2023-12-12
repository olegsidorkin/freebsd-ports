--- src/rdf_storage_mysql.c.orig	2012-12-29 23:01:17 UTC
+++ src/rdf_storage_mysql.c
@@ -38,6 +38,7 @@
 
 #include <stdio.h>
 #include <string.h>
+#include <stdbool.h>
 #ifdef HAVE_STDLIB_H
 #include <stdlib.h>
 #endif
@@ -447,7 +448,7 @@ librdf_storage_mysql_get_handle(librdf_storage* storag
 
 #ifdef HAVE_MYSQL_OPT_RECONNECT
   if(1) {
-    my_bool value=(context->reconnect) ? 1 : 0;
+    bool value=(context->reconnect) ? 1 : 0;
     mysql_options(connection->handle, MYSQL_OPT_RECONNECT, &value);
   }
 #endif
