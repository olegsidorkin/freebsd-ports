PORTNAME=	pdftk
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.3
PORTREVISION=	1
CATEGORIES=	print java

MAINTAINER=	andreas@bilke.org
COMMENT=	Simple tool for doing everyday things with PDF documents
WWW=		https://gitlab.com/pdftk-java/pdftk

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${JAVALIBDIR}/commons-lang3.jar:java/apache-commons-lang3 \
	${JAVALIBDIR}/bcprov.jar:java/bouncycastle
RUN_DEPENDS=	${JAVALIBDIR}/commons-lang3.jar:java/apache-commons-lang3 \
	${JAVALIBDIR}/bcprov.jar:java/bouncycastle

USES=		java:ant,run
USE_GITLAB=	yes
GL_ACCOUNT=	pdftk-java
GL_TAGNAME=	e4292c8f1bd2580a44d3cbf3570a4505bd3a74b6

ALL_TARGET=	jar
NO_ARCH=	yes
SUB_FILES=	pdftk
SUB_LIST=	CLASSPATH="${_CLASSPATH:ts:}" \
		JAVA="${JAVA}"
PLIST_FILES=	${JAVAJARDIR}/pdftk.jar \
		bin/pdftk \
		share/man/man1/pdftk.1.gz

_CLASSPATH=	${JAVAJARDIR}/commons-lang3.jar \
		${JAVAJARDIR}/bcprov.jar \
		${JAVAJARDIR}/pdftk.jar

post-extract:
	@${MKDIR} ${WRKSRC}/lib
	@${LN} -sf ${JAVAJARDIR}/commons-lang3.jar ${WRKSRC}/lib
	@${LN} -sf ${JAVAJARDIR}/bcprov.jar ${WRKSRC}/lib

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pdftk \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/build/jar/pdftk.jar \
		${STAGEDIR}${JAVAJARDIR}
	${INSTALL_MAN} ${WRKSRC}/pdftk.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
