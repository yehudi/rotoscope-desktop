#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QFileDialog>
#include <QLabel>

#include <projet.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void creerMenus();
    void creerActions();
    void creerInterfaceUser();
    void creerToolBox();
    void creerzonedessin();
    void creerzoneoignon();
    ~MainWindow();

public slots:
  void nouveauProjet();
   void parcourirMenu();
   void lancement();
   void creerProjet();

private:
    Ui::MainWindow *ui;

    Projet *projCour;
    /*items */
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuPrevi;
    QMenu *menuOptions;
    QAction *nouveauAct;
    QAction *ouvrirAct;
    QAction *sauvAct;
    QAction *exporterAct;
    QAction *fermerAct;
    QAction *quitterAct;
    QPushButton *nouveauButt;
    QPushButton *ouvrirButt;
    QLineEdit *nomvideo;
    QLineEdit *nom;

    /*interface User */
    QVBoxLayout *panelOutil;
    QHBoxLayout *zonedessin;
    QVBoxLayout *zoneoignon;
};

#endif // MAINWINDOW_H
