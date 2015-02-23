#ifndef TOOLBAR_H
#define TOOLBAR_H

class RotoToolbar :
        public QVBoxLayout{
public:
    RotoToolbar(){
        QLabel *titrebox = new QLabel("OUTILS");
        QPushButton *crayon = new QPushButton("crayon");
        crayon->setMaximumWidth(50);
        QPushButton *gomme = new QPushButton("gomme");
        gomme->setMaximumWidth(50);
        QComboBox *tailleCray = new QComboBox;
        tailleCray->addItem("fin");
        tailleCray->addItem("normal");
        tailleCray->addItem("gros");
        tailleCray->addItem("tres gros");
        tailleCray->setMaximumWidth(50);
        QPushButton *dessin = new QPushButton("dessin");
        dessin->setMaximumWidth(50);
        QPushButton *decor = new QPushButton("decor");
        decor->setMaximumWidth(50);

        this->addWidget(titrebox);
        this->addWidget(crayon);
        this->addWidget(gomme);
        this->addWidget(tailleCray);
        this->addWidget(dessin);
        this->addWidget(decor);
    }
};

#endif // TOOLBAR_H

