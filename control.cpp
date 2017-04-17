#include "control.h"

#include <QDebug>
#include <QMdiSubWindow>

Control::Control(Model *model, MainWindow &mainwindow): mainwindow (mainwindow)
{
    // liaison entre notre Mainwindow(view) et notre control

    this->model = model;
    mainwindow.setControl(this);
}

void Control::ouverture()         // control récupére les fonctions
{
    QLabel *label = new QLabel();
    QString filename;
    filename = mainwindow.ouvrirDialogue();

    if (filename !="")
    {
    label = model->ouvrirLabel(model->ouvrirQpixmap(model->ouvrirQImage(filename)));
    this->mainwindow.printWidget(label);
    }
}


void Control::save()
{

}

void Control::filtrage()  // le controle regroupe les fonctions necessaires
{
    Filtrage *filtrage = new Filtrage();
    QMdiSubWindow *area =mainwindow.mid->currentSubWindow();   //on recupere la sous fenetre active (derniere selectionee)
    QPixmap pixm = area->widget()->grab();  // Grab() va récuperer le sous format Pixmap

    QImage image = pixm.toImage();           //avec toImage() on on cree un QImage a partir d'un QPixmap
    QImage *imagetraite = qImge(image);         //on cree un pointeur QImage* qui pointe vers ce QImage
    filtrage->debutFiltrage(imagetraite);        // on appelle threadCommence() avec notre pointeur
                                        //de typeQImage* en argument
    filtrage->wait();                       //on attend la fin du thread
    delete(area);


    QLabel *label = new QLabel();       //Comme la fonction ouvrirImage(), c'est l'imbriquement de plusieurs
    label = model->ouvrirLabel(model->ouvrirQpixmap(filtrage->imageTraite()));//fonctions afin d'obtenir
    mainwindow.printWidget(label);   //le label et de le "print"
                            //"gris->threadTermine()" renvoie le nouveau QImage noir et blanc
    filtrage->wait();


}

QImage* Control::qImge (QImage qimage)   //fonction permettant de creer un pointeur QImage* qui pointe sur
{                                       //un QImage passer en argument
    QImage *tt = new QImage();
    tt=&qimage;
    return tt;
}

QPixmap* Control::qPix (QPixmap qimage)  //fonction permettant de creer un pointeur QPixmap* qui pointe sur
{                                       //un QPixmap passer en argument

    QPixmap *tt = new QPixmap();
    tt=&qimage;
    return tt;
}



/*void Control::controlTaille(QWidget *label) //cette fonction redimenssionne un widget s'il depasse
{                                               //la taille de la fenetre principale


    unsigned long a = label->height();            //on recupere la hauteur de la fenetre
    unsigned long b = label->width();             //de meme pour la largeur
    const long c = 680 ;                        //on initialise des variable constante representant la taille
    const long d = 1180;                        //de ma fenetre principale ( en pixel)

    if (a>=c | b>=d){                   // si hauteurWidget>hauteurFenetre OU largeurWidget>largeurFenetre

            if (a>=c) {                         // si c'est le premier ca

                label->setFixedHeight(c);       //on redimenssionne la hauteurWidget a celle de hauteur Fenetre
                label->setFixedWidth(b*c/a);    //pour garder les proportion, proportionnellement on reduit la largeur
            }

            if (b>=d) {                         // si c'est le deuxieme

                label->setFixedHeight(d);      //meme principe mais hauteur et largeur inverser
                label->setFixedWidth(a*d/b);
            }
}}*/
