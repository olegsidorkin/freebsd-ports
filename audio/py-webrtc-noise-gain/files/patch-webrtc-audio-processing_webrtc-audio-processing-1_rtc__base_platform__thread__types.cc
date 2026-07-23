--- webrtc-audio-processing/webrtc-audio-processing-1/rtc_base/platform_thread_types.cc.orig	2023-09-28 15:39:18 UTC
+++ webrtc-audio-processing/webrtc-audio-processing-1/rtc_base/platform_thread_types.cc
@@ -15,6 +15,10 @@
 #include <sys/syscall.h>
 #endif
 
+#if defined(WEBRTC_FREEBSD)
+#include <pthread_np.h>
+#endif
+
 #if defined(WEBRTC_WIN)
 #include "rtc_base/arraysize.h"
 
@@ -33,6 +37,8 @@ PlatformThreadId CurrentThreadId() {
 #elif defined(WEBRTC_POSIX)
 #if defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   return pthread_mach_thread_np(pthread_self());
+#elif defined(WEBRTC_FREEBSD)
+  return pthread_getthreadid_np();
 #elif defined(WEBRTC_ANDROID)
   return gettid();
 #elif defined(WEBRTC_FUCHSIA)
