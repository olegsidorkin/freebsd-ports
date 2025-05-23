--- media/capture/video/file_video_capture_device_factory.cc.orig	2025-05-07 06:48:23 UTC
+++ media/capture/video/file_video_capture_device_factory.cc
@@ -52,7 +52,7 @@ void FileVideoCaptureDeviceFactory::GetDevicesInfo(
       VideoCaptureApi::WIN_DIRECT_SHOW;
 #elif BUILDFLAG(IS_MAC)
       VideoCaptureApi::MACOSX_AVFOUNDATION;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE;
 #else
       VideoCaptureApi::UNKNOWN;
