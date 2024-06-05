--- setup.py.orig	2024-03-11 12:49:34 UTC
+++ setup.py
@@ -21,7 +21,8 @@ SYSTEM_IS_UNIX = (sys.platform.startswith("linux") or
 ISA_L_SOURCE = os.path.join("src", "isal", "isa-l")
 
 SYSTEM_IS_UNIX = (sys.platform.startswith("linux") or
-                  sys.platform.startswith("darwin"))
+                  sys.platform.startswith("darwin") or
+                  sys.platform.startswith("freebsd"))
 SYSTEM_IS_WINDOWS = sys.platform.startswith("win")
 
 # Since pip builds in a temp directory by default, setting a fixed file in
@@ -113,7 +114,7 @@ def build_isa_l():
             cflags_param = "CFLAGS_aarch64"
         else:
             cflags_param = "CFLAGS_"
-        subprocess.run(["make", "-j", str(cpu_count), "-f", "Makefile.unx",
+        subprocess.run(["gmake", "-j", str(cpu_count), "-f", "Makefile.unx",
                         "isa-l.h", "bin/isa-l.a",
                         f"{cflags_param}={build_env.get('CFLAGS', '')}"],
                        **run_args)
