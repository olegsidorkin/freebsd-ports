PORTNAME=	uuid
PORTVERSION=	1.6.2
PORTREVISION=	10
CATEGORIES=	misc devel
MASTER_SITES=	OSSP/lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	vd@FreeBSD.org
COMMENT=	ISO-C API and CLI for generating Universally Unique Identifiers
WWW=		http://www.ossp.org/pkg/lib/uuid/

LICENSE=	MIT
.if defined(SLAVEPORT) && ${SLAVEPORT}=="perl"
LICENSE_FILE=	${WRKSRC}/../README
.else
LICENSE_FILE=	${WRKSRC}/README
.endif

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USES+=		libtool pathfix
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-cxx \
		--includedir=${PREFIX}/include/ossp

.if defined(SLAVEPORT) && ${SLAVEPORT}=="perl"
PKGNAMEPREFIX=	p5-OSSP-
.else
TEST_TARGET=	check
.endif

pre-patch:
### Fixes lib conflicts with misc/e2fsprogs-libuuid ###
	@${REINPLACE_CMD} 's/libuuid.la/libossp-uuid.la/ ; s/libuuid++.la/libossp-uuid++.la/' \
		${WRKDIR}/${DISTNAME}/Makefile.in

.include <bsd.port.mk>
