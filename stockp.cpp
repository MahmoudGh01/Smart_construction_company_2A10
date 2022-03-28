#include "stockp.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QString>
#include "QDebug"
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>

#include <QSqlQueryModel>
#include <QDate>
Stockp::Stockp(int id , int prix ,QString nom_produit)
{
   this->id=id;
    this->prix=prix;
    this->nom_produit=nom_produit;
  }

bool Stockp::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);
    //prepare()
    query.prepare("insert into stockp (id,prix,nom_produit)" "values (:id, :prix, :nom_produit)");
    //creation des variable liees
    query.bindValue(":id",res);
    query.bindValue(":prix",prix);
    query.bindValue(":nom_produit",nom_produit);

    return query.exec();

}

QSqlQueryModel * Stockp::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * From stockp");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom_produit"));
    return model;

}

bool Stockp::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("delete from stockp where id= :id");
    query.bindValue(":id",res);
    return query.exec();
}

bool Stockp::modifier(int id,QString nom_produit, int prix )
{
   QSqlQuery query;
   QString id_string= QString::number(id);
    QString prix_string= QString::number(prix);


    query.prepare("update stockp set ID=:id, NOM_PRODUIT=:nom , PRIX=:prix where ID=:id");
    query.bindValue(":id", id_string);
    query.bindValue(":nom",nom_produit);
       query.bindValue(":prix",prix_string);



    return query.exec();
}
void Stockp::creerpdf()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM STOCKP ");
    q.exec();
    QString pdf="<br> <h1 style='text-align: center;'><span style='color: pink;'><em><strong>Tableau des Produits</strong></em></span></p></h1>\n <table style=' width: '100%'; margin-left: auto; border-collapse: collapse; margin-right: auto; border='0'>  <tr>  <th>ID </th>       <th>Nom du produits </th>  <th>prix </th>  " ;


    while ( q.next()) {
pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>   <td> " + q.value(2).toString() +"</td>   <td>" +q.value(1).toString() +" </td>  ";

    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}
