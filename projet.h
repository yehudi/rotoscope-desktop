#ifndef PROJET_H
#define PROJET_H

#include <QString>

class Projet
{

public:
    Projet();
    Projet(QString nomP, QString nomV);
    ~Projet();
    QString *nomProjet;
    QString *nomVideo;
protected:
   // QString *nomProjet;
   // QString *nomVideo;
};

#endif // PROJET_H
