PORTNAME=	merkuro
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Calendar application using Akonadi and QML for online calendars
WWW=		https://invent.kde.org/pim/kalendar

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-only.txt

USES=		cmake compiler:c++17-lang desktop-file-utils gettext kde:6 \
		qt:6 tar:xz xorg
USE_KDE=	akonadi akonadicalendar akonadicontacts auth calendarcore \
		calendarsupport calendarutils codecs config configwidgets \
		contacts coreaddons dbusaddons eventviews grantleetheme i18n \
		identitymanagement itemmodels kio kirigami-addons kirigami2 \
		mailcommon mime mimetreeparser notifications people \
		pimtextedit qqc2-desktop-style service sonnet textwidgets \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base location
USE_XORG=	x11

.include <bsd.port.mk>
