PORTNAME=	acora
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	textproc devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Fast multi-keyword search engine for text strings
WWW=		https://github.com/scoder/acora/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	distutils autoplist

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/scratch	# Any directory different from ${WRKSRC}

do-test:
	@${MKDIR} ${TEST_WRKSRC}
	@${CP} ${WRKSRC}/test.py ${WRKSRC}/README.rst ${TEST_WRKSRC}
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} test.py

.include <bsd.port.mk>
