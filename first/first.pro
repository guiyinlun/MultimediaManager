#-------------------------------------------------
#
# Project created by QtCreator 2022-04-23T20:12:46
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = frist
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
        main.cpp \
        first.cpp \
    welcome.cpp \
    join.cpp \
    vvideo.cpp \
    photos.cpp \
    gplayer.cpp \
    playerdh.cpp \
    photodh.cpp

HEADERS += \
        first.h \
    welcome.h \
    join.h \
    vvideo.h \
    photos.h \
    gplayer.h \
    playerdh.h \
    photodh.h

FORMS += \
        first.ui \
    welcome.ui \
    join.ui \
    photos.ui \
    gplayer.ui \
    playerdh.ui \
    photodh.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

DISTFILES += \
    ../Login/image/y1.png \
    ../Login/image/y2.png \
    ../Login/image/x1.jpg \
    ../Login/image/x2.jpg \
    ../Login/image/ytj1.jpg \
    ../Login/image/ytj2.jfif \
    ../Login/image/y1.png \
    ../Login/image/y2.png \
    ../Login/image/x1.jpg \
    ../Login/image/x2.jpg \
    ../Login/image/ytj1.jpg \
    ../Login/image/ytj2.jfif \
    ../Login/image/y1.png \
    ../Login/image/y2.png \
    ../Login/image/qk.png \
    ../Login/image/sc.png \
    ../Login/image/tj.png \
    ../Login/image/bf.png \
    ../Login/image/sj.png \
    ../Login/image/sx.png \
    ../Login/image/sys.png \
    ../Login/image/xys.png \
    ../Login/image/zt.png \
    ../Login/image/qk.png \
    ../Login/image/sc.png \
    ../Login/image/tj.png \
    ../Login/image/bf.png \
    ../Login/image/sj.png \
    ../Login/image/sx.png \
    ../Login/image/sys.png \
    ../Login/image/xys.png \
    ../Login/image/zt.png
