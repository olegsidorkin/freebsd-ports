PORTNAME=	xfireworks
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://kozos.jp/myfreesoft/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Fireworks on X
WWW=		https://kozos.jp/myfreesoft/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		xorg
USE_XORG=	x11

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xfireworks ${STAGEDIR}${PREFIX}/bin/xfireworks
	${INSTALL_MAN} ${WRKSRC}/xfireworks.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/xfireworks.conf ${STAGEDIR}${PREFIX}/etc/xfireworks.conf.sample

.include <bsd.port.post.mk>
