PORTNAME=	blitz
DISTVERSION=	1.0.2
PORTREVISION=	4
CATEGORIES=	devel science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Blitz++ Multi-Dimensional Array Library for C++
WWW=		https://github.com/blitzpp/blitz

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:noninja localbase python:build
USE_GITHUB=	yes
GH_ACCOUNT=	blitzpp
USE_LDCONFIG=	yes
TEST_TARGET=	check-testsuite
#INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--enable-shared
MAKE_ARGS=	CXXFLAGS="${CXXFLAGS}" FREEBSD_PYTHON_CMD=${PYTHON_CMD}

OPTIONS_DEFINE=		APAD FORTRAN SERIALIZATION THREADSAFE # TBB
APAD_DESC=		Pad all lowest-rank lengths to nearest larger SIMD width
SERIALIZATION_DESC=	Enable serialization support using Boost::Serialization
TBB_DESC=		Use Intel Threading Building Blocks atomic types
THREADSAFE_DESC=	Enable thread-safety features

APAD_CONFIGURE_ENABLE=		array-length-padding
FORTRAN_CONFIGURE_ENABLE=	fortran
FORTRAN_USES=			fortran
SERIALIZATION_CONFIGURE_ENABLE=	serialization
SERIALIZATION_BUILD_DEPENDS=	${LOCALBASE}/include/boost/mpi.hpp:devel/boost-libs
TBB_CONFIGURE_ON=		--with-tbb # TBB_CONFIGURE_WITH=tbb doesn't work: https://github.com/blitzpp/blitz/issues/20
TBB_BUILD_DEPENDS=		${LOCALBASE}/include/tbb/atomic.h:devel/tbb
TBB_BROKEN=			oneTBB doesn't provide tbb/atomic.h any more, see https://github.com/blitzpp/blitz/issues/169
THREADSAFE_CONFIGURE_ENABLE=	threadsafe

post-install:
	@${RM} -r ${STAGEDIR}${DOCSDIR}* # https://github.com/blitzpp/blitz/issues/21

.include <bsd.port.mk>
