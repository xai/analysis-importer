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
#include <QDebug>

namespace analysisimporter {

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
}

bool DBManager::disconnect()
{
#ifdef QT_DEBUG
    qDebug() << "DBManager.disconnect()";
#endif
}

QString DBManager::getDBLocation()
{
    return dblocation;
}

void DBManager::setDBLocation(const QString &path)
{
    dblocation = path;
}

}