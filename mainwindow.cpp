#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stock.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]{20}")));
        ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]{10}")));
        ui->lineEdit_3->setValidator(new QRegExpValidator(QRegExp("[0-9]{10}")));


    ui->tableView->setModel(Stmp.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
    //recuperation des information saisies dans les 3 champs
      int id=ui->lineEdit_2->text().toInt();
      int prix=ui->lineEdit_3->text().toInt();
      QString nom_produit=ui->lineEdit->text();
      Stock S(id,prix,nom_produit);
      bool test=S.ajouter();
      if(test)
      {
          QMessageBox::information(nullptr, QObject::tr("OK"),
                      QObject::tr("Ajout effectué\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
          ui->tableView->setModel(Stmp.afficher());
      }
      else
          QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                      QObject::tr("Ajout non effectuè.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);



}

void MainWindow::on_pushButton_3_clicked()
{
    int id =ui->lineEdit_4->text().toInt();
    bool test=Stmp.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("suppression effectué\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(Stmp.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("suppression non effectuè.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modif_button_clicked()
{
    int id1 =ui->id_modif->text().toInt();
     QString nom1=ui->nom_modif->text();
      int prix1 =ui->prix_modif->text().toInt();
    bool test=Stmp.modifier(id1 , nom1 , prix1);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("modification effectué\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(Stmp.afficher());
    }
    else
      {  QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("modification non effectuè.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel); }
}


