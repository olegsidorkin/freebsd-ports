PORTNAME=	copyq
DISTVERSION=	10.0.0
CATEGORIES=	deskutils
MASTER_SITES=	https://github.com/hluk/CopyQ/releases/download/v${DISTVERSION}/
DISTNAME=	Copyq-${DISTVERSION}

PATCH_SITES=	https://github.com/hluk/CopyQ/commit/
PATCHFILES+=	f08c0d46a239362c5d3525ef9c3ba943bb00f734.patch:-p1 # Fix build with Qt >= 6.9.0

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Qt6 based clipboard manager
WWW=		https://github.com/hluk/CopyQ

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake gl kde:6 pkgconfig qt:6 xorg
USE_GL=		opengl
USE_KDE=	notifications ecm:build statusnotifieritem
USE_QT=		base declarative svg wayland translations:build
USE_XORG=	ice sm x11 xext xfixes xtst

CMAKE_ARGS=	-DWITH_QT6:BOOL=TRUE

PORTSCOUT=	limit:^d\.d\.

OPTIONS_DEFINE=		PLUGINS
OPTIONS_DEFAULT=	PLUGINS
OPTIONS_SUB=		yes

PLUGINS_CMAKE_BOOL=	WITH_PLUGINS

.include <bsd.port.mk>
