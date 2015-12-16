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


#include "xmltodbhandler.h"

namespace analysisimporter {

XmlToDBHandler::XmlToDBHandler()
{
    dbmanager = new DBManager();
    dbmanager->connect();
}

XmlToDBHandler::~XmlToDBHandler()
{
    delete dbmanager;
}

bool XmlToDBHandler::startDocument()
{
    return true;
}

bool XmlToDBHandler::endDocument()
{
    return true;
}

bool XmlToDBHandler::startElement(const QString & namespaceURI, const QString & localName, const QString & qName, const QXmlAttributes & atts)
{
    if (localName == "project") {
        project = new Project();

        for (int i = 0 ; i < atts.length(); i++) {
            if (atts.localName(i) == "name") {
                project->setName(atts.value(i));
            } else if (atts.localName(i) == "url") {
                project->setUrl(atts.value(i));
            }

        }
    }

    return true;
}

bool XmlToDBHandler::endElement(const QString & namespaceURI, const QString & localName, const QString & qName)
{
    if (localName == "project") {
        QTextStream(stdout) << "Store project: " << project->print() << endl;
        delete project;
    }

    return true;
}

bool XmlToDBHandler::characters(const QString &str)
{
    // QString content = str.trimmed();

    // if (content != "") {
    //     QTextStream(stdout) << indent() << "\"Content\": " << "\"" << content << "\"" << endl;
    // }

    return true;
}

}
