PORTNAME=	scipy
DISTVERSION=	1.16.2
PORTEPOCH=	1
CATEGORIES=	science python
MASTER_SITES=	https://docs.scipy.org/doc/scipy-${DISTVERSION}/:doc \
		PYPI:source \
		SF:source
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source \
		scipy-html-${DISTVERSION}.zip:doc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Scientific tools for Python
WWW=		https://www.scipy.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}meson-python>0:devel/meson-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pythran>=0:devel/py-pythran@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=60:devel/py-setuptools@${PY_FLAVOR} \
		cmake:devel/cmake-core \
		unzip>0:archivers/unzip \
		xsimd>=8.1:devel/xsimd
LIB_DEPENDS=	libblas.so:math/blas \
		libopenblas.so:math/openblas \
		libqhull_r.so:math/qhull
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gmpy2>0:math/py-gmpy2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mpmath>0:math/py-mpmath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pooch>0:devel/py-pooch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-umfpack>0:math/py-scikit-umfpack@${PY_FLAVOR}

USES=		compiler:c++17-lang cpe fortran localbase pkgconfig python:3.10-3.14 shebangfix
USE_PYTHON=	autoplist concurrent cython pep517

PYDISTUTILS_BUILDARGS=	--fcompiler=gnu95
PYDISTUTILS_CONFIGUREARGS=	--fcompiler=gnu95

PIE_UNSAFE=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
PEP517_BUILD_CONFIG_SETTING=	-Cbuild-dir=build -Csetup-args="-Duse-system-libraries=qhull"

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/scipy/ -name '*.so' | ${XARGS} ${STRIP_CMD}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${UNZIP_CMD} -d ${STAGEDIR}${DOCSDIR} ${DISTDIR}/scipy-html-${DISTVERSION}.zip
	@${RM} ${STAGEDIR}${DOCSDIR}/.buildinfo

do-test:
	@cd ${WRKSRC} && ${TOUCH} .coveragerc && ${PYTHON_CMD} runtests.py

.include <bsd.port.mk>
