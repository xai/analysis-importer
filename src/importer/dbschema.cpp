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

const QString DB_CREATE_TABLE_COMMITS(
        "CREATE TABLE commits ( "
        "  id            INTEGER PRIMARY KEY, "
        "  project       INTEGER NOT NULL, "
        "  commit        VARCHAR NOT NULL, "
        "  timestamp     DATETIME"
        ")");

const QString DB_CREATE_TABLE_MERGESCENARIOS(
        "CREATE TABLE mergescenarios ( "
        "  id            INTEGER PRIMARY KEY, "
        "  project       INTEGER NOT NULL, "
        "  commit        INTEGER NOT NULL"
        ")");

const QString DB_CREATE_TABLE_PARENTCOMMITS(
        "CREATE TABLE parentcommits ( "
        "  id            INTEGER PRIMARY KEY, "
        "  commit        INTEGER NOT NULL, "
        "  parent        INTEGER NOT NULL"
        ")");

const QString DB_CREATE_TABLE_FILES(
        "CREATE TABLE files ( "
        "  id            INTEGER PRIMARY KEY, "
        "  commit        INTEGER NOT NULL, "
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

/* Statements to manage commits */

const QString DB_FIND_COMMIT_BY_ID(
        "SELECT id from commits "
        "WHERE id = :id");

const QString DB_FIND_COMMIT_BY_PROJECT(
        "SELECT id from commits "
        "WHERE project = :project");

const QString DB_FIND_COMMIT_BY_COMMIT(
        "SELECT id from commits "
        "WHERE commit = :commit");

const QString DB_ADD_COMMIT(
        "INSERT INTO commits (project, commit, timestamp) "
        "VALUES (:project, :commit, :timestamp)");

const QString DB_UPDATE_COMMIT(
        "UPDATE commits SET "
        "  project   = :project, "
        "  commit    = :commit, "
        "  timestamp = :timestamp "
        "WHERE id = :id");

/* Statements to manage mergescenarios */

const QString DB_FIND_MERGESCENARIO_BY_ID(
        "SELECT id from mergescenarios "
        "WHERE id = :id");

const QString DB_FIND_MERGESCENARIO_BY_PROJECT(
        "SELECT id from mergescenarios "
        "WHERE project = :project");

const QString DB_FIND_MERGESCENARIO_BY_COMMIT(
        "SELECT id from mergescenarios "
        "WHERE mergescenario = :mergescenario");

const QString DB_ADD_MERGESCENARIO(
        "INSERT INTO mergescenarios (project, commit) "
        "VALUES (:project, :commit)");

const QString DB_UPDATE_MERGESCENARIO(
        "UPDATE mergescenarios SET "
        "  project   = :project, "
        "  commit    = :commit, "
        "WHERE id = :id");

/* Statements to manage parent commits */

const QString DB_FIND_PARENTCOMMIT_BY_COMMIT(
        "SELECT id from parentcommits "
        "WHERE commit = :commit");

const QString DB_ADD_PARENTCOMMIT(
        "INSERT INTO parentcommits (commit, parent) "
        "VALUES (:commit, :parent)");

}
