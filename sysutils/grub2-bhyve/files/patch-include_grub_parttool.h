--- include/grub/parttool.h.orig	2015-08-31 22:42:56 UTC
+++ include/grub/parttool.h
@@ -32,7 +32,7 @@ struct grub_parttool_args
   int set;
   union
   {
-    int bool;
+    int b;
     char *str;
   };
 };
