#include "analysisimporter.h"

using namespace analysisimporter;

int main(int argc, char *argv[])
{
    AnalysisImporter importer(argc, argv);

    return importer.run();
}
