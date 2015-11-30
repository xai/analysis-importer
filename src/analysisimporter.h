#ifndef ANALYSISIMPORTER_H
#define ANALYSISIMPORTER_H

#include <QCoreApplication>
#include <QTextStream>

namespace analysisimporter {

class AnalysisImporter : public QCoreApplication
{
public:
    explicit AnalysisImporter(int &argc, char **argv);

    int run();

private:
    void import(QTextStream *in);
};

}

#endif // ANALYSISIMPORTER_H
