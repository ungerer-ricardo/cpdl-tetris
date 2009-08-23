# -------------------------------------------------
# Project created by QtCreator 2009-07-28T09:36:09
# -------------------------------------------------
QT += network \
    testlib
QT -= gui
TARGET = tests
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += testserver.cpp \
    ../ouvinte.cpp \
    ../roteador.cpp \
    ../jogador.cpp
HEADERS += ../ouvinte.h \
    ../roteador.h \
    ../jogador.h
