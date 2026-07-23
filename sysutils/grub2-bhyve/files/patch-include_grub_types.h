--- include/grub/types.h.orig	2026-02-27 17:57:03 UTC
+++ include/grub/types.h
@@ -20,6 +20,7 @@
 #define GRUB_TYPES_HEADER	1
 
 #include <config.h>
+#include <stdbool.h>
 #ifndef GRUB_UTIL
 #include <grub/cpu/types.h>
 #endif
