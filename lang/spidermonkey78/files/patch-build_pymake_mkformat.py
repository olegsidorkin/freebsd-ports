--- build/pymake/mkformat.py.orig	2021-09-28 10:04:51 UTC
+++ build/pymake/mkformat.py
@@ -6,7 +6,7 @@ import pymake.parser
 filename = sys.argv[1]
 source = None
 
-with open(filename, 'rU') as fh:
+with open(filename, 'r') as fh:
     source = fh.read()
 
 statements = pymake.parser.parsestring(source, filename)
