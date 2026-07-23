--- grub-core/lib/posix_wrap/sys/types.h.orig	2015-08-31 22:42:56 UTC
+++ grub-core/lib/posix_wrap/sys/types.h
@@ -27,11 +27,6 @@ typedef grub_ssize_t ssize_t;
 #include <stddef.h>
 #endif
 typedef grub_ssize_t ssize_t;
-#ifndef GRUB_POSIX_BOOL_DEFINED
-typedef enum { false = 0, true = 1 } bool;
-#define GRUB_POSIX_BOOL_DEFINED 1
-#endif
-
 typedef grub_uint8_t uint8_t;
 typedef grub_uint16_t uint16_t;
 typedef grub_uint32_t uint32_t;
