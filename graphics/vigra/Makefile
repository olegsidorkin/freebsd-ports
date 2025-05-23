PORTNAME=	vigra
DISTVERSIONPREFIX=v
DISTVERSION=	1.12.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VIGRA stands for "Vision with Generic Algorithms"
WWW=		https://ukoethe.github.io/vigra/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libImath.so:math/Imath \
		libsz.so:science/libaec

USES=		cmake compiler:c++14-lang localbase python:run shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	ukoethe
GH_TAGNAME=	8acd73a
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include/Imath

CMAKE_ARGS=	-DDEPENDENCY_SEARCH_PREFIX:PATH=${LOCALBASE} \
		-DDOCINSTALL:PATH=${DOCSDIR_REL}
SHEBANG_FILES=	config/vigra-config.in

OPTIONS_DEFINE=		HDF5 OPENEXR NUMPY DOCS FFTW
OPTIONS_DEFAULT=	HDF5 OPENEXR FFTW ${OPTIONS_GROUP_IMAGEFORMATS}
OPTIONS_GROUP=		IMAGEFORMATS
OPTIONS_GROUP_IMAGEFORMATS=	PNG JPEG TIFF
OPTIONS_SUB=		yes

HDF5_CFLAGS=		-DH5_USE_110_API=1
HDF5_CMAKE_BOOL=	WITH_HDF5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5

OPENEXR_CMAKE_BOOL=	WITH_OPENEXR
OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr

NUMPY_DESC=		NumPy mathematical computing (USE Fortran/GCC47+)
NUMPY_CMAKE_BOOL=	WITH_VIGRANUMPY
NUMPY_USES=		compiler:gcc-c++11-lib python:build
NUMPY_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
			${PYNUMPY}
NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
			${PYNUMPY}
NUMPY_LIB_DEPENDS=	${PY_BOOST}
# On FreeBSD < 11 libc++ lacks support for sized delete operators.
# GCC dropped the builtin version of these operators in 6+ by
# defaulting to gnu++14. Force c++11 instead.
# For a more detailed discussion see:
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=219484
NUMPY_CXXFLAGS=		-std=gnu++11

PNG_CMAKE_BOOL=		WITH_PNG
PNG_LIB_DEPENDS=	libpng.so:graphics/png

JPEG_CMAKE_BOOL=	WITH_JPEG
JPEG_USES=		jpeg

TIFF_CMAKE_BOOL=	WITH_TIFF
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff

FFTW_CMAKE_BOOL=	WITH_FFTW
FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3 \
			libfftw3f.so:math/fftw3-float

post-package-NUMPY-on:
	@${ECHO} ""
	@${ECHO} "* BEWARE!"
	@${ECHO} "* Using py-NumPY implies Fortran and GCC 4.7+ as hard dependencies"
	@${ECHO} "* and require all ports, depending on vigra, to set USE_GCC=yes"
	@${ECHO} ""

.include <bsd.port.mk>
