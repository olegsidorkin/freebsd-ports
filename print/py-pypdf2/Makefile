PORTNAME=	pypdf2
PORTVERSION=	1.27.12
PORTREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyPDF2-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Pure-Python PDF toolkit
WWW=		https://mstamy2.github.io/PyPDF2/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream moved the development back to PyPDF. Use print/py-pypdf instead
EXPIRATION_DATE=2025-02-28

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
