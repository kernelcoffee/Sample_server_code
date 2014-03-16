#-------------------------------------------------
#
# Project created by QtCreator 2014-03-15T17:43:21
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    tcpserver.cpp \
    processthread.cpp

HEADERS += \
    tcpserver.h \
    processthread.h
