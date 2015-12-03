#ifndef IMPORTER_H
#define IMPORTER_H

#include "config.h"
#include <QTextStream>

namespace analysisimporter {

class Importer
{
public:
    Importer(Config *config);
    virtual ~Importer();

    virtual void import(QTextStream *input) = 0;

protected:
    Config *config;
};

}

#endif // IMPORTER_H
