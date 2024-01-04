# Created by: Oleg Sidorkin <osidorkin@gmail.com>>

PORTNAME=	plasma-Luna2
PORTVERSION=	2.1.2
CATEGORIES=	astro

MAINTAINER=	osidorkin@gmail.com
COMMENT=	Plasmoid displaying the current moon phase

LICENSE=	GPLv3

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz

GH_ACCOUNT=	wwjjbb
GH_PROJECT=	Luna-II
GH_TAGNAME=	v${DISTVERSION}

USE_GITHUB=	yes
USE_KDE=	ecm_build plasma-framework
USE_QT=		buildtools_build qmake_build

NO_ARCH=	yes

post-extract:
	${RM} ${WRKSRC}/package/Changelog
	${RM} ${WRKSRC}/package/LICENSE.GPL2
	${RM} ${WRKSRC}/package/LICENSE.GPL3
	${RM} ${WRKSRC}/package/README
	${RM} ${WRKSRC}/package/README_TRANSLATIONS.txt
	${MV} ${WRKSRC}/package/contents/po ${WRKSRC}/po

post-install:
	(cd ${WRKSRC}/po && ${COPYTREE_SHARE} "locale" ${STAGEDIR}${PREFIX}/share)

.include <bsd.port.mk>
