PORTNAME=	isal
PORTVERSION=	1.8.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	osidorkin@FreeBSD.org
COMMENT=	Bindings for the ISA-L library for compression and decompression
WWW=		https://github.com/pycompression/python-isal

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nasm:devel/nasm \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libisal.so:devel/isa-l

USES=		gmake python:3.10+
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
