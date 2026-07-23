--- setup.py.orig	2023-09-28 15:39:18 UTC
+++ setup.py
@@ -363,6 +363,8 @@ if system == "linux":
 
 if system == "linux":
     system_cflags += ["-DWEBRTC_LINUX", "-DWEBRTC_THREAD_RR", "-DWEBRTC_POSIX"]
+elif system == "freebsd":
+    system_cflags += ["-DWEBRTC_FREEBSD", "-DWEBRTC_THREAD_RR", "-DWEBRTC_POSIX"]
 elif system == "darwin":
     system_cflags += ["-DWEBRTC_MAC", "-DWEBRTC_POSIX"]
     machine = "arm64"  # assume cross-compiling
