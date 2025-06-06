--- src/libslic3r/SupportSpotsGenerator.cpp.orig	2025-04-10 11:26:51 UTC
+++ src/libslic3r/SupportSpotsGenerator.cpp
@@ -1063,7 +1063,7 @@ SliceMappings update_active_object_parts(const Layer  
                 }
             }
             const float bottom_z = layer->bottom_z();
-            auto estimate_conn_strength = [bottom_z](const SliceConnection &conn) {
+            auto estimate_conn_strength = [bottom_z](const SliceConnection &conn) -> float {
                 if (conn.area < EPSILON) { // connection is empty, does not exists. Return max strength so that it is not picked as the
                                            // weakest connection.
                     return INFINITY;
