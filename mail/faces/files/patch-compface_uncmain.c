--- compface/uncmain.c.orig
+++ compface/uncmain.c
@@ -13,16 +13,14 @@
  *  to me, then an attempt will be made to fix them.
  */
 
-#include <stdlib.h>
-#include <unistd.h>
+#include <errno.h>
 #include <fcntl.h>
+#include <stdio.h>
 #include "compface.h"
 
-#define  STRCAT        (void) strcat
-#define  STRCPY        (void) strcpy
-#define  WRITE         (void) write
+extern int xbitmap;
 
-/* The buffer is longer than needed to handle sparse input formats */
+/* the buffer is longer than needed to handle sparse input formats */
 #define FACEBUFLEN 2048
 char fbuf[FACEBUFLEN];
 
@@ -32,56 +30,55 @@
 int outfile   = 1;
 char *outname = "<stdout>";
 
-char *cmdname;                 /* Basename of executable */
+/* basename of executable */
+char *cmdname;
 
-/* Error handling definitions follow */
+/* error handling definitions follow */
 
-extern int errno, sys_nerr;
-extern char *sys_errlist[];
+extern void exit P((int)) ;
 
 #define ERR         ((errno < sys_nerr) ? sys_errlist[errno] : "")
-#define INITERR(s)  { \
-                        STRCPY(fbuf, cmdname); \
-                        STRCAT(fbuf, ": "); \
-                        STRCAT(fbuf, (s));\
-                    }
-#define ADDERR(s)   STRCAT(fbuf, (s));
-#define ERROR       { \
-                        STRCAT(fbuf, "\n"); \
-                        WRITE(2, fbuf, strlen(fbuf)); \
-                        exit(1); \
-                    }
-#define INITWARN(s) { \
-                        STRCPY(fbuf, cmdname); \
-                        STRCAT(fbuf, ": (warning) "); \
-                        STRCAT(fbuf, (s)); \
-                    }
-#define ADDWARN(s)  STRCAT(fbuf, (s));
-#define WARN        { \
-                        STRCAT(fbuf, "\n"); \
-                        WRITE(2, fbuf, strlen(fbuf)); \
-                    }
+#define INITERR(s) {(void)strcpy(fbuf, cmdname); (void)strcat(fbuf, ": ");\
+					(void)strcat(fbuf, (s));}
+#define ADDERR(s) (void)strcat(fbuf, (s));
+#define ERROR {(void)strcat(fbuf, "\n");\
+				(void)write(2, fbuf, strlen(fbuf)); exit(1);}
+#define INITWARN(s) {(void)strcpy(fbuf, cmdname);\
+					(void)strcat(fbuf, ": (warning) ");\
+					(void)strcat(fbuf, (s));}
+#define ADDWARN(s) (void)strcat(fbuf, (s));
+#define WARN {(void)strcat(fbuf, "\n"); (void)write(2, fbuf, strlen(fbuf));}
 
 int
-main(int argc, char *argv[])
+main(argc, argv)
+int argc;
+char *argv[];
 {
     cmdname = *argv;
-    while (**argv) {
-        if (*((*argv)++) == '/') {
+  while (**argv)
+    if (*((*argv)++) == '/')
             cmdname = *argv;               /* find the command's basename */
-        }
+
+  if (argc > 1 && !strcmp(argv[1], "-X"))
+    {
+      xbitmap++;
+      argc--;
+      argv++;
     }
 
-    if (argc > 3) {
+  if (argc > 3)
+    {
         INITERR("usage: ")
         ADDERR(cmdname)
         ADDERR(" [infile [outfile]]")
         ERROR
     }
 
-    if ((argc > 1) && strcmp(*++argv, "-")) {
+  if ((argc > 1) && strcmp(*++argv, "-"))
+    {
         inname = *argv;
-        if ((infile = open(inname, O_RDONLY)) == -1) {
+      if ((infile = open(inname, O_RDONLY)) == -1)
+        {
             INITERR(inname)
             ADDERR(": ")
             ADDERR(ERR)
@@ -89,10 +86,11 @@
         }
     }
 
-    if (argc > 2) {
+  if (argc > 2)
+    {
         outname = *++argv;
-        if ((outfile = open(outname, O_WRONLY | O_CREAT | 
-                                     O_TRUNC, 0644)) == -1) {
+      if ((outfile = open(outname, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
+        {
             INITERR(outname)
             ADDERR(": ")
             ADDERR(ERR)
@@ -101,7 +99,8 @@
     }
 
     (void) ReadBuf();
-    switch (uncompface(fbuf)) {
+  switch (uncompface(fbuf))
+    {
         case -2 : INITERR("internal error")
                   ERROR
         case -1 : INITERR(inname)
@@ -121,13 +120,15 @@
 int
 WriteBuf()
 {
-    char *s, *t;
-    int len;
+	register char *s, *t;
+	register int len;
 
     s = fbuf;
     t = s + strlen(s);
-    while (s < t) {
-        if ((len = write(outfile, s, t - s)) == -1) {
+	while (s < t)
+	{
+		if ((len = write(outfile, s, t - s)) == -1)
+		{
             INITERR(outname)
             ADDERR(": ")
             ADDERR(ERR)
@@ -135,27 +136,30 @@
         }
         s += len;
     }
-    return(0);
+	return 0;
 }
 
 
 int
 ReadBuf()
 {
-    int count, len;
-    char *t;
+	register int count, len;
+	register char *t;
 
     count = 0;
     t = fbuf;
-    while ((len = read(infile, t, FACEBUFLEN - count))) {
-        if (len == -1) {
+	while (len = read(infile, t, FACEBUFLEN - count))
+	{
+		if (len == -1)
+		{
             INITERR(inname)
             ADDERR(": ")
             ADDERR(ERR)
             ERROR
         }
         t += len;
-        if ((count += len) >= FACEBUFLEN) {
+		if ((count += len) >= FACEBUFLEN)
+		{
             INITWARN(inname)
             ADDWARN(" exceeds internal buffer size.  Data may be lost")
             WARN
@@ -163,5 +167,5 @@
         }
     }
     *t = '\0';
-    return(count);
+	return count;
 }
