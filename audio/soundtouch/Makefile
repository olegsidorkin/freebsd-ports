PORTNAME=	soundtouch
DISTVERSION=	2.3.3
CATEGORIES=	audio
MASTER_SITES=	https://www.surina.net/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Open-source audio processing library
WWW=		https://www.surina.net/soundtouch/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.TXT

USES=		cmake compiler:c++17-lang cpe
CPE_VENDOR=	surina
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
CFLAGS_i386=	-DSOUNDTOUCH_DISABLE_X86_OPTIMIZATIONS

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=			INTEGER_SAMPLES OPTIMIZED_CFLAGS
OPTIONS_DEFINE_aarch64=		NEON OPENMP
OPTIONS_DEFINE_amd64=		OPENMP
OPTIONS_DEFINE_armv7=		NEON
OPTIONS_DEFINE_i386=		OPENMP
OPTIONS_DEFINE_powerpc64=	OPENMP
OPTIONS_DEFINE_powerpc64le=	OPENMP
OPTIONS_DEFINE_riscv64=		OPENMP
OPTIONS_DEFAULT=		${MACHINE_CPU:Msoftfp:C/.+/INTEGER_SAMPLES/}
OPTIONS_DEFAULT_aarch64=	NEON OPENMP OPTIMIZED_CFLAGS
OPTIONS_DEFAULT_amd64=		OPENMP OPTIMIZED_CFLAGS
OPTIONS_DEFAULT_powerpc64=	OPENMP OPTIMIZED_CFLAGS
OPTIONS_DEFAULT_powerpc64le=	OPENMP OPTIMIZED_CFLAGS
OPTIONS_DEFAULT_riscv64=	OPENMP OPTIMIZED_CFLAGS

INTEGER_SAMPLES_DESC=	Use integer sample format
NEON_DESC=		Use NEON instructions

INTEGER_SAMPLES_CMAKE_BOOL=	INTEGER_SAMPLES
NEON_CMAKE_BOOL=		NEON
OPENMP_CMAKE_BOOL=		OPENMP
OPTIMIZED_CFLAGS_CFLAGS=	-Ofast

.include <bsd.port.mk>
