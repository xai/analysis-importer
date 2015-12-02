#include "xmlimporter.h"
#include "myxmlhandler.h"

#include <QtDebug>
#include <QXmlSimpleReader>
#include <QXmlInputSource>

namespace analysisimporter {

XMLImporter::XMLImporter()
{

}

XMLImporter::~XMLImporter()
{

}

void XMLImporter::import(QTextStream *input)
{
#ifdef QT_DEBUG
    qDebug() << "Processing XML input:";
    qDebug() << "--------------------------------------------------";
    while (!input->atEnd()) {
        qDebug() << qPrintable(input->readLine());
    }
    qDebug() << "--------------------------------------------------";
#endif

    // TODO: parse xml and store objects in database
    QXmlInputSource *source = new QXmlInputSource;
    source->setData(input->readAll());

    QXmlSimpleReader xmlReader;
    MyXmlHandler *handler = new MyXmlHandler;
    xmlReader.setContentHandler(handler);
    xmlReader.setErrorHandler(handler);
}

}
