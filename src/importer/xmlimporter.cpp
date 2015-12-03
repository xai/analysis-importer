#include "xmlimporter.h"
#include "xmltojsonhandler.h"

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
        throw std::runtime_error("DB Handler not yet implemented.");
    } else {
        throw std::runtime_error("No handler found.");
    }

    xmlReader.setContentHandler(handler);
    xmlReader.setErrorHandler(handler);

    if (!xmlReader.parse(source)) {
        throw std::runtime_error("Parsing failed.");
    }
}

}
