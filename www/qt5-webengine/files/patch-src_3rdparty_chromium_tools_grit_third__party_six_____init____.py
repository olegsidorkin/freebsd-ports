--- src/3rdparty/chromium/tools/grit/third_party/six/__init__.py.orig	2024-03-26 14:47:34 UTC
+++ src/3rdparty/chromium/tools/grit/third_party/six/__init__.py
@@ -72,6 +72,12 @@ else:
         del X
 
 
+if PY34:
+    from importlib.util import spec_from_loader
+else:
+    spec_from_loader = None
+
+
 def _add_doc(func, doc):
     """Add documentation to a function."""
     func.__doc__ = doc
@@ -184,6 +190,11 @@ class _SixMetaPathImporter(object):
     def find_module(self, fullname, path=None):
         if fullname in self.known_modules:
             return self
+        return None
+
+    def find_spec(self, fullname, path, target=None):
+        if fullname in self.known_modules:
+            return spec_from_loader(fullname, self)
         return None
 
     def __get_module(self, fullname):
