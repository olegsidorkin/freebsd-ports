PORTNAME=	aws-sdk-importexport
PORTVERSION=	1.62.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official AWS Ruby gem for AWS Import/Export
WWW=		https://github.com/aws/aws-sdk-ruby/tree/version-3/gems/aws-sdk-importexport

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-aws-sdk-core>=3.227.0<4:devel/rubygem-aws-sdk-core \
		rubygem-aws-sigv2>=1.0<2:devel/rubygem-aws-sigv2

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
