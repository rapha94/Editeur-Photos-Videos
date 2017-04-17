#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMainWindow>
#include <QMessageBox>
#include <QString>

#include "ui_mainwindow.h"
#include "control.h"

class Control;

namespace Ui{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setarea(QMdiArea *mid)
    {
        this->setCentralWidget(mid);
    }

    void setControl(Control *control)
    {
         this->control=control;
    }

    QMdiArea *mid = new QMdiArea();

public slots:

    QString ouvrirDialogue();
    void ouverture();
    void filtrage();
    void createActions();
    void setActiveSubWindow(QWidget *window);
    void tailleSubWindowsVertically(QWidget *label);
    void tailleSubWindowsHorizontally(QWidget *label);
    void printWidget(QLabel *label);

private slots:

    void on_actionGray_triggered();
    //void on_actionSave_triggered();
    void on_actionOuvrir_triggered();

private:

    Ui::MainWindow *ui;
    Control *control;
    QAction *tailleVerticalAct;
    QAction *tailleHorizontalAct;
};

#endif // MAINWINDOW_H
