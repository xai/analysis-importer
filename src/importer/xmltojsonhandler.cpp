#include "xmltojsonhandler.h"
#include <iostream>

namespace analysisimporter {

XmlToJSONHandler::XmlToJSONHandler()
{

}

XmlToJSONHandler::~XmlToJSONHandler()
{

}

std::string XmlToJSONHandler::indent()
{
    QString s = "";

    for (int i = 0; i < indentation; i++) {
        s.append(" ");
    }

    return s.toStdString();
}

bool XmlToJSONHandler::startDocument()
{
    std::cout << "{" << std::endl;
    indentation += 4;
    return true;
}

bool XmlToJSONHandler::endDocument()
{
    indentation -= 4;
    std::cout << "}" << std::endl;
    return true;
}

bool XmlToJSONHandler::startElement(const QString & namespaceURI, const QString & localName, const QString & qName, const QXmlAttributes & atts)
{
    std::cout << indent() << "\"" << qPrintable(localName) << "\": {" << std::endl;

    indentation += 4;

    for (int i = 0 ; i < atts.length(); i++) {
        std::cout << indent()
                  << "\"" << qPrintable(atts.localName(i)) << "\": "
                  << "\"" << qPrintable(atts.value(i)) << "\"";

        if (i != atts.length() - 1) {
            std::cout << ",";
        }

        std::cout << std::endl;
    }

    return true;
}

bool XmlToJSONHandler::endElement(const QString & namespaceURI, const QString & localName, const QString & qName)
{
    indentation -= 4;
    std::cout << indent() << "}," << std::endl;

    return true;
}

bool XmlToJSONHandler::characters(const QString &str)
{
    QString content = str.trimmed();

    if (content != "") {
        std::cout << indent() << "\"Content\": " << "\"" << qPrintable(content) << "\"" << std::endl;
    }

    return true;
}

}
