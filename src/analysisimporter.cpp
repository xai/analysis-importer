#include "analysisimporter.h"
#include "importer/xmlimporter.h"

#include <iostream>
#include <QCommandLineParser>
#include <QtDebug>

namespace analysisimporter {

enum CommandLineParseResult
{
    CommandLineOk,
    CommandLineError,
    CommandLineVersionRequested,
    CommandLineHelpRequested
};

CommandLineParseResult parseCommandLine(QCommandLineParser &parser, QString *config, QString *errorMessage) {

    // TODO: Add options to configure database connection.

    const QCommandLineOption helpOption = parser.addHelpOption();
    const QCommandLineOption versionOption = parser.addVersionOption();

    if (!parser.parse(QCoreApplication::arguments())) {
        return CommandLineError;
    } else if (parser.isSet(versionOption)) {
        return CommandLineVersionRequested;
    } else if (parser.isSet(helpOption)) {
        return CommandLineHelpRequested;
    }

    return CommandLineOk;
}

AnalysisImporter::AnalysisImporter(int &argc, char **argv) : QCoreApplication(argc, argv)
{
    setApplicationName("Analysis-Importer");
    setApplicationVersion("0.0.1");
}

int AnalysisImporter::run()
{
    QCommandLineParser parser;
    parser.setApplicationDescription("Import repository analysis into database.");

    QString config;
    QString errorMessage;

    switch(parseCommandLine(parser, &config, &errorMessage)) {
    case CommandLineOk:
        break;
    case CommandLineError:
        fputs(qPrintable(errorMessage), stderr);
        fputs("\n\n", stderr);
        fputs(qPrintable(parser.helpText()), stderr);
        return 1;
    case CommandLineVersionRequested:
        printf("%s %s\n", qPrintable(QCoreApplication::applicationName()), qPrintable(QCoreApplication::applicationVersion()));
        return 0;
    case CommandLineHelpRequested:
        parser.showHelp();
        Q_UNREACHABLE();
    }

#ifdef QT_DEBUG
    qDebug() << "Database configuration: " << config;
#endif

    QTextStream in(stdin);

    XMLImporter importer;
    importer.import(&in);

    return 0;
}

}
