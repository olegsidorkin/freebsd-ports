PORTNAME=	ccrtp
PORTVERSION=	2.1.2
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Implementation of the real-time transport protocol
WWW=		https://www.gnu.org/software/ccrtp/

DEPRECATED=	No active development in years and no users in tree
EXPIRATION_DATE=2025-03-16

LIB_DEPENDS=	libcommoncpp.so:devel/ucommon \
		libgcrypt.so:security/libgcrypt

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib gmake gettext libtool localbase iconv pkgconfig
USE_LDCONFIG=	yes

INFO=		ccrtp

post-patch:
	@cd ${WRKSRC}/src && \
		${FIND} * -type f -exec ${REINPLACE_CMD} -i "" -e "s|<malloc.h>|<stdlib.h>|g" {} \;

post-configure:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e 's|-l-pthread|-pthread|g'

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libccrtp.so.3.0.1

.include <bsd.port.mk>
