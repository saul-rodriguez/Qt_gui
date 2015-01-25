#-------------------------------------------------
#
# Project created by QtCreator 2015-01-11T09:53:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt_gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

LIBS += -lwiringPi

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
