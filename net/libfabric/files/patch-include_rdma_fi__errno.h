--- include/rdma/fi_errno.h.orig	2021-04-01 21:01:34 UTC
+++ include/rdma/fi_errno.h
@@ -104,7 +104,7 @@ extern "C" {
 //#define	FI_EDEADLOCK		EDEADLOCK	/* Resource deadlock would occur */
 //#define	FI_EBFONT		EBFONT		/* Bad font file format */
 //#define	FI_ENOSTR		ENOSTR		/* Device not a stream */
-#define	FI_ENODATA		ENODATA		/* No data available */
+#define	FI_ENODATA		ENOMSG		/* No data available */
 //#define	FI_ETIME		ETIME		/* Timer expired */
 //#define	FI_ENOSR		ENOSR		/* Out of streams resources */
 //#define	FI_ENONET		ENONET		/* Machine is not on the network */
