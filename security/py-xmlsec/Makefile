PORTNAME=	xmlsec
DISTVERSION=	1.3.14
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python bindings for XML Security Library
WWW=		https://github.com/mehcode/python-xmlsec/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=3.8.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkgconfig>=0:devel/py-pkgconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libxmlsec1-openssl.so:security/xmlsec1
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR}

USES=		gnome pkgconfig python
USE_GNOME=	libxml2 libxslt
USE_PYTHON=	autoplist distutils flavors pytest

INSTALL_TARGET=	install-strip

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/xmlsec*.so

.include <bsd.port.mk>
