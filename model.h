#ifndef MODEL_H
#define MODEL_H

#include <QString>
#include <QImage>
#include <QLabel>
#include <QPixmap>



class Model
{
public:
    Model();
    QImage* ouvrirQImage(QString filename);
    QPixmap* ouvrirQpixmap(QImage* image);
    QLabel* ouvrirLabel(QPixmap* Piximage);
};

#endif // MODEL_H
