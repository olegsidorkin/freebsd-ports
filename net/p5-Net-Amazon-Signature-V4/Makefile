PORTNAME=	Net-Amazon-Signature-V4
PORTVERSION=	0.22
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for AWS signature V4, AWS4-HMAC-SHA256
WWW=		https://metacpan.org/release/Net-Amazon-Signature-V4

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-URI>=0:net/p5-URI
TEST_DEPENDS=	p5-File-Slurper>0:devel/p5-File-Slurper

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
