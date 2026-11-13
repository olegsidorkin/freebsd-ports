--- absl/base/internal/unscaledcycleclock.cc.orig	2026-11-12 18:26:02 UTC
+++ absl/base/internal/unscaledcycleclock.cc
@@ -97,9 +97,12 @@ double UnscaledCycleClock::Frequency() {
   static once_flag init_timebase_frequency_once;
   static double timebase_frequency = 0.0;
   base_internal::LowLevelCallOnce(&init_timebase_frequency_once, [&]() {
-    size_t length = sizeof(timebase_frequency);
-    sysctlbyname("kern.timecounter.tc.timebase.frequency", &timebase_frequency,
-                 &length, nullptr, 0);
+    uint64_t freq = 0;
+    size_t length = sizeof(freq);
+    if (sysctlbyname("kern.timecounter.tc.timebase.frequency", &freq, &length,
+	nullptr, 0) == 0) {
+	timebase_frequency = static_cast<double>(freq);
+    }
   });
   return timebase_frequency;
 #else
