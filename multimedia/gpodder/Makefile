PORTNAME=	gpodder
DISTVERSION=	3.11.5
CATEGORIES=	multimedia python

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Media aggregator and podcast client
WWW=		https://gpodder.github.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}build>0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}installer>0:devel/py-installer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		intltool-extract:textproc/intltool \
		help2man:misc/help2man
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mygpoclient>=1.7:devel/py-mygpoclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}podcastparser>=0.6.0:devel/py-podcastparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>=0:audio/py-mutagen@${PY_FLAVOR} \
		yt-dlp:www/yt-dlp \
		${PYTHON_PKGNAMEPREFIX}eyed3>=0:audio/py-eyed3@${PY_FLAVOR}

USES=		gettext gmake gnome python

USE_GITHUB=	yes

OPTIONS_DEFINE=		GTK3
OPTIONS_DEFAULT=	GTK3
OPTIONS_SUB=		yes
OPTIONS_EXCLUDE=	NLS

ALL_TARGET=	messages
MAKE_ENV=	PYTHON=${PYTHON_CMD}
MAKEFILE=	makefile
NO_ARCH=	yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

GTK3_VARS=	MAKE_ENV+=GPODDER_INSTALL_UIS="cli gtk"
GTK3_RUN_DEPENDS+=	xdg-open:devel/xdg-utils
GTK3_USE=	GNOME=pygobject3

.if empty(GTK3)
MAKE_ENV+=	GPODDER_INSTALL_UIS="cli"
.endif

.include <bsd.port.mk>
