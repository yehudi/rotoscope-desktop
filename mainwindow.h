#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QFileDialog>

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
    void lancement();
    ~MainWindow();

public slots:
  void nouveauProjet();
   void parcourirMenu();
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
};

#endif // MAINWINDOW_H
