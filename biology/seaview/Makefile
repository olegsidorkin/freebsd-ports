PORTNAME=	seaview
PORTVERSION=	5.0.5
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://pbil.univ-lyon1.fr/pub/mol_phylogeny/seaview/archive/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Multiple DNA/protein sequence alignment editor
WWW=		https://doua.prabi.fr/software/seaview

LICENSE=	GPLv3

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png

PORTSCOUT=	skipv:4.6.1.3
WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake jpeg xorg
USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender

MAKE_ENV=	HELPFILE='-DDEFAULT_HELPFILE=\"${DATADIR}/seaview.html\"' \
		PHYMLNAME='-DPHYMLNAME=\"phyml\"' \
		IFLTK='-I${LOCALBASE}/include' \
		LFLTK='-L${LOCALBASE}/lib' \
		USE_XFT='-DUSE_XFT' \
		OPT="${CFLAGS}"
ALL_TARGET=	${PORTNAME}

DESKTOP_ENTRIES="SeaView" "" "${PREFIX}/share/pixmaps/seaview.xpm" "seaview" \
		"Biology;Science;" true

post-patch:
# Ignore FLTK patch version because >=10 breaks the comparison logic
	${REINPLACE_CMD} -e 's, + FL_PATCH_VERSION,,' \
		${WRKSRC}/FL/Fl_SVG_Image.cxx
	${REINPLACE_CMD} -e \
		's|^\(CC\) |#\1 | ; s|-ldl || ; \
		s|^\(CXX\) |#\1 |' ${WRKSRC}/Makefile
	${ECHO_CMD} 'boolean javarun;' >> ${WRKSRC}/csrc/phylip.c

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} seaview \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} seaview.1 \
		${STAGEDIR}${PREFIX}/share/man/man1)
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} seaview.html \
		${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} seaview.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
