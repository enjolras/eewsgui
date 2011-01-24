ewscreation.target = eews/eews.h
eewscreation.commands = "wsdl2h -o eews/eews.h eewsadm.wsdl"
eewsdefinition.target = serviceHeaders.h
unix {
    eewsdefinition.commands = "soapcpp2 -2 -C -i -I/usr/share/gsoap/import -d eews eews/eews.h"
}
win32 {
    eewsdefinition.commands = "soapcpp2 -2 -C -i -I/dev/gsoap/gsoap/import -d eews eews/eews.h"
}
eewsdefinition.depends = eewscreation
QMAKE_EXTRA_UNIX_TARGETS += eewscreation eewsdefinition

SOURCES += main.cpp \
 mainWindow.cpp \
	eews/soapeewsadmProxy.cpp \
	eews/soapC.cpp \
 stdsoap2.cpp \
 eewsadmObject.cpp \
 connectDialog.cpp \
 serversDialog.cpp \
 aboutServerDialog.cpp \
 mainWidget.cpp \
 addEditServer.cpp \
 genericTab.cpp \
 pluginFieldsTab.cpp \
 pluginField.cpp \
 pluginFieldString.cpp \
 pluginFieldInt.cpp \
 pluginFieldBool.cpp \
 aboutBox.cpp \
 addEditLanguage.cpp \
 statusTab.cpp \
 queueWidget.cpp \
 preferencesWidget.cpp \
 serverConfigWidget.cpp \
 databaseConfigWidget.cpp \
 cacheConfigWidget.cpp \
 languagesConfigWidget.cpp \
 configWidget.cpp \
 pluginsConfigWidget.cpp \
 serverTab.cpp \
 percentDial.cpp

TEMPLATE = app
CONFIG += warn_on \
	  thread \
          qt \
 debug

win32 {
    CONFIG -= debug
}

TARGET = ../bin/eewsgui

PRE_TARGETDEPS += serviceHeaders.h

QMAKE_CLEAN += eews/*

QT += network
FORMS += mainWindow.ui \
 connectDialog.ui \
 serversDialog.ui \
 aboutServerDialog.ui \
 mainWidget.ui \
 addEditServer.ui \
 genericTab.ui \
 pluginField.ui \
 pluginFieldsTab.ui \
 aboutBox.ui \
 addEditLanguage.ui \
 statusTab.ui \
 queueWidget.ui \
 preferencesWidget.ui \
 serverConfigWidget.ui \
 databaseConfigWidget.ui \
 cacheConfigWidget.ui \
 languagesConfigWidget.ui \
 pluginsConfigWidget.ui \
 serverTab.ui

HEADERS += mainWindow.h \
 stdsoap2.h \
 eewsadmObject.h \
 connectDialog.h \
 serversDialog.h \
 aboutServerDialog.h \
 mainWidget.h \
 addEditServer.h \
 genericTab.h \
 pluginFieldsTab.h \
 pluginField.h \
 pluginFieldString.h \
 pluginFieldBool.h \
 pluginFieldInt.h \
 aboutBox.h \
 addEditLanguage.h \
 statusTab.h \
 queueWidget.h \
 preferencesWidget.h \
 serverConfigWidget.h \
 databaseConfigWidget.h \
 cacheConfigWidget.h \
 languagesConfigWidget.h \
 configWidget.h \
 pluginsConfigWidget.h \
 serverTab.h \
 percentDial.h


RESOURCES += eewsgui.qrc

INCLUDEPATH += eews/

unix {
	INCLUDEPATH += /usr/include/qwt5
	LIBS += -lqwt
}

win32 {
	INCLUDEPATH += /Qwt-5.2.0/include
	LIBS += -lws2_32 -L/Qwt-5.2.0/lib -lqwt5
	RC_FILE = myapp.rc
}


TRANSLATIONS += translations/es.ts

