PORTNAME=	swank-clojure
PORTVERSION=	1.2.1
CATEGORIES=	devel lisp java
MASTER_SITES=	LOCAL/olgeni

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Swank/SLIME support for Clojure
WWW=		https://github.com/technomancy/swank-clojure

USES=		java
USE_GITHUB=	yes
GH_ACCOUNT=	technomancy

PLIST_FILES=	%%JAVAJARDIR%%/swank-clojure-1.2.1.jar

do-build:
	@cd ${WRKSRC} && ${JAR} cf ${PORTNAME}-${PORTVERSION}.jar -C src swank

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
