#-------------------------------------------------
#
# Project created by QtCreator 2018-12-06T16:20:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QWaitCondition
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Producer.cpp \
    Consumer.cpp \
    global.cpp

HEADERS  += mainwindow.h \
    Producer.h \
    global.h \
    Consumer.h

FORMS    += mainwindow.ui
