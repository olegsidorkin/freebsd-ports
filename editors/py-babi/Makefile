PORTNAME=	babi
DISTVERSION=	1.6.1
CATEGORIES=	editors python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Text Editor written in Python
WWW=		https://github.com/asottile/babi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babi_grammars>=0:devel/py-babi_grammars@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}identify>=0:devel/py-identify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}onigurumacffi>=0.0.18:devel/py-onigurumacffi@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babi_grammars>=0:devel/py-babi_grammars@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}identify>=0:devel/py-identify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}onigurumacffi>=0.0.18:devel/py-onigurumacffi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils flavors

NO_ARCH=	yes

.include <bsd.port.mk>
