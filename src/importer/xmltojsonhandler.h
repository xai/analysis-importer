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

#ifndef XMLTOJSONHANDLER_H
#define XMLTOJSONHANDLER_H

#include <QtXml>

namespace analysisimporter {

class XmlToJSONHandler : public QXmlDefaultHandler
{
public:
    XmlToJSONHandler();
    virtual ~XmlToJSONHandler();

    bool startDocument();

    bool endDocument();

    bool startElement(const QString & namespaceURI, const QString & localName, const QString & qName, const QXmlAttributes & atts);

    bool endElement(const QString & namespaceURI, const QString & localName, const QString & qName);

    bool characters(const QString &str);

private:
    int indentation = 0;
    QString indent();
};

}

#endif // XMLTOJSONHANDLER_H
