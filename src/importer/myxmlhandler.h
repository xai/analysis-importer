#ifndef MYXMLHANDLER_H
#define MYXMLHANDLER_H

#include <QtXml>

namespace analysisimporter {

class MyXmlHandler : public QXmlDefaultHandler
{
public:
    MyXmlHandler();
    virtual ~MyXmlHandler();

    bool startElement(const QString & namespaceURI, const QString & localName, const QString & qName, const QXmlAttributes & atts);

};

}

#endif // MYXMLHANDLER_H
