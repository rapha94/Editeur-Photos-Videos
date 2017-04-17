#include "model.h"
#include <QDebug>


Model::Model()
{
}

QPixmap* Model::ouvrirQpixmap(QImage *image)      //fonction qui recoit un QImage
{                                       //que l'on veut ouvrir et retourne un objet de type QPixmap
QPixmap *imagePix = new QPixmap();
*imagePix = QPixmap::fromImage(*image);     //fromImage() ->  fait  passer un QImage en QPixmap
return imagePix;
}

QImage* Model::ouvrirQImage(QString filename)       //fonction qui recoit un QString (notre adresse de fichier
{                                       //que l'on veut ouvrir et retourne un objet de type QImage
    QImage *image = new QImage();

    if (image->load(filename)==true){       //load() -> retourne un QImage pour une adresse donnee
    qDebug() << "flux1";                // ecris le caractère t dans le flux renvoie une référence au flux.
    return image;
    }
    else {return 0;}

}

QLabel* Model::ouvrirLabel(QPixmap* imagePix){      //fonction qui recoit un QPixmap et le place sur un
                            //QLabel. elle retourne un objet de type QLabel

QLabel *label = new QLabel();
label->setPixmap(*imagePix);        //setPixmap()-> place le QPixmap sur le QLabel
qDebug() << "flux2";
qDebug() << "flux3";
return label;

}


