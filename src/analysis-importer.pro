#
# Copyright (C) 2015: Olaf Lessenich
#
# This file is part of AnalysisImporter.
# 
# AnalysisImporter is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# AnalysisImporter is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with AnalysisImporter.  If not, see <http://www.gnu.org/licenses/>.
#

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
    data/mergescenario.cpp \
    importer/dbschema.cpp

HEADERS += \
    analysisimporter.h \
    importer/importer.h \
    importer/xmlimporter.h \
    importer/xmltojsonhandler.h \
    config.h \
    data/project.h \
    data/mergescenario.h

