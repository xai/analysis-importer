#ifndef MERGESCENARIO_H
#define MERGESCENARIO_H

#include <QString>
#include <QList>

namespace analysisimporter {

typedef QString Commit;

class MergeScenario
{
public:
    MergeScenario(Commit commit, QList<Commit> parents);

private:
    Commit commit;
    QList<Commit> parents;
};

}

#endif // MERGESCENARIO_H
