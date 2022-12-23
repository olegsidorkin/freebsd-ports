--- dom/base/usecounters.py.orig	2021-09-28 10:04:51 UTC
+++ dom/base/usecounters.py
@@ -10,7 +10,7 @@ import sys
 
 def read_conf(conf_filename):
     # Can't read/write from a single StringIO, so make a new one for reading.
-    stream = open(conf_filename, 'rU')
+    stream = open(conf_filename, 'r')
 
     def parse_counters(stream):
         for line_num, line in enumerate(stream):
