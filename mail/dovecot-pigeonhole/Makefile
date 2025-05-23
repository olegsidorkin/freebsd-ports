PORTNAME=	dovecot-pigeonhole
DISTVERSION=	0.5.21.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	https://pigeonhole.dovecot.org/releases/${DOVECOTVERSION}/
DISTNAME=	${PORTNAME:C/-/-${DOVECOTVERSION}-/}-${PORTVERSION}

MAINTAINER=	ler@FreeBSD.org
COMMENT=	Sieve plugin for the Dovecot 'deliver' LDA and LMTP
WWW=		https://pigeonhole.dovecot.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

FLAVORS=	default mysql pgsql
FLAVOR?=	${FLAVORS[1]}
mysql_PKGNAMESUFFIX=	-mysql
pgsql_PKGNAMESUFFIX=	-pgsql
BUILD_DEPENDS=	dovecot>=2.3.9:mail/dovecot@default
RUN_DEPENDS=	dovecot>=2.3.9:mail/dovecot@default
.if ${FLAVOR:U} == mysql
BUILD_DEPENDS=	dovecot-mysql>=2.3.9:mail/dovecot@mysql
RUN_DEPENDS=	dovecot-mysql>=2.3.9:mail/dovecot@mysql
.endif
.if ${FLAVOR:U} == pgsql
BUILD_DEPENDS=	dovecot-pgsql>=2.3.9:mail/dovecot@pgsql
RUN_DEPENDS=	dovecot-pgsql>=2.3.9:mail/dovecot@pgsql
.endif

DOVECOTVERSION=	2.3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} \
		--docdir=${DOCSDIR} \
		--with-dovecot="${LOCALBASE}/lib/dovecot"
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		compiler:c11 libtool ssl
USE_LDCONFIG=	${PREFIX}/lib/dovecot

OPTIONS_DEFINE=	DOCS EXAMPLES LDAP MANAGESIEVE
OPTIONS_DEFAULT=EXAMPLES MANAGESIEVE GSSAPI_NONE

OPTIONS_SINGLE=	GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_NONE GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT
OPTIONS_SUB=	yes

GSSAPI_DESC=		GSSAPI Support (*MUST MATCH* mail/dovecot)
GSSAPI_NONE_DESC=	Build without GSSAPI support
GSSAPI_BASE_DESC=	Use GSSAPI from base
GSSAPI_HEIMDAL_DESC=	Use Heimdal GSSAPI from security/heimdal
GSSAPI_MIT_DESC=	Use MIT GSSAPI from security/krb5

GSSAPI_BASE_USES=	gssapi
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_NONE_CONFIGURE_OFF=	${GSSAPI_CONFIGURE_ARGS}
BUILD_FAIL_MESSAGE=	Ensure that ${PORTNAME}'s GSSAPI backend is the same as dovecot2 (make config).

MANAGESIEVE_DESC=		ManageSieve support
MANAGESIEVE_CONFIGURE_WITH=	managesieve

LDAP_CONFIGURE_WITH=	ldap
LDAP_CPPFLAGS=		-I${LOCALBASE}/include
LDAP_LDFLAGS=		-L${LOCALBASE}/lib
LDAP_USES=		ldap

PORTDOCS=	sieve/extensions/* sieve/plugins/* sieve/locations/*
PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -E '\
	s!^(install-data-am:) install-sieve_docDATA!\1!; \
		s!^(uninstall-am:) uninstall-sieve_docDATA!\1!;' \
		${WRKSRC}/doc/Makefile.in

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}

	${CP} ${WRKSRC}/examples/elvey.sieve ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/jerry.sieve ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/mjohnson.sieve ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/mklose.sieve ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/relational.rfc5231.sieve ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/rfc3028.sieve ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/sanjay.sieve ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/sieve_examples.sieve ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/subaddress.rfc5233.sieve ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/vacation.sieve ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/examples/vivil.sieve ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
