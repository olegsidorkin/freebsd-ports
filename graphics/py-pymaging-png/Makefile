PORTNAME=	pymaging-png
PORTREVISION=	2
PORTVERSION=	g20130727
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	PNG support for pymaging
WWW=		https://pymaging.rtfd.org

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymaging>=g20130908:graphics/py-pymaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	ojii
GH_TAGNAME=	83d85c4

NO_ARCH=	yes

.include <bsd.port.mk>
