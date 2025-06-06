PORTNAME=	ruby
PORTVERSION=	${RUBY_DISTVERSION}
PORTEPOCH=	${RUBY_PORTEPOCH}
CATEGORIES=	lang ruby
MASTER_SITES=	RUBY/${MASTER_SITE_SUBDIR_RUBY}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Object-oriented interpreted scripting language
WWW=		https://www.ruby-lang.org/en/

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

DEPRECATED=	Please migrate to newer version. Ruby 3.2 is expected to reach its EoL on March 31, 2026
EXPIRATION_DATE=	2026-04-30

# Using LIB_DEPENDS finds the libffi from gcc which causes problems
BUILD_DEPENDS=	libffi>=0:devel/libffi
LIB_DEPENDS=	libyaml.so:textproc/libyaml
RUN_DEPENDS=	libffi>=0:devel/libffi

USES=		autoreconf cpe localbase ruby:none ssl tar:xz
CPE_VENDOR=	ruby-lang
CPE_UPDATE=	p0
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${RUBY_CONFIGURE_ARGS} \
		--disable-rpath \
		--enable-install-static-library \
		--enable-pthread \
		--enable-shared \
		--with-ruby-version="${RUBY_VER}" \
		--with-sitedir="${PREFIX}/lib/ruby/site_ruby" \
		--with-vendordir="${PREFIX}/lib/ruby/vendor_ruby"
CONFIGURE_ENV=	debugflags=

# Keep this, else ruby will fail to load libraries dependent of libpthread.
LIBS+=		-lpthread

# We get these from other ports
EXTRACT_AFTER_ARGS=	--exclude ${DISTNAME}/bin/gem \
			--exclude ${DISTNAME}/ext/win32* \
			--exclude ${DISTNAME}/lib/bundler* \
			--exclude ${DISTNAME}/libexec/bundler \
			--exclude ${DISTNAME}/man/erb.1 \
			--exclude ${DISTNAME}/man/irb.1 \
			--exclude ${DISTNAME}/man/ri.1 \
			--no-same-owner --no-same-permissions

RUBY_VER=	3.2

OPTIONS_DEFINE=		CAPIDOCS DEBUG DOCS EXAMPLES GMP RDOC YJIT
OPTIONS_DEFAULT=	LIBEDIT RDOC
OPTIONS_SINGLE=		EDIT
OPTIONS_SINGLE_EDIT=	LIBEDIT READLINE
OPTIONS_SUB=		yes

CAPIDOCS_DESC=	Build and install C API documents
EDIT_DESC=	Which line editing lib to use
GMP_DESC=	Use GMP to accelerate Bignum operations
LIBEDIT_DESC=	Use libedit
RDOC_DESC=	Build and install Rdoc indexes
READLINE_DESC=	Use libreadline
YJIT_DESC=	Enable YJIT (Yet Another Ruby JIT)

CAPIDOCS_BUILD_DEPENDS=		dot:graphics/graphviz \
				doxygen>=1.8.13,2:devel/doxygen
CAPIDOCS_CONFIGURE_ENABLE=	install-capi
GMP_LIB_DEPENDS=		libgmp.so:math/gmp
GMP_CONFIGURE_WITH=		gmp
LIBEDIT_USES=			libedit
LIBEDIT_CONFIGURE_ON=		--enable-libedit \
				--with-libedit-dir=${LOCALBASE}
RDOC_CONFIGURE_ENABLE=		install-rdoc
READLINE_USES=			readline
READLINE_CONFIGURE_ON=		--disable-libedit \
				--with-readline-dir=${LOCALBASE}
YJIT_BUILD_DEPENDS=		${RUST_DEFAULT}>=1.58.0:lang/${RUST_DEFAULT}
YJIT_CONFIGURE_ENABLE=		yjit

.include <bsd.port.pre.mk>

# PORTREVISION/PORTEPOCH hack

.if ${PORTREVISION} != 0
_SUF1=		_${PORTREVISION}
.endif

.if ${PORTEPOCH} != 0
_SUF2=		,${PORTEPOCH}
.endif

#.if ${OPSYS} == "FreeBSD"
#.if exists(/usr/sbin/dtrace) && (${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == powerpc64le || ${ARCH} == powerpc64 || ${ARCH} == powerpc)
#CONFIGURE_ARGS+=--enable-dtrace
#.else
#CONFIGURE_ARGS+=--disable-dtrace
#.endif
#.endif

# keep in sync with all platforms where libunwind is available
.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == armv7 || ${ARCH} == \
	i386 || ${ARCH} == powerpc || ${ARCH} == powerpc64 || ${ARCH} == powerpc64le
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.endif

.if ${ARCH} == armv6 || ${ARCH} == armv7 || ${ARCH} == powerpc
CONFIGURE_ARGS+=	--with-setjmp-type=_setjmp
CONFIGURE_ENV+=		ac_cv_func__setjmp=yes
.endif

.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
PLIST_SUB+=	IF_DEFAULT=""
.else
PKGNAMESUFFIX=	${RUBY_SUFFIX}
PLIST_SUB+=	IF_DEFAULT="@comment "
.endif

INSTALLED_SCRIPTS=	ruby
INSTALLED_MANUALS=	ruby

EXTSAMPLES=	bigdecimal/sample/*.rb

EXTDOCS=	readline/README ripper/README stringio/README.md \
		syslog/syslog.txt

# Macros to change variables in rbconfig.rb
# NOTE: The last argument RB_SET_CONF_VAR is a dummy argument. See bug 222872.
RB_SET_CONF_VAR=	${SH} -c \
			'${REINPLACE_CMD} -E -e "s,(CONFIG\[\"$$0\"\][[:space:]]*=[[:space:]]*)(\(?)(.*)(\)?),\1\2$$1\4," ${WRKSRC}/rbconfig.rb' \
			RB_SET_CONF_VAR

post-build:
#
# Hack to allow modules to be installed into separate PREFIX and/or under user
# privileges
#
	@${RB_SET_CONF_VAR} "prefix" "ENV['PREFIX'] || \3"
	@${RB_SET_CONF_VAR} "INSTALL" "'/usr/bin/install -c'"
	@${RB_SET_CONF_VAR} "INSTALL_PROGRAM" "ENV['RB_USER_INSTALL'] ? '${INSTALL} ${COPY} ${STRIP} -m ${BINMODE}' : '${INSTALL_PROGRAM}'"
	@${RB_SET_CONF_VAR} "INSTALL_SCRIPT" "ENV['RB_USER_INSTALL'] ? '${INSTALL} ${COPY} -m ${BINMODE}' : '${INSTALL_SCRIPT}'"
	@${RB_SET_CONF_VAR} "INSTALL_DATA" "ENV['RB_USER_INSTALL'] ? '${INSTALL} ${COPY} -m ${SHAREMODE}' : '${INSTALL_DATA}'"

post-build-CAPIDOCS-on:
	@${FIND} ${WRKSRC}/doc -type d -empty -delete

pre-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITEARCHLIBDIR}
	${MKDIR} ${STAGEDIR}${RUBY_VENDORARCHLIBDIR}

pre-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${RUBY_DOCDIR}

pre-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${RUBY_EXAMPLESDIR}

pre-install-RDOC-on:
	${MKDIR} ${STAGEDIR}${RUBY_RIDIR}
	${MKDIR} ${STAGEDIR}${RUBY_SITERIDIR}

post-install:
.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
#
# Link just installed "ruby" to "ruby31", etc.
#
. for FILE in ${INSTALLED_SCRIPTS}
	${LN} -fs ${FILE}${RUBY_SUFFIX} ${STAGEDIR}${PREFIX}/bin/${FILE}
. endfor
#
# Link "ruby.1.gz" to "ruby31.1.gz", etc.
#
. for FILE in ${INSTALLED_MANUALS}
	${LN} -fs ${FILE}${RUBY_SUFFIX}.1.gz ${STAGEDIR}${PREFIX}/share/man/man1/${FILE}.1.gz
. endfor
.endif

post-install-CAPIDOCS-on:
	${RM} ${WRKSRC}/doc/capi/.timestamp ${STAGEDIR}${PREFIX}/share/doc/ruby${RUBY_SUFFIX}/capi/.timestamp
	cd ${STAGEDIR}${PREFIX} && ${FIND} share/doc/ruby${RUBY_SUFFIX}/capi/ -type f >> ${TMPPLIST}

post-install-DEBUG-off:
#
# XXX: hack to strip ruby binary. Ruby uses its own install script that seems
# bogus to hack.
#
.if defined(STRIP) && ${STRIP} == -s
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ruby${RUBY_SUFFIX}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libruby${RUBY_SHLIBVER}.so.${RUBY_SHLIBVER}
	${FIND} ${STAGEDIR}${RUBY_ARCHLIBDIR} -type f -name '*\.so' -exec ${STRIP_CMD} {} \;
.endif

post-install-DOCS-on:
# Create all dirs required (":u" isn't available in STABLE yet :-()
	${MKDIR} ${EXTDOCS:C|^([^/]+)/.*|\1|:S|^|${STAGEDIR}${RUBY_DOCDIR}/|}
.for FILE in ${EXTDOCS}
	${INSTALL_DATA} ${WRKSRC}/ext/${FILE} \
		${STAGEDIR}${RUBY_DOCDIR}/${FILE:C|^([^/]+)/.*|\1|}/
.endfor
	@(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${RUBY_DOCDIR}/)
	${INSTALL_DATA} ${WRKSRC}/COPYING*	\
			${WRKSRC}/ChangeLog	\
			${WRKSRC}/LEGAL		\
			${WRKSRC}/README*	\
			${STAGEDIR}${RUBY_DOCDIR}/

post-install-EXAMPLES-on:
# Create all dirs required (":u" isn't available in STABLE yet :-()
	${MKDIR} ${EXTSAMPLES:C|^([^/]+)/.*|\1|:S|^|${STAGEDIR}${RUBY_EXAMPLESDIR}/|}
.for FILE in ${EXTSAMPLES}
	${INSTALL_DATA} ${WRKSRC}/ext/${FILE} \
		${STAGEDIR}${RUBY_EXAMPLESDIR}/${FILE:C|^([^/]+)/.*|\1|}/
.endfor
	(cd ${WRKSRC}/sample/ && ${COPYTREE_SHARE} . ${STAGEDIR}${RUBY_EXAMPLESDIR}/)

do-test:
	cd ${WRKSRC} && ${MAKE_CMD} test

.include <bsd.port.post.mk>
