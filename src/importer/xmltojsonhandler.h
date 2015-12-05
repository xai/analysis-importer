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
