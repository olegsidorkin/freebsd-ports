PORTNAME=	pikchr
PORTVERSION=	0.0.s20240731
CATEGORIES=	graphics textproc
MASTER_SITES=	https://pikchr.org/home/tarball/${CHECKIN}/
DISTNAME=	${PORTNAME}-${CHECKIN}${ARCHIVE_SUFX}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	PIC-like markup language for diagrams
WWW=		https://pikchr.org

LICENSE=	BSD0CLAUSE

CHECKIN=	1e14a4118c
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
