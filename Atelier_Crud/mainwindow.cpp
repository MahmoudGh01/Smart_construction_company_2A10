#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "batiment.h"
#include <QMessageBox>
#include <QSqlQueryModel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->tab_batiment->setModel(b.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    QString id= ui->lineEdit_ID->text();
    QString responsable= ui->lineEdit_responsable->text();
    QString type= ui->lineEdit_type->text();
    QString adresse= ui->lineEdit_Adresse->text();
    Batiments b(id,responsable,type,adresse) ;
    bool test=b.ajouter();
    if (test)
    { QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("Ajout effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_batiment->setModel(b.afficher());

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                            QObject::tr("Ajout échoué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
   }

void MainWindow::on_pb_supprimer_clicked()
{
    Batiments B1; B1.setid(ui->lineEdit_ID->text());
    bool test=B1.supprimer(B1.get_id());
    if (test)
    { QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("Suppression effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_batiment->setModel(b.afficher());

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                            QObject::tr("Suppression échoué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_clicked()
{

    QString id= ui->lineEdit_ID->text();
    QString responsable= ui->lineEdit_responsable->text();
    QString type= ui->lineEdit_type->text();
    QString adresse= ui->lineEdit_Adresse->text();
    /*QDate date_contrat = ui->dateEdit_Contrat->date();
    int id = ui->lineEdit_idsuppmodifContrat->text().toInt();*/

    Batiments B(id,responsable,type,adresse);


bool ok = B.modifier();
if(ok)
{

    QMessageBox::information(nullptr, QObject::tr("succes"),
                QObject::tr(" modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_batiment->setModel(b.afficher());


}
else
    QMessageBox::critical(nullptr, QObject::tr("fail"),
                QObject::tr(" non modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
