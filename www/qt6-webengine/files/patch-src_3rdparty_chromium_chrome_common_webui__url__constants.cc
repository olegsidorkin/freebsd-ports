--- src/3rdparty/chromium/chrome/common/webui_url_constants.cc.orig	2024-07-03 01:14:49 UTC
+++ src/3rdparty/chromium/chrome/common/webui_url_constants.cc
@@ -511,18 +511,18 @@ const char kOsUIVersionURL[] = "os://version";
 const char kOsUIVersionURL[] = "os://version";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kChromeUIWebUIJsErrorHost[] = "webuijserror";
 const char kChromeUIWebUIJsErrorURL[] = "chrome://webuijserror/";
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 const char kChromeUIConnectorsInternalsHost[] = "connectors-internals";
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kChromeUIDiscardsHost[] = "discards";
 const char kChromeUIDiscardsURL[] = "chrome://discards/";
 #endif
@@ -537,14 +537,14 @@ const char kChromeUILinuxProxyConfigHost[] = "linux-pr
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 const char kChromeUISandboxHost[] = "sandbox";
 #endif
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
 const char kChromeUIBrowserSwitchHost[] = "browser-switch";
 const char kChromeUIBrowserSwitchURL[] = "chrome://browser-switch/";
 const char kChromeUIIntroHost[] = "intro";
@@ -563,7 +563,7 @@ const char kChromeUIProfilePickerStartupQuery[] = "sta
 const char kChromeUIProfilePickerStartupQuery[] = "startup";
 #endif
 
-#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
      defined(TOOLKIT_VIEWS)) ||                         \
     defined(USE_AURA)
 const char kChromeUITabModalConfirmDialogHost[] = "tab-modal-confirm-dialog";
@@ -647,7 +647,7 @@ const char kCookiesSubPagePath[] = "/cookies";
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const char kChromeUIWebAppSettingsURL[] = "chrome://app-settings/";
 const char kChromeUIWebAppSettingsHost[] = "app-settings";
 #endif
@@ -895,7 +895,7 @@ const char* const kChromeDebugURLs[] = {
     blink::kChromeUIGpuJavaCrashURL,
     kChromeUIJavaCrashURL,
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     kChromeUIWebUIJsErrorURL,
 #endif
     kChromeUIQuitURL,
