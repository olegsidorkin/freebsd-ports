PORTNAME=	google-cloud-bigquery
DISTVERSION=	3.28.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSIONFULL}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Google BigQuery API client library
WWW=		https://github.com/googleapis/python-bigquery

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=2.11.1:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=2.14.1:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-core>=2.4.1:www/py-google-cloud-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-resumable-media>=2.0.0:www/py-google-resumable-media@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.49.1:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proto-plus>=1.15.0:devel/py-proto-plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.19.5:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.7.2:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.21.0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-cloud-testutils>0:www/py-google-cloud-testutils@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # 31 tests fail, tests require missing dependencies like db-tests, etc

NO_ARCH=	yes

.include <bsd.port.mk>
