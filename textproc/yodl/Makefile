PORTNAME=	yodl
DISTVERSION=	4.01.00
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Easy to use but powerful document formatting/preparation language
WWW=		https://fbb-git.gitlab.io/yodl/

LICENSE=	GPLv3

RUN_DEPENDS=	bash:shells/bash \
		getopt>=0:misc/getopt
BUILD_DEPENDS=	icmake:devel/icmake \
		bash:shells/bash \
		gsed:textproc/gsed

USES=		cpe perl5 shebangfix compiler:c++14-lang
CPE_VENDOR=	${PORTNAME}_project
USE_PERL5=	build
USE_GITLAB=	yes
GL_ACCOUNT=	fbb-git
GL_TAGNAME=	1a4149b41eaa8a89f4a1ec2b7071725446b1d1cd

SHEBANG_LANG=	icmake
icmake_OLD_CMD=	/usr/bin/icmake
icmake_CMD=	${LOCALBASE}/bin/icmake

SHEBANG_FILES=	${WRKSRC}/macros/rawmacros/create \
		${WRKSRC}/macros/rawmacros/keepdiff \
		${WRKSRC}/macros/rawmacros/makeyoin \
		${WRKSRC}/macros/rawmacros/repairs \
		${WRKSRC}/macros/rawmacros/separator \
		${WRKSRC}/macros/rawmacros/separator.pl \
		${WRKSRC}/macros/rawmacros/startdoc \
		${WRKSRC}/macros/rawmacros/startdoc.pl \
		${WRKSRC}/contrib/build.pl \
		${WRKSRC}/scripts/configreplacements \
		${WRKSRC}/scripts/macroseparator.pl \
		${WRKSRC}/scripts/stdmacros \
		${WRKSRC}/scripts/yodl2whatever.in \
		${WRKSRC}/build

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

WRKSRC_SUBDIR=	${PORTNAME}

OPTIONS_DEFINE=	DOCS

DOCS_USES=	tex
DOCS_USE=	TEX=latex:build,dvipsk:build

post-patch:
	@${REINPLACE_CMD} -e 's|"/usr"|"${PREFIX}"| ; \
		s|"/share/yodl"|"/share/${PORTNAME}-${PORTVERSION}"| ; \
		s|"/share/doc/yodl"|"/share/doc/${PORTNAME}-${PORTVERSION}"| ; \
		s|"/share/doc/yodl-doc"|"/share/doc/${PORTNAME}-${PORTVERSION}/doc"| ; \
		s|"gcc"|"${CC}"| ; \
		s|"g++"|"${CXX}"|' \
		${WRKSRC}/INSTALL.im
	@${REINPLACE_CMD} -e 's|yodlconverters.1|yodlconverters.1.gz| ; \
		s|".1"|".1.gz"|' \
		${WRKSRC}/icmake/install
	@${REINPLACE_CMD} -e 's|#!/usr/bin/icmake|#!${LOCALBASE}/bin/icmake| ; \
		s|"-O2 -Wall"|"-Wall ${CFLAGS}"|' \
		${WRKSRC}/build
	@${REINPLACE_CMD} -e 's|sed |${LOCALBASE}/bin/gsed | ; \
		s|getopt |${LOCALBASE}/bin/getopt |' \
		${WRKSRC}/scripts/configreplacements \
		${WRKSRC}/scripts/yodl2whatever.in \
		${WRKSRC}/scripts/yodlstriproff \
		${WRKSRC}/macros/rawmacros/repairs

do-build:
	@cd ${WRKSRC} && ./build programs strip
	@cd ${WRKSRC} && ./build macros
	@cd ${WRKSRC} && ./build man

do-build-DOCS-on:
	@cd ${WRKSRC} && ./build manual

do-install:
	@cd ${WRKSRC} && ./build install programs ${STAGEDIR}
	@cd ${WRKSRC} && ./build install macros ${STAGEDIR}
	@cd ${WRKSRC} && ./build install man ${STAGEDIR}

do-install-DOCS-on:
	@cd ${WRKSRC} && ./build install manual ${STAGEDIR}
	@cd ${WRKSRC} && ./build install docs ${STAGEDIR}

.include <bsd.port.mk>
