#include "config.h"

namespace analysisimporter {

Config::Config()
{

}

Config::~Config()
{

}

QString Config::str()
{
    QString s;
    if (db) {
        s.append("DBHOST=\"" + dbhost + "\"");
        s.append("; DBPORT=\"" + dbuser + "\"");
        s.append("; DBUSER=\"" + dbuser + "\"");
    } else {
        s.append("JSON");
    }

    return s;
}

bool Config::isJSON()
{
    return json;
}

bool Config::isDB()
{
    return db;
}

void Config::setJSON(bool value)
{
    this->json = value;
}

void Config::setDB(bool value)
{
    this->db = value;
}

}
