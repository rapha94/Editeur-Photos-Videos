#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model m;
    MainWindow w;
    Control (&m,w);
    w.show();


    return a.exec();
}
