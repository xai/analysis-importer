#include "analysisimporter.h"
#include "config.h"
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

CommandLineParseResult parseCommandLine(QCommandLineParser &parser, Config *config, QString *errorMessage) {

    QCommandLineOption toJsonOption(QStringList() << "j" << "json",
                                      QCoreApplication::translate("main", "Print JSON."));
    parser.addOption(toJsonOption);

    QCommandLineOption toDBOption(QStringList() << "d" << "database",
                                      QCoreApplication::translate("main", "Store into database."));
    parser.addOption(toDBOption);

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

    config->setJSON(parser.isSet(toJsonOption));
    config->setDB(parser.isSet(toDBOption));

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

    Config config;
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
    qDebug() << "Configuration:" << qPrintable(config.str());
#endif

    QTextStream in(stdin);

    if (config.isDB() || config.isJSON()) {
        XMLImporter importer(&config);
        importer.import(&in);
    } else {
        // do nothing, just dump xml
        QTextStream out(stdout);
        out << in.readAll();
    }

    return 0;
}

}
