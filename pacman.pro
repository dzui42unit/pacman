#-------------------------------------------------
#
# Project created by QtCreator 2017-10-04T22:24:00
#
#-------------------------------------------------

QT       += core gui \

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pacman
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


SOURCES += \
	main.cpp \
    gameclass.cpp \
    blinky.cpp \
    pacman.cpp \
    pinky.cpp \
    ghost.cpp \
    clyde.cpp \
    inky.cpp

HEADERS += \
    gameclass.h \
    pacman.h \
    blinky.h \
    pinky.h \
    ghost.h \
    clyde.h \
    inky.h

RESOURCES += \
    qrc.qrc
