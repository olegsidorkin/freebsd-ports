PORTNAME=	actionview
PORTVERSION=	4.2.11.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rendering framework putting the V in MVC (part of Rails)
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/rails/tree/main/actionview

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport4>=${PORTVERSION}:devel/rubygem-activesupport4 \
		rubygem-builder>=3.1<4:devel/rubygem-builder \
		rubygem-erubis>=2.7.0<2.8:www/rubygem-erubis \
		rubygem-rails-dom-testing1>=1.0.5<2:textproc/rubygem-rails-dom-testing1 \
		rubygem-rails-html-sanitizer>=1.0.3<2:textproc/rubygem-rails-html-sanitizer

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails

PORTSCOUT=	limit:^4\.2\.

.include <bsd.port.mk>
