Leave InputMethod empty by default since qtvirtualkeyboard does not appear to
be supported by the included themes.  The keyboard is drawn on top of the
login screen and has to be clicked away (button lower-right).

Set the default theme and cursor theme to breeze, because sddm is most likely
used together with Plasma.  If they aren't available sddm falls back to a
compiled-in theme.

--- src/common/Configuration.h.orig	2024-02-26 10:23:03 UTC
+++ src/common/Configuration.h
@@ -51,10 +51,10 @@ namespace SDDM {
         //  Name   Entries (but it's a regular class again)
         Section(Theme,
             Entry(ThemeDir,            QString,     _S(DATA_INSTALL_DIR "/themes"),             _S("Theme directory path"));
-            Entry(Current,             QString,     _S(""),                                     _S("Current theme name"));
+            Entry(Current,             QString,     _S("breeze"),                               _S("Current theme name"));
             Entry(FacesDir,            QString,     _S(DATA_INSTALL_DIR "/faces"),              _S("Global directory for user avatars\n"
                                                                                                    "The files should be named <username>.face.icon"));
-            Entry(CursorTheme,         QString,     QString(),                                  _S("Cursor theme used in the greeter"));
+            Entry(CursorTheme,         QString,     _S("breeze_cursors"),                       _S("Cursor theme used in the greeter"));
             Entry(CursorSize,          QString,     QString(),                                  _S("Cursor size used in the greeter"));
             Entry(Font,                QString,     QString(),                                  _S("Font used in the greeter"));
             Entry(EnableAvatars,       bool,        true,                                       _S("Enable display of custom user avatars"));
@@ -65,11 +65,11 @@ namespace SDDM {
 
         // TODO: Not absolutely sure if everything belongs here. Xsessions, VT and probably some more seem universal
         Section(X11,
-            Entry(ServerPath,          QString,     _S("/usr/bin/X"),                           _S("Path to X server binary"));
+            Entry(ServerPath,          QString,     _S("/usr/local/bin/X"),                           _S("Path to X server binary"));
             Entry(ServerArguments,     QString,     _S("-nolisten tcp"),                        _S("Arguments passed to the X server invocation"));
-            Entry(XephyrPath,          QString,     _S("/usr/bin/Xephyr"),                      _S("Path to Xephyr binary"));
+            Entry(XephyrPath,          QString,     _S("/usr/local/bin/Xephyr"),                      _S("Path to Xephyr binary"));
             Entry(SessionDir,          QStringList, {_S("/usr/local/share/xsessions"),
-                                                     _S("/usr/share/xsessions")},               _S("Comma-separated list of directories containing available X sessions"));
+                                                     _S("/usr/local/share/xsessions")},               _S("Comma-separated list of directories containing available X sessions"));
             Entry(SessionCommand,      QString,     _S(SESSION_COMMAND),                        _S("Path to a script to execute when starting the desktop session"));
             Entry(SessionLogFile,      QString,     _S(".local/share/sddm/xorg-session.log"),   _S("Path to the user session log file"));
             Entry(DisplayCommand,      QString,     _S(DATA_INSTALL_DIR "/scripts/Xsetup"),     _S("Path to a script to execute when starting the display server"));
@@ -80,7 +80,7 @@ namespace SDDM {
         Section(Wayland,
             Entry(CompositorCommand,   QString,     _S("weston --shell=kiosk"),                 _S("Path of the Wayland compositor to execute when starting the greeter"));
             Entry(SessionDir,          QStringList, {_S("/usr/local/share/wayland-sessions"),
-                                                     _S("/usr/share/wayland-sessions")},        _S("Comma-separated list of directories containing available Wayland sessions"));
+                                                     _S("/usr/local/share/wayland-sessions")},        _S("Comma-separated list of directories containing available Wayland sessions"));
             Entry(SessionCommand,      QString,     _S(WAYLAND_SESSION_COMMAND),                _S("Path to a script to execute when starting the desktop session"));
             Entry(SessionLogFile,      QString,     _S(".local/share/sddm/wayland-session.log"),_S("Path to the user session log file"));
             Entry(EnableHiDPI,         bool,        true,                                       _S("Enable Qt's automatic high-DPI scaling"));
@@ -88,8 +88,8 @@ namespace SDDM {
 
         Section(Users,
             Entry(DefaultPath,         QString,     _S("/usr/local/bin:/usr/bin:/bin"),         _S("Default $PATH for logged in users"));
-            Entry(MinimumUid,          int,         UID_MIN,                                    _S("Minimum user id for displayed users"));
-            Entry(MaximumUid,          int,         UID_MAX,                                    _S("Maximum user id for displayed users"));
+            Entry(MinimumUid,          int,         SDDM_UID_MIN,                               _S("Minimum user id for displayed users"));
+            Entry(MaximumUid,          int,         SDDM_UID_MAX,                               _S("Maximum user id for displayed users"));
             Entry(HideUsers,           QStringList, QStringList(),                              _S("Comma-separated list of users that should not be listed"));
             Entry(HideShells,          QStringList, QStringList(),                              _S("Comma-separated list of shells.\n"
                                                                                                    "Users with these shells as their default won't be listed"));
