#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tree = new TreeInterval<int>();
    tree2 = new TreeRedBlack<int>();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAdd_clicked()
{
    QString texto = ui->txtValue->text();
    tree2->add(texto.toInt());

    /*
    QStringList values = texto.split(",");

    int low = values.at(0).toInt();
    int high = values.at(1).toInt();
    tree->add(new Interval<int>(low, high));
*/
    tree2->dot("tree.dot");
    system("dot -Tpng tree.dot -o tree.png");
    ui->image->setPixmap(QString("tree.png"));

    ui->txtValue->setText("");
}

void MainWindow::on_btnFill_clicked()
{
    QString texto = ui->txtValue->text();
    int t = texto.toInt();

    for (int i = 0; i < t; i++) {
        tree2->add(i);
    }

    tree2->dot("tree.dot");
    system("dot -Tpng tree.dot -o tree.png");
    ui->image->setPixmap(QString("tree.png"));

    ui->txtValue->setText("");
}
