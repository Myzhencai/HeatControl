#############################################################################
# Makefile for building: HeatControlApplication
# Generated by qmake (3.1) (Qt 5.9.3)
# Project:  C:\Users\APPO\Desktop\HeatContolApplication\HeatControlApplication.pro
# Template: app
# Command: D:\QT\5.9.3\mingw53_32\bin\qmake.exe -o Makefile C:\Users\APPO\Desktop\HeatContolApplication\HeatControlApplication.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
#############################################################################

MAKEFILE      = Makefile

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = D:\QT\5.9.3\mingw53_32\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
QINSTALL      = D:\QT\5.9.3\mingw53_32\bin\qmake.exe -install qinstall
QINSTALL_PROGRAM = D:\QT\5.9.3\mingw53_32\bin\qmake.exe -install qinstall -exe
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: C:/Users/APPO/Desktop/HeatContolApplication/HeatControlApplication.pro ../../QT/5.9.3/mingw53_32/mkspecs/features/spec_pre.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/qdevice.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/features/device_config.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/common/g++-base.conf \
		../../QT/5.9.3/mingw53_32/mkspecs/common/angle.conf \
		../../QT/5.9.3/mingw53_32/mkspecs/common/sanitize.conf \
		../../QT/5.9.3/mingw53_32/mkspecs/common/gcc-base.conf \
		../../QT/5.9.3/mingw53_32/mkspecs/qconfig.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3danimation.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3danimation_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dcore.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dcore_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dextras.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dextras_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dinput.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dinput_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dlogic.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dlogic_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquick.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquick_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickanimation.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickanimation_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickextras.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickextras_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickinput.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickinput_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickrender.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickrender_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickscene2d.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickscene2d_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3drender.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3drender_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_axbase.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_axbase_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_axcontainer.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_axcontainer_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_axserver.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_axserver_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_bluetooth.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_charts.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_charts_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_concurrent.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_core.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_core_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_datavisualization.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_datavisualization_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_dbus.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_dbus_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_designer.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_designer_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_egl_support_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_fb_support_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_gamepad.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_gamepad_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_gui.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_gui_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_help.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_help_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_location.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_location_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_multimedia.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_network.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_network_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_networkauth.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_networkauth_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_nfc.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_nfc_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_opengl.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_opengl_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_openglextensions.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_positioning.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_positioning_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_printsupport.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_purchasing.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_purchasing_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_qml.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_qml_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_qmldebug_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_qmltest.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_quick.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_quick_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_remoteobjects.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_remoteobjects_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_repparser.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_repparser_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_script.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_script_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_scripttools.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_scxml.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_scxml_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_sensors.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_sensors_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_serialbus.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_serialbus_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_serialport.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_serialport_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_sql.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_sql_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_svg.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_svg_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_testlib.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_testlib_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_texttospeech.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_texttospeech_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_theme_support_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_uiplugin.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_uitools.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_uitools_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_webchannel.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_websockets.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_websockets_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_widgets.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_widgets_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_winextras.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_winextras_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_xml.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_xml_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../QT/5.9.3/mingw53_32/mkspecs/features/qt_functions.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/qt_config.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/win32-g++/qmake.conf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/spec_post.prf \
		.qmake.stash \
		../../QT/5.9.3/mingw53_32/mkspecs/features/exclusive_builds.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/toolchain.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/default_pre.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/win32/default_pre.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/resolve_config.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/exclusive_builds_post.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/default_post.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/qml_debug.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/precompile_header.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/warn_on.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/qt.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/resources.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/moc.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/win32/opengl.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/uic.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/qmake_use.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/file_copies.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/win32/windows.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/testcase_targets.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/exceptions.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/yacc.prf \
		../../QT/5.9.3/mingw53_32/mkspecs/features/lex.prf \
		C:/Users/APPO/Desktop/HeatContolApplication/HeatControlApplication.pro \
		../../QT/5.9.3/mingw53_32/lib/qtmaind.prl \
		../../QT/5.9.3/mingw53_32/lib/Qt5Widgets.prl \
		../../QT/5.9.3/mingw53_32/lib/Qt5Gui.prl \
		../../QT/5.9.3/mingw53_32/lib/Qt5Concurrent.prl \
		../../QT/5.9.3/mingw53_32/lib/Qt5Network.prl \
		../../QT/5.9.3/mingw53_32/lib/Qt5SerialPort.prl \
		../../QT/5.9.3/mingw53_32/lib/Qt5Core.prl
	$(QMAKE) -o Makefile C:\Users\APPO\Desktop\HeatContolApplication\HeatControlApplication.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
../../QT/5.9.3/mingw53_32/mkspecs/features/spec_pre.prf:
../../QT/5.9.3/mingw53_32/mkspecs/qdevice.pri:
../../QT/5.9.3/mingw53_32/mkspecs/features/device_config.prf:
../../QT/5.9.3/mingw53_32/mkspecs/common/g++-base.conf:
../../QT/5.9.3/mingw53_32/mkspecs/common/angle.conf:
../../QT/5.9.3/mingw53_32/mkspecs/common/sanitize.conf:
../../QT/5.9.3/mingw53_32/mkspecs/common/gcc-base.conf:
../../QT/5.9.3/mingw53_32/mkspecs/qconfig.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3danimation.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3danimation_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dcore.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dcore_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dextras.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dextras_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dinput.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dinput_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dlogic.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dlogic_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquick.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquick_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickanimation.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickanimation_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickextras.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickextras_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickinput.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickinput_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickrender.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickrender_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickscene2d.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3dquickscene2d_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3drender.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_3drender_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_accessibility_support_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_axbase.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_axbase_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_axcontainer.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_axcontainer_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_axserver.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_axserver_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_bluetooth.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_bluetooth_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_bootstrap_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_charts.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_charts_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_concurrent.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_concurrent_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_core.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_core_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_datavisualization.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_datavisualization_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_dbus.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_dbus_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_designer.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_designer_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_designercomponents_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_egl_support_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_fb_support_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_gamepad.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_gamepad_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_gui.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_gui_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_help.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_help_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_location.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_location_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_multimedia.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_multimedia_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_network.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_network_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_networkauth.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_networkauth_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_nfc.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_nfc_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_opengl.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_opengl_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_openglextensions.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_openglextensions_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_packetprotocol_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_positioning.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_positioning_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_printsupport.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_printsupport_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_purchasing.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_purchasing_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_qml.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_qml_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_qmldebug_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_qmldevtools_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_qmltest.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_qmltest_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_quick.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_quick_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_quickparticles_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_quickwidgets.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_remoteobjects.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_remoteobjects_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_repparser.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_repparser_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_script.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_script_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_scripttools.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_scripttools_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_scxml.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_scxml_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_sensors.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_sensors_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_serialbus.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_serialbus_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_serialport.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_serialport_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_sql.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_sql_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_svg.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_svg_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_testlib.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_testlib_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_texttospeech.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_texttospeech_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_theme_support_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_uiplugin.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_uitools.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_uitools_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_webchannel.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_webchannel_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_websockets.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_websockets_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_widgets.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_widgets_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_winextras.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_winextras_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_xml.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_xml_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns.pri:
../../QT/5.9.3/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
../../QT/5.9.3/mingw53_32/mkspecs/features/qt_functions.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/qt_config.prf:
../../QT/5.9.3/mingw53_32/mkspecs/win32-g++/qmake.conf:
../../QT/5.9.3/mingw53_32/mkspecs/features/spec_post.prf:
.qmake.stash:
../../QT/5.9.3/mingw53_32/mkspecs/features/exclusive_builds.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/toolchain.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/default_pre.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/win32/default_pre.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/resolve_config.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/exclusive_builds_post.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/default_post.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/qml_debug.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/precompile_header.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/warn_on.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/qt.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/resources.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/moc.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/win32/opengl.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/uic.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/qmake_use.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/file_copies.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/win32/windows.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/testcase_targets.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/exceptions.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/yacc.prf:
../../QT/5.9.3/mingw53_32/mkspecs/features/lex.prf:
C:/Users/APPO/Desktop/HeatContolApplication/HeatControlApplication.pro:
../../QT/5.9.3/mingw53_32/lib/qtmaind.prl:
../../QT/5.9.3/mingw53_32/lib/Qt5Widgets.prl:
../../QT/5.9.3/mingw53_32/lib/Qt5Gui.prl:
../../QT/5.9.3/mingw53_32/lib/Qt5Concurrent.prl:
../../QT/5.9.3/mingw53_32/lib/Qt5Network.prl:
../../QT/5.9.3/mingw53_32/lib/Qt5SerialPort.prl:
../../QT/5.9.3/mingw53_32/lib/Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile C:\Users\APPO\Desktop\HeatContolApplication\HeatControlApplication.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"

qmake_all: FORCE

make_first: debug-make_first release-make_first  FORCE
all: debug-all release-all  FORCE
clean: debug-clean release-clean  FORCE
distclean: debug-distclean release-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash

debug-mocclean:
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first

benchmark: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
