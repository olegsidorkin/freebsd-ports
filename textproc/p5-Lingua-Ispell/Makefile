PORTNAME=	Lingua-Ispell
PORTVERSION=	0.07
PORTREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl module that encapsulates access to the Ispell program
WWW=		https://metacpan.org/release/Lingua-Ispell

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	ispell:textproc/aspell-ispell

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/lib/Lingua/Ispell.pm

.include <bsd.port.mk>
