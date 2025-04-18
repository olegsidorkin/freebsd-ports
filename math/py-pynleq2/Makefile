PORTNAME=	pynleq2
DISTVERSION=	0.0.2
PORTREVISION=	9
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for NLEQ2 algorithm's fortran implementation
WWW=		https://github.com/bjodah/pynleq2

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}

USES=		fortran python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	nodefault
GH_TUPLE=	PySCeS:pysces:0.9.8:fortran

FORTRAN_FILES=	linalg_nleq2.f nleq2.f wnorm.f zibconst.f zibmon.f zibsec.f

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/setup.py

pre-build: # compile fortran files into a static library because distutils fails while doing this
	@${MKDIR} ${WRKDIR}/.fbuild && \
		cd ${WRKDIR}/.fbuild && \
		${FC} -c ${CFLAGS} -fPIC ${FORTRAN_FILES:C,^,${WRKSRC_fortran}/pysces/nleq2/,} && \
		${AR} -qc libff.a ${FORTRAN_FILES:S/.f/.o/}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/nleq2*.so

.include <bsd.port.mk>
