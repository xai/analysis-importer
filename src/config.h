#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

namespace analysisimporter {

class Config
{
public:
    Config();
    ~Config();
    QString str();
    bool isJSON();
    bool isDB();
    void setJSON(bool value);
    void setDB(bool value);

private:
    bool json = false;
    bool db = false;
    QString dbhost = "";
    QString dbport = "";
    QString dbuser = "";
    QString dbpasswd = "";
};

}

#endif // CONFIG_H
