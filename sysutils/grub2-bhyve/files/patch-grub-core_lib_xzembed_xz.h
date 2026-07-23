--- grub-core/lib/xzembed/xz.h.orig	2015-08-31 22:42:56 UTC
+++ grub-core/lib/xzembed/xz.h
@@ -29,10 +29,6 @@
 #include <string.h>
 #include <grub/misc.h>
 
-#ifndef GRUB_POSIX_BOOL_DEFINED
-typedef enum { false = 0, true = 1 } bool;
-#endif
-
 /**
  * enum xz_ret - Return codes
  * @XZ_OK:              Everything is OK so far. More input or more output
