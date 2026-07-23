--- grub-core/parttool/msdospart.c.orig	2015-08-31 22:42:56 UTC
+++ grub-core/parttool/msdospart.c
@@ -61,7 +61,7 @@ static grub_err_t grub_pcpart_boot (const grub_device_
       return grub_errno;
     }
 
-  if (args[0].set && args[0].bool)
+  if (args[0].set && args[0].b)
     {
       for (i = 0; i < 4; i++)
 	mbr.entries[i].flag = 0x0;
@@ -116,7 +116,7 @@ static grub_err_t grub_pcpart_type (const grub_device_
 
   if (args[1].set)
     {
-      if (args[1].bool)
+      if (args[1].b)
 	type |= GRUB_PC_PARTITION_TYPE_HIDDEN_FLAG;
       else
 	type &= ~GRUB_PC_PARTITION_TYPE_HIDDEN_FLAG;
