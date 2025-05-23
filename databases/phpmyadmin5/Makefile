PORTNAME=	phpMyAdmin
DISTVERSION=	5.2.2
PORTREVISION=	0
CATEGORIES=	databases www
MASTER_SITES=	https://files.phpmyadmin.net/${PORTNAME}/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-all-languages
PKGNAMESUFFIX=	5${PHP_PKGNAMESUFFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Set of PHP-scripts to manage MySQL over the web
WWW=		https://www.phpmyadmin.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	phpMyAdmin-php[0-9][0-9] phpMyAdmin[0-9]-php[0-9][0-9] # www/phpMyAdmin/CONTRIBUTING.md

USES=		cpe php:web,flavors tar:xz
CPE_PRODUCT=	${PORTNAME:tl}

NO_ARCH=	yes
NO_BUILD=	yes
.if !defined(WITHOUT_PHP_DEPENDS)

# Note: composer.json files in the source list pcre as a required
# extension, but pcre is compiled into PHP as standard on FreeBSD.
# The same goes for the spl library.
# libsodium are only required in the bundled vendor code. PMA
# could, in principle, also use the PHP dbase extension, but it's not
# available for PHP >= 7.0 and of only minority interest.

USE_PHP=	ctype filter iconv mysqli session xml xmlwriter
.endif

# Note: default settings will pull in X11 client support.  If you don't
# want this, either turn off GD in the config dialog, or else turn off
# FONTCONFIG in the graphics/gd port options.

OPTIONS_DEFINE=		BZ2 CURL GD GMP MBSTRING OPCACHE \
			SODIUM ZIP ZLIB
OPTIONS_DEFAULT=	BZ2 GD MBSTRING ZIP ZLIB

BZ2_DESC=	PHP bzip2 library support
CURL_DESC=	PHP curl support
GD_DESC=	PHP GD library support (requires X11)
GMP_DESC=	PHP GMP library support
MBSTRING_DESC=	PHP Multi-byte String support
OPCACHE_DESC=	PHP Opcache support
PDF_DESC=	PHP PDFlib support
SODIUM_DESC=	PHP libsodium support
ZIP_DESC=	PHP Zip compression support
ZLIB_DESC=	PHP ZLIB support

.include <bsd.port.options.mk>

GROUPS?=	${WWWGRP}
CFG_FILE=	config.inc.php

PLIST=		${WRKDIR}/plist
PLIST_SUB+=	PMA_GRP=${GROUPS}

SUB_LIST+=	PKGNAME=${PKGNAME}	        \
		CFG_FILE=${WWWDIR}/${CFG_FILE}
SUB_FILES+=	pkg-message

.if ${FLAVOR} != php80
OPTIONS_DEFINE+=	PDF
.endif

.if !defined(WITHOUT_PHP_DEPENDS)

.for opt in ${OPTIONS_DEFINE}
.    if ${PORT_OPTIONS:M${opt}}
USE_PHP+=	${opt:tl}
.    endif
.endfor

.endif

.SILENT:

post-patch:
	cd ${WRKSRC} ; \
	${CP} ${FILESDIR}/${CFG_FILE}.sample ${WRKSRC}/${CFG_FILE}.sample ; \
	${FIND} . ! -type d ! -name ${CFG_FILE}.sample ! -name '*.bak' | \
	    ${SORT} | ${SED} -e "s,^\.,%%WWWDIR%%,"   >${PLIST} ; \
	${CAT} ${PKGDIR}/pkg-plist-chunk	     >>${PLIST} ; \
	for emptydir in $$( ${FIND} . -type d -empty -print | \
		${SED} -e "s,^\.,%%WWWDIR%%," ) ; do \
	    ${ECHO} "@dir $${emptydir}"		     >>${PLIST} ; \
	done ; \

do-install:
	cd ${WRKSRC} ; \
	for src in $$( ${FIND} . ! -name .cvsignore ! -name '*.bak' ) ; do \
	    dst=${STAGEDIR}${WWWDIR}$${src#.} ; \
	    if ${TEST} -d "$$src" ; then \
		${MKDIR} "$$dst" ; \
	    else \
		${INSTALL_DATA} "$$src" "$$dst" ; \
	    fi \
	done
	@${MKDIR} ${STAGEDIR}${WWWDIR}/tmp

.include <bsd.port.mk>
