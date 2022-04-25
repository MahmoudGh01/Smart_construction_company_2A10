#include "batiment.h"
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

Batiments::Batiments()
{
id="";
responsable="";
type="";
adresse="";
budget="";

}
Batiments::Batiments (QString id ,QString responsable ,QString type ,QString adresse,QString budget)
{this->id=id; this->responsable=responsable;this->type=type;this->adresse=adresse;this->budget=budget;}
QString Batiments::get_id(){return id ;}
QString Batiments::get_responsable(){return responsable;}
QString Batiments::get_type()  { return type;}
QString Batiments::get_adresse(){return adresse;}
QString Batiments::get_budget(){return budget;}

void Batiments::setid(QString id){this->id=id;}
void Batiments:: setresponsable(QString responsable){this->responsable=responsable;}
void Batiments::settype(QString type){this->type=type;}
void Batiments::setadresse(QString adresse){this->adresse=adresse;}
void Batiments::setbudget(QString budget){this->budget=budget;}

bool Batiments::ajouter()
{
    QSqlQuery query;
          query.prepare("INSERT INTO BATIMENT (id,responsable,type , adresse , budget) "
                        "VALUES (:id, :responsable, :type, :adresse , :budget)");
          query.bindValue(":id", id);
          query.bindValue(":responsable", responsable);
          query.bindValue(":type", type);
          query.bindValue(":adresse", adresse);
          query.bindValue(":budget", budget);
          return query.exec();

}
QSqlQueryModel* Batiments::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel;

          model->setQuery("SELECT* FROM BATIMENT");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Responsable"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Budget"));
          return model;
}

bool Batiments::supprimer(QString id)
{
    QSqlQuery query;
          query.prepare("DELETE FROM BATIMENT WHERE id=:id");
          query.bindValue(":id", id);
          query.bindValue(":responsable", responsable);
          query.bindValue(":type", type);
          query.bindValue(":adresse", adresse);
          query.bindValue(":budget", budget);
          return query.exec();
}
bool Batiments::modifier()
{   QSqlQuery query;
    query.prepare( "UPDATE BATIMENT SET ID=:id,RESPONSABLE=:responsable,TYPE=:type,ADRESSE=:adresse,budget=:budget WHERE ID=:id");
    query.bindValue(":id", id);
    query.bindValue(":responsable", responsable);
    query.bindValue(":type", type);
    query.bindValue(":adresse", adresse);
    query.bindValue(":budget", budget);
    return query.exec();
}
void Batiments::creerpdf()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM Batiment ");
    q.exec();
    QString pdf="<br> <h1 style='text-align: center;'><span style='color: #ffcc00;'><em><strong>TABLEAU DE BATIMENTS</strong></em></span></p></h1>\n <table style=\"text-align: center; font-size: 20px;\" border=1>  <tr>  <th>ID </th>       <th>Responsable </th>  <th>Type </th> <th>adresse </th>  <th>Budget </th>   " ;


    while ( q.next()) {
pdf= pdf+ " <br> <tr> <td><p>"+ q.value(0).toString()+"</p></td>   <td><p> " + q.value(1).toString() +"</p></td>   <td><p>" +q.value(2).toString() +" </p></td>   <td><p>"+q.value(3).toString()+"</p></td> <td><p>"+q.value(4).toString()+"</p></td>";

    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}
