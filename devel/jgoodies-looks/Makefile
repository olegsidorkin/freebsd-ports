PORTNAME=	jgoodies-looks
DISTVERSION=	2.7.0
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/com/jgoodies/${PORTNAME}/${DISTVERSION}/
DISTFILES=	${JARFILE} ${JAVADOCFILE} ${JAVASRCFILE}
EXTRACT_ONLY=	# nothing to extract

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Improved appearance for Java Swing applications
WWW=		http://www.jgoodies.com

LICENSE=	BSD3CLAUSE

USES=		java
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

JARFILE=	${PORTNAME}-${PORTVERSION}.jar

PLIST_FILES=	${JAVAJARDIR}/${JARFILE} \
		${JAVAJARDIR}/looks.jar

OPTIONS_DEFINE=	DOCS SRC
SRC_DESC=	Install source jarfile
DOCS_VARS=	JAVADOCFILE=${PORTNAME}-${PORTVERSION}-javadoc.jar
SRC_VARS=	JAVASRCFILE=${PORTNAME}-${PORTVERSION}-sources.jar

DOCS_PLIST_FILES=	${JAVAJARDIR}/${JAVADOCFILE}
SRC_PLIST_FILES=	${JAVAJARDIR}/${JAVASRCFILE}

do-install:
	${INSTALL_DATA} ${DISTDIR}/${JARFILE} ${STAGEDIR}${JAVAJARDIR}
	${LN} -sf ${JARFILE} ${STAGEDIR}${JAVAJARDIR}/looks.jar

do-install-DOCS-on:
	${INSTALL_DATA} ${DISTDIR}/${JAVADOCFILE} ${STAGEDIR}${JAVAJARDIR}

do-install-SRC-on:
	${INSTALL_DATA} ${DISTDIR}/${JAVASRCFILE} ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
