PORTNAME=	ack
PORTVERSION=	3.9.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PETDANCE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Grep-like text finder for large trees of text
WWW=		https://metacpan.org/release/ack \
		https://beyondgrep.com/

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Next>=1.18:sysutils/p5-File-Next
TEST_DEPENDS=	bash:shells/bash \
		p5-IO-Tty>=0:devel/p5-IO-Tty \
		p5-YAML-PP>=0:textproc/p5-YAML-PP

USES=		cpe perl5
USE_PERL5=	configure

NO_ARCH=	yes

CONFLICTS_INSTALL=	ja-ack

CPE_VENDOR=	beyondgrep

PORTSCOUT=	limit:^[0-9\.]*$$

.include <bsd.port.mk>
