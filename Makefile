#############################################################################
# Makefile for building: JSONReader
# Generated by qmake (3.1) (Qt 5.11.0)
# Project:  JSONReader.pro
# Template: subdirs
# Command: /usr/lib/qt5/bin/qmake -o Makefile JSONReader.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
#############################################################################

MAKEFILE      = Makefile

first: make_first
QMAKE         = /usr/lib/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/lib/qt5/bin/qmake -install qinstall
QINSTALL_PROGRAM = /usr/lib/qt5/bin/qmake -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = JSONReader1.0.0
DISTDIR = /home/astra/Projects/JSONReader/.tmp/JSONReader1.0.0
SUBTARGETS    =  \
		sub----JSONReader \
		sub----JSONReaderAutoTest


sub----JSONReader-qmake_all:  FORCE
	@test -d ../JSONReader/ || mkdir -p ../JSONReader/
	cd ../JSONReader/ && $(QMAKE) -o Makefile /home/astra/Projects/JSONReader/JSONReader.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
	cd ../JSONReader/ && $(MAKE) -f Makefile qmake_all
sub----JSONReader: FORCE
	@test -d ../JSONReader/ || mkdir -p ../JSONReader/
	cd ../JSONReader/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReader/JSONReader.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile
sub----JSONReader-make_first: FORCE
	@test -d ../JSONReader/ || mkdir -p ../JSONReader/
	cd ../JSONReader/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReader/JSONReader.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile 
sub----JSONReader-all: FORCE
	@test -d ../JSONReader/ || mkdir -p ../JSONReader/
	cd ../JSONReader/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReader/JSONReader.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile all
sub----JSONReader-clean: FORCE
	@test -d ../JSONReader/ || mkdir -p ../JSONReader/
	cd ../JSONReader/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReader/JSONReader.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile clean
sub----JSONReader-distclean: FORCE
	@test -d ../JSONReader/ || mkdir -p ../JSONReader/
	cd ../JSONReader/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReader/JSONReader.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile distclean
sub----JSONReader-install_subtargets: FORCE
	@test -d ../JSONReader/ || mkdir -p ../JSONReader/
	cd ../JSONReader/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReader/JSONReader.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile install
sub----JSONReader-uninstall_subtargets: FORCE
	@test -d ../JSONReader/ || mkdir -p ../JSONReader/
	cd ../JSONReader/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReader/JSONReader.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile uninstall
sub----JSONReaderAutoTest-qmake_all:  FORCE
	@test -d ../JSONReaderAutoTest/ || mkdir -p ../JSONReaderAutoTest/
	cd ../JSONReaderAutoTest/ && $(QMAKE) -o Makefile /home/astra/Projects/JSONReaderAutoTest/JSONReaderAutoTest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
	cd ../JSONReaderAutoTest/ && $(MAKE) -f Makefile qmake_all
sub----JSONReaderAutoTest: FORCE
	@test -d ../JSONReaderAutoTest/ || mkdir -p ../JSONReaderAutoTest/
	cd ../JSONReaderAutoTest/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReaderAutoTest/JSONReaderAutoTest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile
sub----JSONReaderAutoTest-make_first: FORCE
	@test -d ../JSONReaderAutoTest/ || mkdir -p ../JSONReaderAutoTest/
	cd ../JSONReaderAutoTest/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReaderAutoTest/JSONReaderAutoTest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile 
sub----JSONReaderAutoTest-all: FORCE
	@test -d ../JSONReaderAutoTest/ || mkdir -p ../JSONReaderAutoTest/
	cd ../JSONReaderAutoTest/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReaderAutoTest/JSONReaderAutoTest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile all
sub----JSONReaderAutoTest-clean: FORCE
	@test -d ../JSONReaderAutoTest/ || mkdir -p ../JSONReaderAutoTest/
	cd ../JSONReaderAutoTest/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReaderAutoTest/JSONReaderAutoTest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile clean
sub----JSONReaderAutoTest-distclean: FORCE
	@test -d ../JSONReaderAutoTest/ || mkdir -p ../JSONReaderAutoTest/
	cd ../JSONReaderAutoTest/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReaderAutoTest/JSONReaderAutoTest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile distclean
sub----JSONReaderAutoTest-install_subtargets: FORCE
	@test -d ../JSONReaderAutoTest/ || mkdir -p ../JSONReaderAutoTest/
	cd ../JSONReaderAutoTest/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReaderAutoTest/JSONReaderAutoTest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile install
sub----JSONReaderAutoTest-uninstall_subtargets: FORCE
	@test -d ../JSONReaderAutoTest/ || mkdir -p ../JSONReaderAutoTest/
	cd ../JSONReaderAutoTest/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReaderAutoTest/JSONReaderAutoTest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile uninstall

Makefile: JSONReader.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KAuth.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KBookmarks.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KCodecs.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KCompletion.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KConfigCore.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KConfigGui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KConfigWidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KCoreAddons.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KDBusAddons.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KDeclarative.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KGlobalAccel.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KGuiAddons.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KI18n.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KIconThemes.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KIOCore.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KIOFileWidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KIOGui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KIOWidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KItemViews.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KJobWidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KNTLM.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KService.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KTextWidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KWidgetsAddons.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KWindowSystem.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KXmlGui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_designer.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_designer_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_help.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_help_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_location.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_positioning.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickcontrols2.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_script.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_scripttools.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sensors.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_serialport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_svg.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_texttospeech.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_uiplugin.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_uitools.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_uitools_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_waylandcompositor.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webchannel.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webengine.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webengine_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webenginecore.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webenginecore_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webenginecoreheaders_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webenginewidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webenginewidgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webkit.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webkitwidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_websockets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_x11extras.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xmlpatterns.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_QuickAddons.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_Solid.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_SonnetCore.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_SonnetUi.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qml_debug.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		JSONReader.pro
	$(QMAKE) -o Makefile JSONReader.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KAuth.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KBookmarks.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KCodecs.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KCompletion.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KConfigCore.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KConfigGui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KConfigWidgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KCoreAddons.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KDBusAddons.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KDeclarative.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KGlobalAccel.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KGuiAddons.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KI18n.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KIconThemes.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KIOCore.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KIOFileWidgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KIOGui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KIOWidgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KItemViews.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KJobWidgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KNTLM.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KService.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KTextWidgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KWidgetsAddons.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KWindowSystem.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KXmlGui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_designer.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_designer_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_designercomponents_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_help.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_help_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_location.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimedia.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_positioning.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmltest.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmltest_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quick.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quick_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickcontrols2.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickwidgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_script.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_scripttools.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sensors.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_serialport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_svg.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_texttospeech.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_uiplugin.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_uitools.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_uitools_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_waylandcompositor.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webchannel.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webengine.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webengine_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webenginecore.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webenginecore_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webenginecoreheaders_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webenginewidgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webenginewidgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webkit.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webkitwidgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_websockets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_x11extras.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xmlpatterns.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_QuickAddons.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_Solid.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_SonnetCore.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_SonnetUi.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qml_debug.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
JSONReader.pro:
qmake: FORCE
	@$(QMAKE) -o Makefile JSONReader.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug

qmake_all: sub----JSONReader-qmake_all sub----JSONReaderAutoTest-qmake_all FORCE

make_first: sub----JSONReader-make_first sub----JSONReaderAutoTest-make_first  FORCE
all: sub----JSONReader-all sub----JSONReaderAutoTest-all  FORCE
clean: sub----JSONReader-clean sub----JSONReaderAutoTest-clean  FORCE
distclean: sub----JSONReader-distclean sub----JSONReaderAutoTest-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash
install_subtargets: sub----JSONReader-install_subtargets sub----JSONReaderAutoTest-install_subtargets FORCE
uninstall_subtargets: sub----JSONReader-uninstall_subtargets sub----JSONReaderAutoTest-uninstall_subtargets FORCE

sub----JSONReader-check:
	@test -d ../JSONReader/ || mkdir -p ../JSONReader/
	cd ../JSONReader/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReader/JSONReader.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile check
sub----JSONReaderAutoTest-check:
	@test -d ../JSONReaderAutoTest/ || mkdir -p ../JSONReaderAutoTest/
	cd ../JSONReaderAutoTest/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReaderAutoTest/JSONReaderAutoTest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile check
check: sub----JSONReader-check sub----JSONReaderAutoTest-check

sub----JSONReader-benchmark:
	@test -d ../JSONReader/ || mkdir -p ../JSONReader/
	cd ../JSONReader/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReader/JSONReader.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile benchmark
sub----JSONReaderAutoTest-benchmark:
	@test -d ../JSONReaderAutoTest/ || mkdir -p ../JSONReaderAutoTest/
	cd ../JSONReaderAutoTest/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReaderAutoTest/JSONReaderAutoTest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -f Makefile benchmark
benchmark: sub----JSONReader-benchmark sub----JSONReaderAutoTest-benchmark
install:install_subtargets  FORCE

uninstall: uninstall_subtargets FORCE

FORCE:

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: sub----JSONReader-distdir sub----JSONReaderAutoTest-distdir FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KAuth.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KBookmarks.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KCodecs.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KCompletion.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KConfigCore.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KConfigGui.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KConfigWidgets.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KCoreAddons.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KDBusAddons.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KDeclarative.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KGlobalAccel.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KGuiAddons.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KI18n.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KIconThemes.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KIOCore.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KIOFileWidgets.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KIOGui.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KIOWidgets.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KItemViews.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KJobWidgets.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KNTLM.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KService.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KTextWidgets.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KWidgetsAddons.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KWindowSystem.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_KXmlGui.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_designer.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_designer_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_designercomponents_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_help.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_help_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_location.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimedia.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_positioning.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qml.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qml_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmltest.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmltest_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quick.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quick_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickcontrols2.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickwidgets.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_script.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_scripttools.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sensors.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_serialport.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_svg.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_texttospeech.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_uiplugin.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_uitools.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_uitools_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_waylandcompositor.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webchannel.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webengine.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webengine_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webenginecore.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webenginecore_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webenginecoreheaders_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webenginewidgets.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webenginewidgets_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webkit.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_webkitwidgets.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_websockets.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_x11extras.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xmlpatterns.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_QuickAddons.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_Solid.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_SonnetCore.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_SonnetUi.pri /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf .qmake.stash /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qml_debug.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf JSONReader.pro $(DISTDIR)/

sub----JSONReader-distdir: FORCE
	@test -d ../JSONReader/ || mkdir -p ../JSONReader/
	cd ../JSONReader/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReader/JSONReader.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -e -f Makefile distdir DISTDIR=$(DISTDIR)/../JSONReader

sub----JSONReaderAutoTest-distdir: FORCE
	@test -d ../JSONReaderAutoTest/ || mkdir -p ../JSONReaderAutoTest/
	cd ../JSONReaderAutoTest/ && ( test -e Makefile || $(QMAKE) -o Makefile /home/astra/Projects/JSONReaderAutoTest/JSONReaderAutoTest.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug ) && $(MAKE) -e -f Makefile distdir DISTDIR=$(DISTDIR)/../JSONReaderAutoTest

