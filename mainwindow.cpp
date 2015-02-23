#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    lancement();
    creerActions();
    creerMenus();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lancement()
{
    QWidget *widget = new QWidget(this);

    QVBoxLayout *panel = new QVBoxLayout();
    nouveauButt = new QPushButton("Nouveau Projet");
    nouveauButt->setMinimumSize(350,100);
    connect(nouveauButt, SIGNAL(pressed()),this,SLOT(nouveauProjet()));

    ouvrirButt = new QPushButton("Ouvrir Projet");
    ouvrirButt->setMinimumSize(350,100);
    connect(ouvrirButt, SIGNAL(triggered()),this,SLOT(ouvrirProjet()));
    panel->addWidget(nouveauButt);
    panel->addWidget(ouvrirButt);
    panel->setAlignment(Qt::AlignCenter);
    widget->setLayout(panel);
    setCentralWidget(widget);
}
/*creation des menus */
void MainWindow::creerMenus()
{
    menuFichier = menuBar()->addMenu(tr("&Fichier"));
    menuFichier->addAction(nouveauAct);
    menuFichier->addAction(ouvrirAct);
    menuFichier->addAction(sauvAct);
    menuFichier->addAction(exporterAct);
    menuFichier->addAction(fermerAct);
    menuFichier->addAction(quitterAct);

    menuEdition = menuBar()->addMenu(tr("&Edition"));

    menuPrevi = menuBar()->addMenu(tr("&Previsualisation"));

    menuOptions = menuBar()->addMenu(tr("&Options"));

}

/*creation des sous-menus (actions) */
void MainWindow::creerActions()
{
    nouveauAct = new QAction(tr("&Nouveau Projet"),this);
    nouveauAct->setStatusTip("Creation d'un nouveau projet");
    nouveauAct->setShortcut(QKeySequence(tr("Ctrl+N")));
    connect(nouveauAct, SIGNAL(triggered()),this,SLOT(nouveauProjet()));

    ouvrirAct = new QAction(tr("&Ouvrir Projet"),this);
    ouvrirAct->setStatusTip("Ouverture d'un nouveau projet");
    ouvrirAct->setShortcut(QKeySequence(tr("Ctrl+O")));
    connect(ouvrirAct, SIGNAL(triggered()),this,SLOT(ouvrirProjet()));

    sauvAct = new QAction(tr("&Sauvegarder Projet"),this);
    sauvAct->setStatusTip("Sauvegarde du projet");
    sauvAct->setShortcut(QKeySequence(tr("Ctrl+S")));
    connect(sauvAct, SIGNAL(triggered()),this,SLOT(sauverProjet()));

    exporterAct = new QAction(tr("&Exporter"),this);
    exporterAct->setStatusTip("Exportation du projet");
    exporterAct->setShortcut(QKeySequence(tr("Ctrl+A")));
    connect(sauvAct, SIGNAL(triggered()),this,SLOT(exporterProjet()));

    fermerAct = new QAction(tr("&Fermer Projet"),this);
    fermerAct->setShortcut(QKeySequence(tr("Ctrl+W")));
    connect(fermerAct, SIGNAL(triggered()),this,SLOT(fermerProjet()));


    quitterAct = new QAction(tr("&Quitter"),this);
    quitterAct->setShortcut(QKeySequence(tr("Ctrl+Q")));
    connect(quitterAct, SIGNAL(triggered()),this,SLOT(close()));

}

void MainWindow::nouveauProjet()
{
    QWidget *widget = new QWidget(this);
    /* element de la fenetre */
    QHBoxLayout *simplelay = new QHBoxLayout;

    QVBoxLayout *panelfinal = new QVBoxLayout;

    nom = new QLineEdit;
    nom->setMaximumWidth(200);
    QComboBox *imgParS = new QComboBox;
    imgParS->addItem("6 Img/Sec");
    imgParS->addItem("8 Img/Sec");
    imgParS->addItem("12 Img/Sec");
    imgParS->addItem("24 Img/Sec");
    imgParS->setMaximumWidth(200);
    QPushButton *parcourirButt = new QPushButton("Parcourir");
    parcourirButt->setMaximumWidth(100);


    QHBoxLayout *panelbutt = new QHBoxLayout;
    QPushButton *creerButt = new QPushButton("Creer");
    creerButt->setMaximumWidth(100);
    QPushButton *annulerButt = new QPushButton("Annuler");
    annulerButt->setMaximumWidth(100);
    panelbutt->addWidget(creerButt);
    panelbutt->addWidget(annulerButt);

    nomvideo = new QLineEdit;
    nomvideo->setMaximumWidth(250);
    simplelay->addWidget(nomvideo);
    simplelay->addWidget(parcourirButt);
    /*creation de la fenentre */
    QFormLayout *panelform = new QFormLayout;
    panelform->addRow("Nom du projet", nom);
    panelform->addRow("Nombre d'image par seconde", imgParS);
    panelform->addRow("Video à charger", simplelay);
    panelform->setFormAlignment(Qt::AlignCenter);
    panelfinal->addLayout(panelform);
    panelfinal->addLayout(panelbutt);
    panelfinal->setAlignment(Qt::AlignCenter);
    widget->setLayout(panelfinal);
    setCentralWidget(widget);

    connect(parcourirButt, SIGNAL(pressed()),this,SLOT(parcourirMenu()));
    connect(creerButt, SIGNAL(pressed()),this,SLOT(creerProjet()));
    connect(annulerButt, SIGNAL(pressed()),this,SLOT(lancement()));

}
void MainWindow::parcourirMenu()
{
    QString nomfichier = QFileDialog::getOpenFileName(this,tr("Ouvrir video"),"",tr("Video Files (*.mp4)"));
    nomvideo->setText(nomfichier);
}
void MainWindow::creerProjet()
{

    projCour = new Projet(nom->text(),nomvideo->text());
    creerInterfaceUser();
}

void MainWindow::creerInterfaceUser()
{

    QWidget *widget = new QWidget(this);
    QGridLayout *panelfinal = new QGridLayout;
    creerToolBox();
    creerzonedessin();
    creerzoneoignon();
    panelfinal->addLayout(panelOutil,0,0);
    panelfinal->addLayout(zonedessin,0,2);
    panelfinal->addLayout(zoneoignon,1,0,1,3);
    widget->setLayout(panelfinal);
    this->setCentralWidget(widget);



}
void MainWindow::creerToolBox()
{
    panelOutil = new QVBoxLayout;
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

    panelOutil->addWidget(titrebox);
    panelOutil->addWidget(crayon);
    panelOutil->addWidget(gomme);
    panelOutil->addWidget(tailleCray);
    panelOutil->addWidget(dessin);
    panelOutil->addWidget(decor);

}
void MainWindow::creerzonedessin()
{

    zonedessin = new QHBoxLayout;
    QPushButton *precedent = new QPushButton("<-");
    //precedent->setMaximumSize(50,500);
    QPushButton *suivant = new QPushButton("->");
    //suivant->setMaximumSize(50,500);
    zonedessin->addWidget(precedent);
    zonedessin->addWidget(suivant);
}
void MainWindow::creerzoneoignon()
{

    zoneoignon = new QVBoxLayout;
    QVBoxLayout *panelbouton = new QVBoxLayout;


    QPushButton *affDessin = new QPushButton("Aff. dessin");

    QPushButton *affImage = new QPushButton("Aff. image");
    panelbouton->addWidget(affDessin);
    panelbouton->addWidget(affImage);
    zoneoignon->addLayout(panelbouton);

}
