PORTNAME=	epson-inkjet-printer-201207w
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	https://download.ebz.epson.net/dsc/op/stable/RPMS/x86_64/:amd64 \
		https://download.ebz.epson.net/dsc/op/stable/RPMS/i486/:i386
DISTFILES_amd64=${DISTNAME}-1lsb3.2.x86_64.rpm:amd64
DISTFILES_i386=	${DISTNAME}-1lsb3.2.i486.rpm:i386

MAINTAINER=	ninjaskool@gmail.com
COMMENT=	CUPS filter for Seiko Epson Color Ink Jet Printers
WWW=		https://download.ebz.epson.net/dsc/search/01/search/?OSC=LX

# License does not allow redistribution
LICENSE=		EPSON LGPL21
LICENSE_COMB=		multi
LICENSE_NAME_EPSON=	SEIKO EPSON CORPORATION SOFTWARE LICENSE AGREEMENT
LICENSE_FILE_EPSON=	${WRKSRC}/opt/${PORTNAME}/doc/COPYING.EPSON
LICENSE_FILE_LGPL21=	${WRKSRC}/opt/${PORTNAME}/doc/COPYING.LIB
LICENSE_PERMS_EPSON=	none

RUN_DEPENDS=	${LOCALBASE}/libexec/cups/filter/gstoraster:print/cups-filters

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE} \
		PORTNAME=${PORTNAME}
USES=		linux
USE_LINUX=	cups-libs imageformats-libs

.include <bsd.port.options.mk>

.if ${ARCH} == i386
PLIST_SUB+=	LIBDIR=lib
.elif ${ARCH} == amd64
PLIST_SUB+=	LIBDIR=lib64
.endif

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/opt/${PORTNAME}/ppds/Epson/*.ppd.gz

post-patch:
	@${SED} -i '' '/^\*cupsFilter:/s,/opt/,${LINUXBASE}&,' \
		${WRKSRC}/opt/${PORTNAME}/ppds/Epson/*.ppd

do-install:
	${MKDIR} ${STAGEDIR}${LINUXBASE}
	${CP} -Rp ${WRKSRC}/opt ${STAGEDIR}${LINUXBASE}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cups/model/
	${LN} -sf ${LINUXBASE}/opt/${PORTNAME}/ppds/Epson ${STAGEDIR}${PREFIX}/share/cups/model/Epson-201207w

.include <bsd.port.mk>
