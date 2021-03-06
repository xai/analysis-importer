/**
 * Copyright (C) 2015: Olaf Lessenich
 *
 * This file is part of AnalysisImporter.
 * 
 * AnalysisImporter is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * AnalysisImporter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with AnalysisImporter.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "xmlimporter.h"
#include "xmltojsonhandler.h"
#include "xmltodbhandler.h"

#include <QtDebug>
#include <QXmlSimpleReader>
#include <QXmlInputSource>
#include <QXmlDefaultHandler>
#include <stdexcept>

namespace analysisimporter {

XMLImporter::XMLImporter(Config *config) : Importer::Importer(config)
{

}

XMLImporter::~XMLImporter()
{

}

void XMLImporter::import(QTextStream *input)
{
    QXmlInputSource *source = new QXmlInputSource;
    source->setData(input->readAll());

    QXmlSimpleReader xmlReader;
    QXmlDefaultHandler *handler;

    if (config->isJSON()) {
        handler = new XmlToJSONHandler;
    } else if (config->isDB()) {
        handler = new XmlToDBHandler;
    } else {
        throw std::runtime_error("No handler found.");
    }

    xmlReader.setContentHandler(handler);
    xmlReader.setErrorHandler(handler);

    if (!xmlReader.parse(source)) {
        throw std::runtime_error("Parsing failed.");
    }

    delete handler;
    delete source;
}

}
