PORTNAME=	compiz
PORTVERSION=	0.8.8
PORTREVISION=	15
CATEGORIES=	x11-wm
MASTER_SITES=	https://BSDforge.com/projects/source/x11-wm/compiz/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Compiz Composite/Window Manager
WWW=		http://www.compiz.org/

LICENSE=		GPLv2+ LGPL21+ MIT
LICENSE_COMB=		multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_MIT=	${WRKSRC}/COPYING.MIT

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgtop-2.0.so:devel/libgtop \
		libpng.so:graphics/png \
		libstartup-notification-1.so:x11/startup-notification
RUN_DEPENDS=	glxinfo:graphics/mesa-demos \
		${RUN_DEPENDS_${ARCH}}
RUN_DEPENDS_amd64=	nvidia-settings:x11/nvidia-settings
RUN_DEPENDS_i386=	nvidia-settings:x11/nvidia-settings

USES=		gettext-runtime gettext-tools gl gmake gnome libtool \
		localbase pathfix tar:bzip2 xorg xorg-cat:app
USE_GL=		gl glu
USE_GNOME=	cairo intltool libxslt
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama \
		xorgproto xrandr xrender

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-kde4 \
		--disable-kde \
		--disable-gconf \
		--disable-gnome \
		--disable-gnome-keybindings \
		--disable-metacity \
		--disable-inotify
INSTALL_TARGET=	install-strip

SUB_FILES=		compiz-manager
DESKTOP_ENTRIES=	"Compiz Manager" \
			"Wrapper script for starting compiz" \
			"" \
			"compiz-manager" \
			"System;Core;" \
			false

OPTIONS_DEFINE=	DBUS FUSE GTK2 SVG
OPTIONS_DEFAULT=DBUS GTK2 SVG
OPTIONS_SUB=	yes

DBUS_CONFIGURE_ENABLE=	dbus
DBUS_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:devel/dbus
DBUS_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:devel/dbus

FUSE_CONFIGURE_ENABLE=	fuse
FUSE_USES=		fuse

GTK2_CONFIGURE_ENABLE=	gtk
GTK2_USE=	GNOME=glib20
GTK2_LIB_DEPENDS=	libwnck-1.so:x11-toolkits/libwnck

SVG_CONFIGURE_ENABLE=	librsvg
SVG_USE=	GNOME=librsvg2

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.if ${PORT_OPTIONS:MDBUS} && ${PORT_OPTIONS:MGTK2}
CONFIGURE_ARGS+=	--enable-dbus-glib
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:devel/dbus-glib
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:devel/dbus-glib
.else
CONFIGURE_ARGS+=	--disable-dbus-glib
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/compiz-manager ${STAGEDIR}${PREFIX}/bin/compiz-manager

.include <bsd.port.mk>
