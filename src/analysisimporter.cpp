/**
 * Copyright (C) 2015: Olaf Lessenich
 *
 * This file is part of AnalysisImporter.
 * 
 * AnalysisImporter is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * AnalysisImporter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with AnalysisImporter.  If not, see <http://www.gnu.org/licenses/>.
 */

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
