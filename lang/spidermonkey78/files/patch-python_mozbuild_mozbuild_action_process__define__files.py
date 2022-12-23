--- python/mozbuild/mozbuild/action/process_define_files.py.orig	2021-09-28 10:04:57 UTC
+++ python/mozbuild/mozbuild/action/process_define_files.py
@@ -36,7 +36,7 @@ def process_define_file(output, input):
             not config.substs.get('JS_STANDALONE'):
         config = PartialConfigEnvironment(mozpath.join(topobjdir, 'js', 'src'))
 
-    with open(path, 'rU') as input:
+    with open(path, 'r') as input:
         r = re.compile('^\s*#\s*(?P<cmd>[a-z]+)(?:\s+(?P<name>\S+)(?:\s+(?P<value>\S+))?)?', re.U)
         for l in input:
             m = r.match(l)
