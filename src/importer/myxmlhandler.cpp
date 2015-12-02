#include "myxmlhandler.h"
#include <iostream>

namespace analysisimporter {

MyXmlHandler::MyXmlHandler()
{

}

MyXmlHandler::~MyXmlHandler()
{

}

bool MyXmlHandler::startElement(const QString & namespaceURI, const QString & localName, const QString & qName, const QXmlAttributes & atts)
{
    std::cout << "Found tag: " << qPrintable(localName) << std::endl;
    std::cout << "Attributes:" << std::endl;

    for (int i = 0 ; i < atts.length(); i++) {
        std::cout << qPrintable(atts.type(i)) << "="
                  << qPrintable(atts.value(i)) << std::endl;
    }

    std::cout << std::endl;

    return true;
}

}
