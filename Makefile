#############################################################################
# Makefile for building: PT_S3_L1
# Generated by qmake (3.1) (Qt 5.12.6)
# Project:  PT_S3_L1.pro
# Template: app
# Command: C:\Qt\5.12.6\mingw73_64\bin\qmake.exe -o Makefile PT_S3_L1.pro -spec win32-g++ "CONFIG-=qml_debug" "CONFIG+=qtquickcompiler" "CONFIG-=separate_debug_info"
#############################################################################

MAKEFILE      = Makefile

EQ            = =

first: release
install: release-install
uninstall: release-uninstall
QMAKE         = C:\Qt\5.12.6\mingw73_64\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
QINSTALL      = C:\Qt\5.12.6\mingw73_64\bin\qmake.exe -install qinstall
QINSTALL_PROGRAM = C:\Qt\5.12.6\mingw73_64\bin\qmake.exe -install qinstall -exe
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		release \
		debug


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

Makefile: PT_S3_L1.pro ../../../../Qt/5.12.6/mingw73_64/mkspecs/win32-g++/qmake.conf ../../../../Qt/5.12.6/mingw73_64/mkspecs/features/spec_pre.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/qdevice.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/device_config.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/common/sanitize.conf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/common/gcc-base.conf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/common/g++-base.conf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/common/angle.conf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/win32/windows_vulkan_sdk.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/common/windows-vulkan.conf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/common/g++-win32.conf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/qconfig.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3danimation.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3danimation_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dcore.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dcore_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dextras.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dextras_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dinput.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dinput_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dlogic.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dlogic_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquick.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquick_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickanimation.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickanimation_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickextras.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickextras_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickinput.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickinput_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickrender.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickrender_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickscene2d.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickscene2d_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3drender.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3drender_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_axbase.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_axbase_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_axcontainer.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_axcontainer_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_axserver.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_axserver_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_bluetooth.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_charts.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_charts_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_core.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_core_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_datavisualization.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_datavisualization_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_dbus.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_designer.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_edid_support_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_egl_support_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_fb_support_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_gamepad.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_gamepad_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_gui.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_help.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_help_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_location.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_location_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_network.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_network_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_networkauth.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_networkauth_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_nfc.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_nfc_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_opengl.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_positioning.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_positioning_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_positioningquick.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_positioningquick_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_purchasing.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_purchasing_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_qml.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_qmldebug_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quick.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quickcontrols2.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quickshapes_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quicktemplates2.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_remoteobjects.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_remoteobjects_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_repparser.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_repparser_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_script.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_script_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_scxml.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_scxml_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_sensors.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_sensors_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_serialbus.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_serialbus_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_serialport.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_serialport_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_sql.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_svg.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_testlib.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_texttospeech.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_texttospeech_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_theme_support_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_uiplugin.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_uitools.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_virtualkeyboard.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_virtualkeyboard_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_webchannel.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_websockets.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_websockets_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_widgets.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_windowsuiautomation_support_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_winextras.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_winextras_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_xml.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/qt_functions.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/qt_config.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/win32-g++/qmake.conf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/spec_post.prf \
		.qmake.stash \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/exclusive_builds.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/toolchain.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/default_pre.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/win32/default_pre.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/resolve_config.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/exclusive_builds_post.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/default_post.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/win32/console.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/resources.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/qtquickcompiler.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/precompile_header.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/warn_on.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/qmake_use.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/file_copies.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/testcase_targets.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/exceptions.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/yacc.prf \
		../../../../Qt/5.12.6/mingw73_64/mkspecs/features/lex.prf \
		PT_S3_L1.pro
	$(QMAKE) -o Makefile PT_S3_L1.pro -spec win32-g++ "CONFIG-=qml_debug" "CONFIG+=qtquickcompiler" "CONFIG-=separate_debug_info"
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/spec_pre.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/qdevice.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/device_config.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/common/sanitize.conf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/common/gcc-base.conf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/common/g++-base.conf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/common/angle.conf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/win32/windows_vulkan_sdk.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/common/windows-vulkan.conf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/common/g++-win32.conf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/qconfig.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3danimation.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3danimation_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dcore.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dcore_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dextras.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dextras_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dinput.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dinput_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dlogic.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dlogic_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquick.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquick_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickanimation.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickanimation_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickextras.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickextras_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickinput.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickinput_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickrender.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickrender_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickscene2d.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3dquickscene2d_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3drender.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_3drender_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_accessibility_support_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_axbase.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_axbase_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_axcontainer.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_axcontainer_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_axserver.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_axserver_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_bluetooth.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_bluetooth_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_bootstrap_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_charts.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_charts_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_concurrent.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_concurrent_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_core.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_core_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_datavisualization.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_datavisualization_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_dbus.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_dbus_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_designer.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_designer_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_edid_support_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_egl_support_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_fb_support_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_gamepad.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_gamepad_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_gui.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_gui_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_help.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_help_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_location.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_location_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_multimedia.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_multimedia_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_multimediawidgets.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_network.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_network_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_networkauth.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_networkauth_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_nfc.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_nfc_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_opengl.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_opengl_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_openglextensions.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_openglextensions_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_packetprotocol_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_positioning.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_positioning_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_positioningquick.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_positioningquick_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_printsupport.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_printsupport_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_purchasing.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_purchasing_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_qml.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_qml_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_qmldebug_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_qmldevtools_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_qmltest.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_qmltest_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quick.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quick_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quickcontrols2.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quickshapes_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quicktemplates2.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quickwidgets.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_remoteobjects.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_remoteobjects_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_repparser.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_repparser_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_script.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_script_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_scripttools.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_scripttools_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_scxml.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_scxml_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_sensors.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_sensors_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_serialbus.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_serialbus_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_serialport.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_serialport_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_sql.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_sql_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_svg.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_svg_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_testlib.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_testlib_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_texttospeech.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_texttospeech_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_theme_support_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_uiplugin.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_uitools.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_uitools_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_virtualkeyboard.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_virtualkeyboard_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_vulkan_support_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_webchannel.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_webchannel_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_websockets.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_websockets_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_widgets.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_widgets_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_windowsuiautomation_support_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_winextras.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_winextras_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_xml.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_xml_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_xmlpatterns.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/qt_functions.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/qt_config.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/win32-g++/qmake.conf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/spec_post.prf:
.qmake.stash:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/exclusive_builds.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/toolchain.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/default_pre.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/win32/default_pre.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/resolve_config.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/exclusive_builds_post.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/default_post.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/win32/console.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/resources.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/qtquickcompiler.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/precompile_header.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/warn_on.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/qmake_use.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/file_copies.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/testcase_targets.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/exceptions.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/yacc.prf:
../../../../Qt/5.12.6/mingw73_64/mkspecs/features/lex.prf:
PT_S3_L1.pro:
qmake: FORCE
	@$(QMAKE) -o Makefile PT_S3_L1.pro -spec win32-g++ "CONFIG-=qml_debug" "CONFIG+=qtquickcompiler" "CONFIG-=separate_debug_info"

qmake_all: FORCE

make_first: release-make_first debug-make_first  FORCE
all: release-all debug-all  FORCE
clean: release-clean debug-clean  FORCE
distclean: release-distclean debug-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash

check: first

benchmark: first
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile
