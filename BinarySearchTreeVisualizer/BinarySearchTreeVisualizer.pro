#-------------------------------------------------
#
# Project created by QtCreator 2019-11-16T05:26:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BinarySearchTreeVisualizer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        binarysearchtree.cpp \
        console.cpp \
        graphicscircle.cpp \
        graphicsscene.cpp \
        graphicsview.cpp \
        main.cpp \
        mainwindow.cpp \
        node.cpp

HEADERS += \
        binarysearchtree.h \
        console.h \
        graphicscircle.h \
        graphicsscene.h \
        graphicsview.h \
        mainwindow.h \
        node.h \
        util.h

FORMS += \
        mainwindow.ui

RC_ICONS = BinarySearchTreeVisualizer32.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    icon.qrc
