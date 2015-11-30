#ifndef IMPORTER_H
#define IMPORTER_H

#include <QTextStream>

namespace analysisimporter {

class Importer
{
public:
    Importer();
    virtual ~Importer();

    virtual void import(QTextStream *input) = 0;
};

}

#endif // IMPORTER_H
