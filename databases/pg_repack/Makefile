PORTNAME=	pg_repack
PORTVERSION=	1.5.2
DISTVERSIONPREFIX=	ver_
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Reorganize tables in PostgreSQL databases with minimal locks
WWW=		https://github.com/reorg/pg_repack

LICENSE=	BSD3CLAUSE

USES=		gettext-runtime gmake pgsql:11+
LLD_UNSAFE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	reorg

WANT_PGSQL=	server

PLIST_FILES=	bin/pg_repack \
		lib/postgresql/pg_repack.so \
		share/postgresql/extension/pg_repack--${PORTVERSION}.sql \
		share/postgresql/extension/pg_repack.control

post-install:
	        ${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pg_repack \
		       ${STAGEDIR}${PREFIX}/lib/postgresql/pg_repack.so

.include <bsd.port.mk>
