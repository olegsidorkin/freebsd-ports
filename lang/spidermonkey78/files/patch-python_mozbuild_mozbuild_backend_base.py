--- python/mozbuild/mozbuild/backend/base.py.orig	2021-09-28 10:04:57 UTC
+++ python/mozbuild/mozbuild/backend/base.py
@@ -265,7 +265,7 @@ class BuildBackend(LoggingMixin):
         return status
 
     @contextmanager
-    def _write_file(self, path=None, fh=None, readmode='rU'):
+    def _write_file(self, path=None, fh=None, readmode='r'):
         """Context manager to write a file.
 
         This is a glorified wrapper around FileAvoidWrite with integration to
