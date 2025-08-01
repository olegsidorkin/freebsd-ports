PORTNAME=	libgda
DISTVERSION?=	5.2.10
PORTREVISION=	5
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX?=	5
DIST_SUBDIR=	gnome

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Provides uniform access to different kinds of data sources
WWW=		https://www.gnome-db.org/

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING.LIB

USES=		cpe python readline shebangfix sqlite tar:xz
CPE_VENDOR=	gnome
LIBGDA5_SLAVE?=	no
SHEBANG_FILES=	libgda-report/RML/*/*.py

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \

USES+=		gettext gmake gnome libtool localbase pkgconfig
USE_GNOME=	glib20 libxslt intlhack introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip
#MAKE_JOBS_UNSAFE=yes
CONFIGURE_ARGS=	--without-oracle \
		--disable-crypto \
		--disable-default-binary \
		--enable-introspection \
		--without-bdb \
		--without-mdb

.include <bsd.port.options.mk>

VERSION=	5.0
PLIST_SUB+=	VERSION=${VERSION}

.if ${LIBGDA5_SLAVE}!="no"
USE_GNOME+=	libgda5
.endif

.if ${LIBGDA5_SLAVE}==ui
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error
CONFIGURE_ARGS+=--with-ui
USE_GNOME+=	cairo gtk30
.else
CONFIGURE_ARGS+=--without-ui
.endif

.if ${LIBGDA5_SLAVE}==ldap
USES+=			ldap
CONFIGURE_ARGS+=	--with-ldap=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if ${LIBGDA5_SLAVE}==mysql
USES+=			mysql
IGNORE_WITH_MYSQL=	80
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${LIBGDA5_SLAVE}==postgresql
USES+=			pgsql
CONFIGURE_ARGS+=	--with-postgres=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-postgres
.endif

.if ${LIBGDA5_SLAVE}==jdbc
USES+=			java
JAVA_VENDOR=		openjdk
CFLAGS+=		-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd
.else
CONFIGURE_ARGS+=	--without-java
.endif

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|"db.h|"db${BDB_VER}/db.h|g' \
		-e 's|ldb47|l${BDB_LIB_NAME}|g' \
		-e 's|ldb|l${BDB_LIB_NAME}|g' \
		-e 's|libdb|lib${BDB_LIB_NAME}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|<db\.h>|<db${BDB_VER}/db.h>|' \
		${WRKSRC}/providers/bdb/gda-bdb-provider.c \
		${WRKSRC}/providers/bdb/gda-bdb-test.c
.if ${LIBGDA5_SLAVE} == jdbc
	@${REINPLACE_CMD} -e 's|lib/amd64|lib/${ARCH:S/powerpc/ppc/}|g' \
		${WRKSRC}/getsp.java
.endif
.if ${LIBGDA5_SLAVE}!="no"
	@${FIND} ${WRKSRC} -name Makefile.in -exec ${REINPLACE_CMD} \
		-e 's|$$(top_builddir)/libgda/libgda-5.0.la|-lgda-5.0|g' \
		-e 's|../libgda/libgda-5.0.la|-lgda-5.0|g' \
		-e '/LIBS =/s|-lgda-5.0|gda-5.0|g' \
		{} \;
.endif

.if ${LIBGDA5_SLAVE} == jdbc
pre-configure:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/javac getsp.java
.endif

pre-build:
.if ${LIBGDA5_SLAVE}==postgresql
	cd ${WRKSRC}/providers/reuseable/postgres && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} libgda-postgres.la
.endif

.if ${LIBGDA5_SLAVE}==mysql
	cd ${WRKSRC}/providers/reuseable/mysql && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} libgda-mysql.la
.endif

.if ${LIBGDA5_SLAVE}==ui
	cd ${WRKSRC}/libgda && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} gda-enum-types.h
.endif

.if ${LIBGDA5_SLAVE}==no
post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/libgda-${VERSION}/config \
		${STAGEDIR}${PREFIX}/etc/libgda-${VERSION}/config.sample
.endif
.if ${LIBGDA5_SLAVE}==ui
post-install:
	${INSTALL_DATA} ${WRKSRC}/libgda-ui-5.0.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/
.endif

.include <bsd.port.mk>
