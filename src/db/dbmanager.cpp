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


#include "dbmanager.h"
#include "dbschema.h"
#include <QDebug>
#include <QDir>

namespace analysisimporter {

const QString DB_FILE_NAME("/.analysis-importer.db");

DBManager::DBManager()
{

}

DBManager::~DBManager()
{
    disconnect();
}

bool DBManager::connect()
{
#ifdef QT_DEBUG
    qDebug() << "DBManager.connect()";
#endif

    if (db.isOpen()) {
        return false;
    }

    db = QSqlDatabase::addDatabase("QSQLITE");
    getDBLocation();

#ifdef QT_DEBUG
    qDebug() << "DB location is " << dblocation;
#endif

    db.setDatabaseName(dblocation);
    QSqlError error = initDb(db);

    if (error.type() != QSqlError::NoError) {
#ifdef QT_DEBUG
        qDebug() << error;
#endif
        return false;
    }

    return true;
}

bool DBManager::disconnect()
{
#ifdef QT_DEBUG
    qDebug() << "DBManager.disconnect()";
#endif

    if (!db.isOpen()) {
        return false;
    }

    QString connection = db.connectionName();

    db.close();
    db = QSqlDatabase();
    QSqlDatabase::removeDatabase(connection);
    return true;
}

QString DBManager::getDBLocation()
{
    if (dblocation.isEmpty()) {
        QString dbPath = DB_FILE_NAME;
        dbPath.prepend(QDir::homePath());

        // TODO: add option to use environment variable

        dblocation = dbPath;
    }

    return dblocation;
}

void DBManager::setDBLocation(const QString &path)
{
    dblocation = path;
}

QSqlError DBManager::checkTable(const QString &table, const QStringList &tables, const QString &createStatement)
{
    if (!tables.contains(table, Qt::CaseInsensitive)) {
        QSqlQuery query;

        if (!query.exec(createStatement)) {
            return query.lastError();
        }
    }

    return QSqlError();
}

QSqlError DBManager::initDb(QSqlDatabase &db)
{
    if (!db.open()) {
        return db.lastError();
    }

    QStringList tables = db.tables();
    QSqlError error = checkTable("projects", tables, DB_CREATE_TABLE_PROJECTS);

    if (error.type() != QSqlError::NoError) {
        return error;
    }

    return QSqlError();

}

}
