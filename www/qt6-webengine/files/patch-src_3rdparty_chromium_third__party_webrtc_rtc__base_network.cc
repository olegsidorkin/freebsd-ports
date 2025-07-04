--- src/3rdparty/chromium/third_party/webrtc/rtc_base/network.cc.orig	2024-06-17 12:56:06 UTC
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/network.cc
@@ -290,7 +290,12 @@ AdapterType GetAdapterTypeFromName(absl::string_view n
   }
 #endif
 
+#if defined(WEBRTC_BSD)
+  // Treat all other network interface names as ethernet on BSD
+  return ADAPTER_TYPE_ETHERNET;
+#else
   return ADAPTER_TYPE_UNKNOWN;
+#endif
 }
 
 NetworkManager::EnumerationPermission NetworkManager::enumeration_permission()
