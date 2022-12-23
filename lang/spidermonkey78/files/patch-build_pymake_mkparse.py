--- build/pymake/mkparse.py.orig	2021-09-28 10:04:51 UTC
+++ build/pymake/mkparse.py
@@ -5,7 +5,7 @@ import pymake.parser
 
 for f in sys.argv[1:]:
     print "Parsing %s" % f
-    fd = open(f, 'rU')
+    fd = open(f, 'r')
     s = fd.read()
     fd.close()
     stmts = pymake.parser.parsestring(s, f)
