PORTNAME=	openyahtzee
PORTVERSION=	1.9.3
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Open%20Yahtzee/Open%20Yahtzee%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-featured classic dice game Yahtzee
WWW=		https://www.openyahtzee.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/scoped_ptr.hpp:devel/boost-libs

USES=		compiler:c++11-lib localbase:ldflags tar:xz
USE_CXXSTD=	c++11
USE_WX=		3.2
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

DESKTOP_ENTRIES="Open Yahtzee" "" "${LOCALBASE}/share/pixmaps/openyahtzee.png" \
		"${PORTNAME}" "Game;" false

PLIST_FILES=	bin/openyahtzee \
		share/pixmaps/openyahtzee.png \
		share/man/man6/openyahtzee.6.gz

.include <bsd.port.mk>
