PORTNAME=	jcalendar
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	java misc
MASTER_SITES=	http://www.toedter.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Date Chooser
WWW=		https://www.toedter.com/en/jcalendar/

USES=		java:ant,run zip
JAVA_VERSION=	8

WRKSRC=		${WRKDIR}/src
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		%%JAVAJARDIR%%/looks-2.0.1.jar

###
# has a potential conflict with devel/looks, both install a looksXXX.jar
###

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-build:
	cd ${WRKDIR}/build && \
		${JAR} cmf ${WRKSRC}/${PORTNAME}.manifest \
			${WRKDIR}/build/${PORTNAME}.jar *

do-install:
	${INSTALL_DATA} ${WRKDIR}/build/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKDIR}/lib/looks-2.0.1.jar ${STAGEDIR}${JAVAJARDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
