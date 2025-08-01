PORTNAME=	libao
PORTVERSION=	1.2.0
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/ao/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Portable audio output library
WWW=		https://www.xiph.org/ao/

LICENSE=	GPLv2

USES=		cpe libtool pkgconfig
CPE_VENDOR=	xiph
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static \
		--disable-alsa \
		--disable-arts \
		--disable-esd
INSTALL_TARGET=	install-strip

# do not install
MAKE_ARGS=	ckport_DATA=""

OPTIONS_DEFINE=	DOCS NAS PULSEAUDIO SNDIO
OPTIONS_SUB=	yes

NAS_LIB_DEPENDS=libaudio.so:audio/nas
NAS_CONFIGURE_ENABLE=	nas

PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_USES=	localbase

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/libao.conf|${PREFIX}&|' \
		${WRKSRC}/libao.conf.5 ${WRKSRC}/include/ao/ao_private.h \
		${WRKSRC}/doc/config.html

.include <bsd.port.mk>
