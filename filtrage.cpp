#include "filtrage.h"

Filtrage::Filtrage()
{
}

Filtrage::~Filtrage()
{
    quit(); //fonctions de la classe QThread
    wait();
}

void Filtrage::run()
{
    for(int x = 0; x < image->width(); x++) // boucle parcourant abscisse
         {
             for(int y = 0; y < image->height(); y++) // et ordonné
             {
                 int gray =  qGray(image->pixel(x,y)); // initialisation du gris
                 image->setPixel(x,y,qRgb(gray,gray,gray)); // traitement de l'image grace a la methode RVB
             }
         }
}

void Filtrage::debutFiltrage(QImage *imagetraite) // cette fonction lace le thread
{
    image=imagetraite;                           // argument QImage* dans un attribut du thread
    this->start();                              // en appelant start() on execute run()
}

QImage* Filtrage::imageTraite()
{
    return image;
}
