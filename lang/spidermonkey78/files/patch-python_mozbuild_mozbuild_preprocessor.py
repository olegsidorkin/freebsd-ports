--- python/mozbuild/mozbuild/preprocessor.py.orig	2021-09-28 10:04:57 UTC
+++ python/mozbuild/mozbuild/preprocessor.py
@@ -517,7 +517,7 @@ class Preprocessor:
 
         if args:
             for f in args:
-                with io.open(f, 'rU', encoding='utf-8') as input:
+                with io.open(f, 'r', encoding='utf-8') as input:
                     self.processFile(input=input, output=out)
             if depfile:
                 mk = Makefile()
@@ -807,7 +807,7 @@ class Preprocessor:
                     args = self.applyFilters(args)
                 if not os.path.isabs(args):
                     args = os.path.join(self.curdir, args)
-                args = io.open(args, 'rU', encoding='utf-8')
+                args = io.open(args, 'r', encoding='utf-8')
             except Preprocessor.Error:
                 raise
             except Exception:
@@ -862,7 +862,7 @@ def preprocess(includes=[sys.stdin], defines={},
     pp = Preprocessor(defines=defines,
                       marker=marker)
     for f in includes:
-        with io.open(f, 'rU', encoding='utf-8') as input:
+        with io.open(f, 'r', encoding='utf-8') as input:
             pp.processFile(input=input, output=output)
     return pp.includes
 
