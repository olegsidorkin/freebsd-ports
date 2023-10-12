PORTNAME=	webrtc-noise-gain
PORTVERSION=	1.2.5
DISTVERSIONPREFIX=	v
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	osidorkin@gmail.com
COMMENT=	Tiny wrapper around webrtc-audio-processing
WWW=		https://github.com/rhasspy/webrtc-noise-gain

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517
USE_GITHUB=	yes
GH_ACCOUNT=	rhasspy
GH_PROJECT=	webrtc-noise-gain

.include <bsd.port.mk>
