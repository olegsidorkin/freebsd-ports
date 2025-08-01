PORTNAME=	numpy
PORTVERSION=	1.26.4
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI \
		https://numpy.org/doc/1.26/:doc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	numpy-${PORTVERSION}${EXTRACT_SUFX} \
		numpy-html.zip:doc
DIST_SUBDIR=	numpy-${PORTVERSION:R}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	The New Numeric Extension to Python
WWW=		https://www.numpy.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython3>=0:lang/cython3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}meson-python>0:devel/meson-python@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=6.2.5:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=6.24.1:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.2.0:devel/py-typing-extensions@${PY_FLAVOR}
USES=		compiler:c11 cpe fortran python:3.9+ shebangfix
USE_PYTHON=	allflavors autoplist concurrent pep517

GCCLIBDIR_CMDS=	${FC} -print-file-name=libgfortran.so | ${SED} -e s/libgfortran.so//
LDFLAGS+=	-s
PYDISTUTILS_BUILDARGS=		--fcompiler=gnu95
PYDISTUTILS_CONFIGUREARGS=	--fcompiler=gnu95
SHEBANG_FILES=	${WRKSRC}/numpy/testing/setup.py \
		${WRKSRC}/numpy/testing/print_coercion_tables.py \
		${WRKSRC}/numpy/f2py/rules.py \
		${WRKSRC}/numpy/f2py/crackfortran.py \
		${WRKSRC}/numpy/f2py/f2py2e.py

PIE_UNSAFE=	yes

PORTDOCS=	*

PORTSCOUT=	limit:^1\.

OPTIONS_DEFINE=		DOCS SUITESPARSE
OPTIONS_SINGLE=		BLASLIB
OPTIONS_SINGLE_BLASLIB=	ATLAS NETLIB OPENBLAS
OPTIONS_DEFAULT=	OPENBLAS SUITESPARSE
SUITESPARSE_DESC=	Use AMD and UMFPACK in SuiteSparse

ATLAS_USES=		blaslapack:atlas
ATLAS_VARS=		BLASLIBS="ptf77blas, ptcblas" BLASNAME=atlas LAPACKLIBS=alapack LIBRARIES=atlas_libs
NETLIB_LIB_DEPENDS=	libcblas.so:math/cblas
NETLIB_USES=		blaslapack:netlib
NETLIB_VARS=		BLASLIBS="blas, cblas" BLASNAME=atlas LAPACKLIBS=lapack LIBRARIES=atlas_libs
OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_VARS=		BLASLIBS="openblas, gfortran" BLASNAME=openblas LAPACKLIBS="openblas, gfortran" LIBRARIES=libraries
SUITESPARSE_LIB_DEPENDS=libumfpack.so:math/suitesparse-umfpack

post-extract:
	@${TOUCH} ${WRKSRC}/numpy/f2py/tests/src/temp
	@${TOUCH} ${WRKSRC}/numpy/random/_examples/temp
	@${TOUCH} ${WRKSRC}/numpy/core/tests/examples/temp

pre-configure-SUITESPARSE-off:
	@${REINPLACE_CMD} -e 's|:%%LOCALBASE%%/include/suitesparse||' ${WRKSRC}/site.cfg

pre-configure:
	@${REINPLACE_CMD} -e 's|%%FC%%|${FC}|' ${WRKSRC}/numpy/distutils/fcompiler/gnu.py
	@${CP} ${FILESDIR}/site.cfg ${WRKSRC}/site.cfg
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%BLASLIBS%%|${BLASLIBS}|; s|%%BLASNAME%%|${BLASNAME}|' \
		-e 's|%%LAPACKLIBS%%|${LAPACKLIBS}|; s|%%LIBRARIES%%|${LIBRARIES}|' \
			${WRKSRC}/site.cfg
	@${REINPLACE_CMD} -e "s|%%GCCLIBDIR%%|$$(${GCCLIBDIR_CMDS})|" ${WRKSRC}/site.cfg ${WRKSRC}/numpy/distutils/system_info.py

do-configure:

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' | ${XARGS} ${STRIP_CMD}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${UNZIP_NATIVE_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/numpy-html.zip -d ${STAGEDIR}${DOCSDIR}
	@${RM} ${STAGEDIR}${DOCSDIR}/.buildinfo

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} runtests.py

.include <bsd.port.mk>
