PORTNAME=	cryptofs
PORTVERSION=	0.6.0
PORTREVISION=	7
CATEGORIES=	filesystems
MASTER_SITES=	https://BSDforge.com/projects/source/sysutils/fusefs-cryptofs/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Encrypted filesystem for FUSE
WWW=		https://BSDforge.com/projects/sysutils/fusefs-cryptofs/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

GNU_CONFIGURE=	yes
USES=		fuse gnome pkgconfig
USE_GNOME=	glib20
DOCS=		README cryptofs.conf

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
