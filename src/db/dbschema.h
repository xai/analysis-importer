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

#ifndef DBSCHEMA_H
#define DBSCHEMA_H

#include <QString>

namespace analysisimporter {

/* Statements to initialize database schema */

const QString DB_CREATE_TABLE_PROJECTS(
        "CREATE TABLE projects ( "
        "  id            INTEGER PRIMARY KEY, "
        "  name          VARCHAR NOT NULL, "
        "  url           VARCHAR NOT NULL, "
        "  latest        DATETIME"
        ")");

const QString DB_CREATE_TABLE_REVISIONS(
        "CREATE TABLE revisions ( "
        "  id            INTEGER PRIMARY KEY, "
        "  project       INTEGER NOT NULL, "
        "  revision        VARCHAR NOT NULL, "
        "  timestamp     DATETIME"
        ")");

const QString DB_CREATE_TABLE_MERGESCENARIOS(
        "CREATE TABLE mergescenarios ( "
        "  id            INTEGER PRIMARY KEY, "
        "  project       INTEGER NOT NULL, "
        "  revision        INTEGER NOT NULL"
        ")");

const QString DB_CREATE_TABLE_PARENTREVISIONS(
        "CREATE TABLE parentrevisions ( "
        "  id            INTEGER PRIMARY KEY, "
        "  revision        INTEGER NOT NULL, "
        "  parent        INTEGER NOT NULL"
        ")");

const QString DB_CREATE_TABLE_FILES(
        "CREATE TABLE files ( "
        "  id            INTEGER PRIMARY KEY, "
        "  revision        INTEGER NOT NULL, "
        "  path          VARCHAR NOT NULL"
        ")");

const QString DB_CREATE_TABLE_CONFLICTS(
        "CREATE TABLE conflicts ( "
        "  id            INTEGER PRIMARY KEY, "
        "  mergescenario INTEGER NOT NULL, "
        "  file          INTEGER NOT NULL"
        ")");

/* TODO: Tables for statistics */
const QString DB_CREATE_TABLE_MERGESTATS = "";
const QString DB_CREATE_TABLE_BUILDSTATS = "";
const QString DB_CREATE_TABLE_TESTSTATS = "";

/* Statements to manage projects */

const QString DB_FIND_PROJECT_BY_ID(
        "SELECT id from projects "
        "WHERE id = :id");

const QString DB_FIND_PROJECT_BY_NAME(
        "SELECT id from projects "
        "WHERE name = :name");

const QString DB_FIND_PROJECT_BY_URL(
        "SELECT id from projects "
        "WHERE url = :url");

const QString DB_ADD_PROJECT(
        "INSERT INTO projects (name, url, latest) "
        "VALUES (:name, :url, :latest)");

const QString DB_UPDATE_PROJECT(
        "UPDATE projects SET "
        "  name   = :name, "
        "  url    = :url, "
        "  latest = :latest "
        "WHERE id = :id");

const QString DB_DELETE_PROJECT(
        "DELETE from projects "
        "WHERE id = :id");

/* Statements to manage revisions */

const QString DB_FIND_REVISION_BY_ID(
        "SELECT id from revisions "
        "WHERE id = :id");

const QString DB_FIND_REVISION_BY_PROJECT(
        "SELECT id from revisions "
        "WHERE project = :project");

const QString DB_FIND_REVISION_BY_REVISION(
        "SELECT id from revisions "
        "WHERE revision = :revision");

const QString DB_ADD_REVISION(
        "INSERT INTO revisions (project, revision, timestamp) "
        "VALUES (:project, :revision, :timestamp)");

const QString DB_UPDATE_REVISION(
        "UPDATE revisions SET "
        "  project   = :project, "
        "  revision    = :revision, "
        "  timestamp = :timestamp "
        "WHERE id = :id");

const QString DB_DELETE_REVISION(
        "DELETE from revisions "
        "WHERE id = :id");

/* Statements to manage mergescenarios */

const QString DB_FIND_MERGESCENARIO_BY_ID(
        "SELECT id from mergescenarios "
        "WHERE id = :id");

const QString DB_FIND_MERGESCENARIO_BY_PROJECT(
        "SELECT id from mergescenarios "
        "WHERE project = :project");

const QString DB_FIND_MERGESCENARIO_BY_REVISION(
        "SELECT id from mergescenarios "
        "WHERE revision = :revision");

const QString DB_FIND_MERGESCENARIO_BY_PROJECT_AND_REVISION(
        "SELECT id from mergescenarios "
        "WHERE project = :project "
        "AND   revision = :revision");

const QString DB_ADD_MERGESCENARIO(
        "INSERT INTO mergescenarios (project, revision) "
        "VALUES (:project, :revision)");

const QString DB_UPDATE_MERGESCENARIO(
        "UPDATE mergescenarios SET "
        "  project   = :project, "
        "  revision    = :revision "
        "WHERE id = :id");

const QString DB_DELETE_MERGESCENARIO(
        "DELETE from mergescenario "
        "WHERE id = :id");

/* Statements to manage parent revisions */

const QString DB_FIND_PARENTREVISION_BY_ID(
        "SELECT id from parentrevisions "
        "WHERE id = :id");

const QString DB_FIND_PARENTREVISION_BY_REVISION(
        "SELECT id from parentrevisions "
        "WHERE revision = :revision");

const QString DB_FIND_PARENTREVISION_BY_REVISION_AND_PARENT(
        "SELECT id from parentrevisions "
        "WHERE revision = :revision "
        "AND   parent = :parent");

const QString DB_ADD_PARENTREVISION(
        "INSERT INTO parentrevisions (revision, parent) "
        "VALUES (:revision, :parent)");

const QString DB_UPDATE_PARENTREVISION(
        "UPDATE parentrevisions SET "
        "  revision = :revision, "
        "  parent = :parent "
        "WHERE id = :id");

const QString DB_DELETE_PARENTREVISION(
        "DELETE from parentrevisions "
        "WHERE id = :id");

/* Statements to manage files */

const QString DB_FIND_FILE_BY_ID(
        "SELECT id from files "
        "WHERE id = :id");

const QString DB_FIND_FILE_BY_REVISION(
        "SELECT id from files "
        "WHERE revision = :revision");

const QString DB_FIND_FILE_BY_PATH(
        "SELECT id from files "
        "WHERE path = :path");

const QString DB_FIND_FILE_BY_REVISION_AND_PATH(
        "SELECT id from files "
        "WHERE revision = :revision "
        "AND   path = :path");

const QString DB_ADD_FILE(
        "INSERT INTO files (revision, path) "
        "VALUES (:revision, :path)");

const QString DB_UPDATE_FILE(
        "UPDATE parentrevisions SET "
        "  revision = :revision, "
        "  path   = :path "
        "WHERE id = :id");

const QString DB_DELETE_FILE(
        "DELETE from files "
        "WHERE id = :id");

/* Statements to manage conflicts */

const QString DB_FIND_CONFLICT_BY_ID(
        "SELECT id from conflicts "
        "WHERE id = :id");

const QString DB_FIND_CONFLICT_BY_MERGESCENARIO(
        "SELECT id from conflicts "
        "WHERE mergescenario = :mergescenario");

const QString DB_FIND_CONFLICT_BY_FILE(
        "SELECT id from conflicts "
        "WHERE file = :file");

const QString DB_FIND_CONFLICT_BY_MERGESCENARIO_AND_FILE(
        "SELECT id from conflicts "
        "WHERE mergescenario = :mergescenario "
        "AND   file = :file");

const QString DB_ADD_CONFLICT(
        "INSERT INTO conflicts (mergescenario, file) "
        "VALUES (:mergescenario, :file)");

const QString DB_UPDATE_CONFLICT(
        "UPDATE mergescenarios SET "
        "  mergescenario = :mergescenario, "
        "  file          = :file "
        "WHERE id = :id");

const QString DB_DELETE_CONFLICT(
        "DELETE from conflicts "
        "WHERE id = :id");

}

#endif // DBSCHEMA_H
