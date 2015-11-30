#include "xmlimporter.h"

#include <QtDebug>

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
}

}
