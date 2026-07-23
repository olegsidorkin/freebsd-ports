--- grub-core/commands/parttool.c.orig	2015-08-31 22:42:56 UTC
+++ grub-core/commands/parttool.c
@@ -295,7 +295,7 @@ grub_cmd_parttool (grub_command_t cmd __attribute__ ((
 		    switch (curarg->type)
 		      {
 		      case GRUB_PARTTOOL_ARG_BOOL:
-			pargs[curarg - ptool->args].bool
+			pargs[curarg - ptool->args].b
 			  = (args[j][grub_strlen (curarg->name)] != '-');
 			break;
 
