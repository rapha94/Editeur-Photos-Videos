#ifndef FILTRAGE_H
#define FILTRAGE_H

#include <QThread>
#include <QPixmap>

class Filtrage : public QThread // création d'une classe héritant de QThread
{
public:
    Filtrage();
    ~Filtrage(); // destructeur essentiel pour les threads

    QImage *image = new QImage();
    QImage* imageTraite();

public slots:
    void debutFiltrage(QImage *image);
    void run(); // fonction lance le Thread

public:

};

#endif // FILTRAGE_H
