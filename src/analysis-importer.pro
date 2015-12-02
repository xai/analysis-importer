QT += core
QT += xml
QT -= gui

TARGET = analysis-importer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS_DEBUG += -std=c++11 -O0
QMAKE_CXXFLAGS_RELEASE += -O3 -march=native -std=c++11

SOURCES += main.cpp \
    analysisimporter.cpp \
    importer/importer.cpp \
    importer/xmlimporter.cpp \
    importer/myxmlhandler.cpp

HEADERS += \
    analysisimporter.h \
    importer/importer.h \
    importer/xmlimporter.h \
    importer/myxmlhandler.h

