#include "batiment.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Batiments::Batiments()
{
id="";
responsable="";
type="";
adresse="";

}
Batiments::Batiments (QString id ,QString responsable ,QString type ,QString adresse)
{this->id=id; this->responsable=responsable;this->type=type;this->adresse=adresse;}
QString Batiments::get_id(){return id ;}
QString Batiments::get_responsable(){return responsable;}
QString Batiments::get_type(){return type;}
QString Batiments::get_adresse(){return adresse;}
void Batiments::setid(QString id){this->id=id;}
void Batiments:: setresponsable(QString responsable){this->responsable=responsable;}
void Batiments::settype(QString type){this->type=type;}
void Batiments::setadresse(QString adresse){this->adresse=adresse;}
bool Batiments::ajouter()
{
    QSqlQuery query;
          query.prepare("INSERT INTO BATIMENT (id,responsable,type , adresse) "
                        "VALUES (:id, :responsable, :type, :adresse)");
          query.bindValue(":id", id);
          query.bindValue(":responsable", responsable);
          query.bindValue(":type", type);
          query.bindValue(":adresse", adresse);
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
          return query.exec();
}
bool Batiments::modifier()
{   QSqlQuery query;
    query.prepare( "UPDATE BATIMENT SET ID=:id,RESPONSABLE=:responsable,TYPE=:type,ADRESSE=:adresse WHERE ID=:id");
    query.bindValue(":id", id);
    query.bindValue(":responsable", responsable);
    query.bindValue(":type", type);
    query.bindValue(":adresse", adresse);

    return query.exec();
}
