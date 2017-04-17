#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWidget>
#include <QFileDialog>
#include <QPixmap>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
}

MainWindow::~MainWindow() // destructeur
{
    delete ui;
}

QString MainWindow::ouvrirDialogue()  // appelle une boite de dialogue pour choisir le fichier
{
    QString filename =""; // declaration d'un QString correspondant aux noms du fichiers
    filename = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
        if (filename == "") // type possible sont png,gif,jpg,jpeg
        {
            return filename;
        }
        else
        {
            QMessageBox::information(this, "Fichier", "Ouverture\n");
            qDebug() << "Sub1"; // flux
            return filename;
        }
}

void MainWindow::printWidget(QLabel *label)           // fonction recevant un label
{
    QMdiSubWindow *window =this->mid->addSubWindow(label);  // subwindow dans mid grace a addSubWindow et on y place le label
    window->setWindowTitle("Image 1");      // on donne un nom à notre subWindown
    setarea(mid);
    window->showNormal();          //on affiche la sous-fenetre
    this->tailleSubWindowsVertically(label); // organisation auto des subwindows
    this->tailleSubWindowsHorizontally(label);
}

void MainWindow::createActions() // créations des actions pour le redimensionnement auto
{
    tailleVerticalAct = new QAction(tr("Taille Vertical"), this);
    tailleVerticalAct->setStatusTip(tr("Taille the sub windows vertically"));
    connect(tailleVerticalAct, SIGNAL(triggered()), this, SLOT(tailleSubWindowsVertically())); // connexion

    tailleHorizontalAct = new QAction(tr("Taille Horizontally"), this);
    tailleHorizontalAct->setStatusTip(tr("Taille the windows horizontally"));
    connect(tailleHorizontalAct, SIGNAL(triggered()), this, SLOT(tailleSubWindowsHorizontally()));
}

void MainWindow::setActiveSubWindow(QWidget *window) // definit les fenetres ouvertes
{
    if (!window)                                    // implicitement la fonction connait la derniere fenetre ouverte
        return;
    mid->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(window));
}

void MainWindow::tailleSubWindowsVertically(QWidget *label)
{
    if (mid->subWindowList().isEmpty()) // verification si mid vide
        return;

    QPoint position(0, 0); // set position

    foreach (QMdiSubWindow *label, mid->subWindowList()) {
        QRect rect(0, 0, mid->width(), mid->height() / mid->subWindowList().count());
        label->setGeometry(rect);
        label->move(position);
        position.setY(position.y() + label->height());
    }
}

void MainWindow::tailleSubWindowsHorizontally(QWidget *label)
{
    if (mid->subWindowList().isEmpty())
        return;

    QPoint position(0, 0);

    foreach (QMdiSubWindow *label, mid->subWindowList()) {
        QRect rect(0, 0, mid->width() / mid->subWindowList().count(), mid->height());
        label->setGeometry(rect);
        label->move(position);
        position.setX(position.x() + label->width());
    }
}

void MainWindow::ouverture()        // appelle actionOuvrir
{
    this->control->ouverture();   // this appelle dans controle ouvrirImage()
}

void MainWindow::on_actionOuvrir_triggered() // déclenchement action ui
{
    control->ouverture();
}

void MainWindow::filtrage()
{
   this->control->filtrage();
}

void MainWindow::on_actionGray_triggered()
{
    control->filtrage();
}



