#ifndef PROJECT_H
#define PROJECT_H

#include <QString>

namespace analysisimporter {

class Project
{
public:
    Project(QString name, QString url);

private:
    QString name;
    QString url;
};

}

#endif // PROJECT_H
