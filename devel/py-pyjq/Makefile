PORTNAME=	pyjq
PORTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmm@tutanota.com
COMMENT=	Python binding for jq
WWW=		https://github.com/doloopwhile/pyjq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjq.so:textproc/jq \
		libonig.so:devel/oniguruma

USES=		localbase python:3.9
USE_PYTHON=	autoplist distutils

post-patch:
	@${RM} -r ${WRKSRC}/dependencies

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_pyjq*.so

.include <bsd.port.mk>
