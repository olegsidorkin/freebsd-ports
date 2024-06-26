PORTNAME=	czmq
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.1
PORTREVISION=	2
CATEGORIES=	net
PKGNAMESUFFIX=	4

MAINTAINER=	krion@FreeBSD.org
COMMENT=	High-level C Binding for ZeroMQ (Version 4)
WWW=		http://czmq.zeromq.org

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		xmlto:textproc/xmlto
LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		autoreconf libtool pkgconfig shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	zeromq
USE_LDCONFIG=	yes

SHEBANG_FILES=	doc/mkman mkdoc model/chkopts.pl model/rename_class

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-drafts="yes" \
		--with-docs="yes" \
		--with-libzmq=${LOCALBASE} \
		--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig

MAKE_ENV=	V=1
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
CPPFLAGS+=	-Wno-error

CONFLICTS_INSTALL=	czmq-3.*

.include <bsd.port.mk>
