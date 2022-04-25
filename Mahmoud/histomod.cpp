#include "histomod.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QObject>
histomod::histomod()
{
    idhm=0;
    prixhm=0;
    nom_produithm="";

}

histomod::histomod(int idhm,int prixhm,QString nom_produithm)
{
    this->idhm=idhm;
    this->nom_produithm=nom_produithm;
    this->prixhm=prixhm;


}





bool histomod::ajouter()
{

QString idhm_string = QString::number(idhm);
QString prixhm_string = QString::number(prixhm);
QSqlQuery query;

//Prendra la requête en paramètre pour la préparer à l’exécution.
query.prepare("insert into histomoda (idhm,prixhm,nom_produithm)" "values (:idhm,:prixhm,:nom_produithm)");

//bindValue+requete
query.bindValue(":idhm", idhm_string);
query.bindValue(":prixhm", prixhm_string );
query.bindValue(":nom_produithm", nom_produithm );



return  query.exec();

}

QSqlQueryModel* histomod::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("SELECT * FROM histomoda");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom_produit"));


return model;
}
