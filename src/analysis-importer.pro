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
    importer/xmltojsonhandler.cpp \
    config.cpp \
    data/project.cpp \
    data/mergescenario.cpp

HEADERS += \
    analysisimporter.h \
    importer/importer.h \
    importer/xmlimporter.h \
    importer/xmltojsonhandler.h \
    config.h \
    data/project.h \
    data/mergescenario.h

