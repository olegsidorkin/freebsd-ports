PORTNAME=	Pod-Spell
PORTVERSION=	1.27
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Formatter for spellchecking Pod
WWW=		https://metacpan.org/release/Pod-Spell

LICENSE=	ART20

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install
RUN_DEPENDS=	p5-Class-Tiny>=0:devel/p5-Class-Tiny \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-Lingua-EN-Inflect>=0:textproc/p5-Lingua-EN-Inflect

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
