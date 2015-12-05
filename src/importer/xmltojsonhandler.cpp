#include "xmltojsonhandler.h"
#include <QTextStream>

namespace analysisimporter {

XmlToJSONHandler::XmlToJSONHandler()
{

}

XmlToJSONHandler::~XmlToJSONHandler()
{

}

QString XmlToJSONHandler::indent()
{
    QString s = "";

    for (int i = 0; i < indentation; i++) {
        s.append(" ");
    }

    return s;
}

bool XmlToJSONHandler::startDocument()
{
    QTextStream(stdout) << "{" << endl;
    indentation += 4;
    return true;
}

bool XmlToJSONHandler::endDocument()
{
    indentation -= 4;
    QTextStream(stdout) << "}" << endl;
    return true;
}

bool XmlToJSONHandler::startElement(const QString & namespaceURI, const QString & localName, const QString & qName, const QXmlAttributes & atts)
{
    QTextStream out(stdout);
    out << indent() << "\"" << localName << "\": {" << endl;

    indentation += 4;

    for (int i = 0 ; i < atts.length(); i++) {
        out << indent()
            << "\"" << atts.localName(i) << "\": "
            << "\"" << atts.value(i) << "\"";

        if (i != atts.length() - 1) {
            out << ",";
        }

        out << endl;
    }

    return true;
}

bool XmlToJSONHandler::endElement(const QString & namespaceURI, const QString & localName, const QString & qName)
{
    indentation -= 4;
    QTextStream(stdout) << indent() << "}," << endl;

    return true;
}

bool XmlToJSONHandler::characters(const QString &str)
{
    QString content = str.trimmed();

    if (content != "") {
        QTextStream(stdout) << indent() << "\"Content\": " << "\"" << content << "\"" << endl;
    }

    return true;
}

}
