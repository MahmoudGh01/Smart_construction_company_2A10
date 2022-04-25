#include "stockp.h"
#include "historique.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QObject>
historique::historique()
{
   nom_produith ="";
    idh=0;
   prixh =0;

}

historique::historique(int idh , int prixh ,QString nom_produith)
{
    this->idh=idh;
     this->prixh=prixh;
     this->nom_produith=nom_produith;
}



bool historique::ajouter()
{

QSqlQuery query;

QString idh_string = QString::number(idh);
QString prixh_string = QString::number(prixh);


//Prendra la requête en paramètre pour la préparer à l’exécution.
query.prepare("insert into historiquea (idh,prixh,nom_produith)" "values (:idh,:prixh,:nom_produith)");

//bindValue+requete
query.bindValue(":idh", idh_string);
query.bindValue(":prixh", prixh_string );
query.bindValue(":nom_produith", nom_produith );



return  query.exec();



}

QSqlQueryModel* historique::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();



model->setQuery("SELECT * FROM historiquea");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom_produit"));
return model;
}
