--- chrome/browser/ui/views/frame/browser_frame_view_linux.cc.orig	2024-11-16 12:20:41 UTC
+++ chrome/browser/ui/views/frame/browser_frame_view_linux.cc
@@ -70,7 +70,7 @@ gfx::ShadowValues BrowserFrameViewLinux::GetShadowValu
 
 void BrowserFrameViewLinux::PaintRestoredFrameBorder(
     gfx::Canvas* canvas) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = frame()->tiled();
 #else
   const bool tiled = false;
@@ -125,7 +125,7 @@ int BrowserFrameViewLinux::NonClientHitTest(const gfx:
 }
 
 float BrowserFrameViewLinux::GetRestoredCornerRadiusDip() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = frame()->tiled();
 #else
   const bool tiled = false;
