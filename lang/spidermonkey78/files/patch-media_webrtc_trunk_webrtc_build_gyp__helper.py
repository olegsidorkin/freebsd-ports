--- media/webrtc/trunk/webrtc/build/gyp_helper.py.orig	2021-09-28 10:04:57 UTC
+++ media/webrtc/trunk/webrtc/build/gyp_helper.py
@@ -15,7 +15,7 @@ def apply_gyp_environment_from_file(file_path):
   """Reads in a *.gyp_env file and applies the valid keys to os.environ."""
   if not os.path.exists(file_path):
     return
-  with open(file_path, 'rU') as f:
+  with open(file_path, 'r') as f:
     file_contents = f.read()
   try:
     file_data = eval(file_contents, {'__builtins__': None}, None)
