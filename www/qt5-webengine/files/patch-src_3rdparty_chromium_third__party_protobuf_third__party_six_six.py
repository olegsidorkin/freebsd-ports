--- src/3rdparty/chromium/third_party/protobuf/third_party/six/six.py.orig	2024-05-31 17:32:55 UTC
+++ src/3rdparty/chromium/third_party/protobuf/third_party/six/six.py
@@ -71,6 +71,10 @@ else:
             MAXSIZE = int((1 << 63) - 1)
         del X
 
+if PY34:
+    from importlib.util import spec_from_loader
+else:
+    spec_from_loader = None
 
 def _add_doc(func, doc):
     """Add documentation to a function."""
@@ -185,6 +189,11 @@ class _SixMetaPathImporter(object):
         if fullname in self.known_modules:
             return self
         return None
+
+    def find_spec(self, fullname, path, target=None):
+        if fullname in self.known_modules:
+            return spec_from_loader(fullname, self)
+        return None
 
     def __get_module(self, fullname):
         try:
