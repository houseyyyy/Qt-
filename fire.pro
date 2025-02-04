#-------------------------------------------------
#
# Project created by QtCreator 2024-07-04T16:15:18
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fire
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
RC_ICONS = myico.ico
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += resources_big
SOURCES += \
        QtSplashScreen.cpp \
        box.cpp \
        client.cpp \
        gameengine.cpp \
        gamemenu.cpp \
        human.cpp \
        main.cpp \
        server.cpp

HEADERS += \
        Human.h \
        QtSplashScreen.h \
        box.h \
        client.h \
        config.h \
        gameengine.h \
        gamemenu.h \
        server.h

FORMS += \
        gameengine.ui \
        gamemenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
