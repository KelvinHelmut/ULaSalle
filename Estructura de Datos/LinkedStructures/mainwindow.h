#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iostream>

#include "treeinterval.h"
#include "treeredblack.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();

    void on_btnFill_clicked();

private:
    Ui::MainWindow *ui;

    Tree<Interval<int>*> *tree;
    Tree<int> *tree2;
};

#endif // MAINWINDOW_H
