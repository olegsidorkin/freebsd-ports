PORTNAME=	aiohttp
PORTVERSION=	3.11.18
CATEGORIES=	www python
MASTER_SITES=	PYPI \
		https://github.com/aio-libs/aiohttp/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Async http client/server framework (asyncio)
WWW=		https://docs.aiohttp.org/en/stable/ \
		https://github.com/aio-libs/aiohttp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython3>=0:lang/cython3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=46.4.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohappyeyeballs>=2.3.0:net/py-aiohappyeyeballs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiosignal>=1.1.2:devel/py-aiosignal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=17.3.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}frozenlist>=1.1.1:devel/py-frozenlist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multidict>=4.5<7.0:www/py-multidict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}propcache>=0.2.0:devel/py-propcache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yarl>=1.17.0<2.0:www/py-yarl@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiodns>=1.1:dns/py-aiodns@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}brotli>=0:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=0:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>=0:www/py-gunicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}re-assert>=0:devel/py-re-assert@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-codspeed>=0:devel/py-pytest-codspeed@${PY_FLAVOR}

USES=		cpe python:3.9+
USE_PYTHON=	autoplist concurrent pep517 pytest

CPE_VENDOR=	aiohttp_project

OPTIONS_DEFINE=	SPEEDUPS
SPEEDUPS_DESC=	Performance speedups

SPEEDUPS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiodns>=3.2.0:dns/py-aiodns@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}brotli>=0:archivers/py-brotli@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}async_timeout>=4.0<6.0:devel/py-async_timeout@${PY_FLAVOR}
.endif

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
