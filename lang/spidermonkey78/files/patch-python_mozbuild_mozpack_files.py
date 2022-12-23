--- python/mozbuild/mozpack/files.py.orig	2021-09-28 10:04:57 UTC
+++ python/mozbuild/mozpack/files.py
@@ -558,7 +558,7 @@ class PreprocessedFile(BaseFile):
         pp = Preprocessor(defines=self.defines, marker=self.marker)
         pp.setSilenceDirectiveWarnings(self.silence_missing_directive_warnings)
 
-        with _open(self.path, 'rU') as input:
+        with _open(self.path, 'r') as input:
             with _open(os.devnull, 'w') as output:
                 pp.processFile(input=input, output=output)
 
@@ -615,7 +615,7 @@ class PreprocessedFile(BaseFile):
         pp = Preprocessor(defines=self.defines, marker=self.marker)
         pp.setSilenceDirectiveWarnings(self.silence_missing_directive_warnings)
 
-        with _open(self.path, 'rU') as input:
+        with _open(self.path, 'r') as input:
             pp.processFile(input=input, output=dest, depfile=deps_out)
 
         dest.close()
