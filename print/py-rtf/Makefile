PORTNAME=	rtf
PORTVERSION=	0.45
PORTREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyRTF-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to create RTF documents using the Python language
WWW=		https://pyrtf.sourceforge.net/

LICENSE=	GPLv1

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
