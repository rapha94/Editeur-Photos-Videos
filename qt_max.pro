#-------------------------------------------------
#
# Project created by QtCreator 2016-12-07T16:16:11
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets \

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_ui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    control.cpp \
    model.cpp \
    filtrage.cpp

HEADERS  += mainwindow.h \
    control.h \
    model.h \
    filtrage.h

FORMS    += mainwindow.ui

RESOURCES += \
    ressource.qrc
