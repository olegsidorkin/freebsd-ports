PORTNAME=	macopix
PORTVERSION=	1.7.4
PORTREVISION=	17
CATEGORIES=	games
MASTER_SITES=	http://rosegray.sakura.ne.jp/macopix/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LICENSE_DISTFILES_DATA}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window sitter for X11
WWW=		http://rosegray.sakura.ne.jp/macopix/index-e.html

LICENSE=	GPLv2+ DATA
LICENSE_COMB=	multi
LICENSE_NAME_DATA=	Commercial character data
LICENSE_TEXT_DATA=	contains commercial character data
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_DISTFILES_DATA=	\
		macopix-mascot-comic_party-euc-ja-1.02.tar.gz \
		macopix-mascot-cosmos-euc-ja-1.02.tar.gz \
		macopix-mascot-kanon-euc-ja-1.02.tar.gz \
		macopix-mascot-mizuiro-euc-ja-1.02.tar.gz \
		macopix-mascot-one-euc-ja-1.02.tar.gz \
		macopix-mascot-pia2-euc-ja-1.02.tar.gz \
		macopix-mascot-triangle_heart-euc-ja-1.02.tar.gz \
		macopix-mascot-tsukihime-euc-ja-1.02.tar.gz \
		macopix-mascot-marimite-euc-ja-2.20.tar.gz \
		macopix-mascot-HxB-euc-ja-0.30.tar.gz
LICENSE_PERMS_DATA=	auto-accept

BROKEN_armv6=		dumps core: Assertion failed: (!NodePtr->isKnownSentinel()), function operator*, file ilist_iterator.h
BROKEN_armv7=		dumps core: Assertion failed: (!NodePtr->isKnownSentinel()), function operator*, file ilist_iterator.h

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		gettext gmake gnome iconv jpeg libtool pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf gtk20
USE_XORG=	x11
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CFLAGS+=	-fcommon
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11 ${ICONV_LIB}

OPTIONS_DEFINE=	DOCS GNUTLS

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ON=	--with-gnutls
GNUTLS_USES_OFF=	ssl

post-patch:
	@${REINPLACE_CMD} -e 's/_MAIL } MailStatus/_MAIL } MailStatus2/' ${WRKSRC}/src/main.h

post-install:
# install mascot file
	@${MKDIR} ${STAGEDIR}${DATADIR}/pixmap
	cd ${WRKDIR}/macopix-mascot-comic_party-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.comipa.jp
	cd ${WRKDIR}/macopix-mascot-cosmos-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.cosmos.jp
	cd ${WRKDIR}/macopix-mascot-kanon-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.kanon.jp
	cd ${WRKDIR}/macopix-mascot-mizuiro-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.mizuiro.jp
	cd ${WRKDIR}/macopix-mascot-one-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.one.jp
	cd ${WRKDIR}/macopix-mascot-pia2-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.pia2.jp
	cd ${WRKDIR}/macopix-mascot-triangle_heart-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.trh.jp
	cd ${WRKDIR}/macopix-mascot-tsukihime-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.tsuki.jp
	cd ${WRKDIR}/macopix-mascot-marimite-euc-ja-2.20 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.marimite.jp
	cd ${WRKDIR}/macopix-mascot-HxB-euc-ja-0.30 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.HxB.jp
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} NKR.README.ja README README.ja \
		${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
