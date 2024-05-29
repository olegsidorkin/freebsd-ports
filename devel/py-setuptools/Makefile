PORTNAME=	setuptools
DISTVERSION=	70.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

# note: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
MAINTAINER=	python@FreeBSD.org
COMMENT=	Python packages installer
WWW=		https://pypi.org/project/setuptools/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	python
USE_PYTHON=	allflavors autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.options.mk>

.if ${FLAVOR} != ${FLAVORS:[1]}
SUB_FILES+=	pkg-message
SUB_LIST+=	PYTHON_VER=${PYTHON_VER}
.endif

# These create dependency loops in redports/poudriere, because setuptools
# is currently an explicit BUILD & RUN dependency in Uses/python.mk.
#TEST_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}
# pkg install -y py38-pytest py38-mock py38-pytest-fixture-config py38-pytest-virtualenv py38-paver

do-test:
	cd ${WRKSRC} && \
		${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
