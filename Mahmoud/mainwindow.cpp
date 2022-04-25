#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("Back.jfif");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if( c.createconnect()){

      close();

      gestion_batiment *ga = new gestion_batiment();

      ga->show();

     }

}

void MainWindow::on_pushButton_2_clicked()
{
    if( c.createconnect()){

      close();

      gestion_stock *ga = new gestion_stock();

      ga->show();

     }
}
