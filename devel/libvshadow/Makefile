PORTNAME=	libvshadow
PORTVERSION=	20240504
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libyal/libvshadow/releases/download/${PORTVERSION}/ \
		LOCAL/antoine
DISTNAME=	${PORTNAME}-alpha-${PORTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library to support the Volume Service Snapshot (VSS) format
WWW=		https://github.com/libyal/libvshadow

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fuse libtool pathfix pkgconfig python
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-python
CONFIGURE_ENV=	PYTHON_CONFIG=${PYTHON_CMD}-config
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
