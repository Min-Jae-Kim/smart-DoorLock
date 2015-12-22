#-------------------------------------------------
#
# Project created by QtCreator 2015-11-26T18:31:11
#
#-------------------------------------------------

QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = interface
TEMPLATE = app


SOURCES += main.cpp\
        lcd_show.cpp \
    message.cpp \
    vibration.c \
    door.cpp \
    checkmemo.cpp \
    memothread.cpp \
    setting.cpp \
    weatherthread.cpp \
    screensaver.cpp \
    dooropenthread.cpp
LIBS    += -lwiringPi
HEADERS  += lcd_show.h \
    message.h \
    vibration.h \
    door.h \
    checkmemo.h \
    memothread.h \
    setting.h \
    weatherthread.h \
    screensaver.h \
    dooropenthread.h

FORMS    += lcd_show.ui \
    message.ui \
    door.ui \
    checkmemo.ui \
    setting.ui \
    screensaver.ui
