#include <QString>

namespace analysisimporter {

/* Statements to initialize database schema */

const QString DB_CREATE_TABLE_PROJECTS(
        "CREATE TABLE projects ( "
        "  id            INTEGER PRIMARY KEY, "
        "  name          VARCHAR NOT NULL, "
        "  url           VARCHAR NOT NULL"
        ")");

const QString DB_CREATE_TABLE_COMMITS(
        "CREATE TABLE commits ( "
        "  id            INTEGER PRIMARY KEY, "
        "  project       INTEGER NOT NULL, "
        "  commit        VARCHAR NOT NULL"
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

}
