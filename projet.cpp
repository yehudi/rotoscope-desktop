#include "projet.h"

Projet::Projet()
{

}
Projet::Projet(QString nomP, QString nomV)
{
    nomProjet = new QString(nomP);
    nomVideo = new QString(nomV);

}


Projet::~Projet()
{

}

