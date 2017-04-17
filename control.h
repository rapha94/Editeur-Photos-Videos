#ifndef CONTROL_H
#define CONTROL_H

#include "model.h"
#include "mainwindow.h"
#include <QObject>
#include <QPixmap>
#include <QString>
#include <QThread>

#include <filtrage.h>

class MainWindow;
class Model;

class Control : public QObject
{
    Q_OBJECT

public:
    Control(Model *model, MainWindow &mainwindow );

    void ouverture();
    void save();
    void pelemele();
    void filtrage();
    //void controlTaille(QWidget *label);

    QPixmap* qPix (QPixmap qimage);
    QImage* qImge (QImage qimage);


 private:
    Model *model;
    MainWindow &mainwindow;
};

#endif // CONTROL_H
