#ifndef XMLIMPORTER_H
#define XMLIMPORTER_H

#include "importer.h"

namespace analysisimporter {

class XMLImporter : public Importer
{
public:
    XMLImporter();
    virtual ~XMLImporter();

    virtual void import(QTextStream *input) override;
};

}

#endif // XMLIMPORTER_H
