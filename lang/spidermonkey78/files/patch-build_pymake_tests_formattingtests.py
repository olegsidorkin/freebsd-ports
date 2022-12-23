--- build/pymake/tests/formattingtests.py.orig	2021-09-28 10:04:51 UTC
+++ build/pymake/tests/formattingtests.py
@@ -253,7 +253,7 @@ class MakefileCorupusTest(TestBase):
                 continue
 
             source = None
-            with open(makefile, 'rU') as fh:
+            with open(makefile, 'r') as fh:
                 source = fh.read()
 
             try:
