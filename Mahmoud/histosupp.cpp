#include "histosupp.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QObject>

histosupp::histosupp(){
    idhs=0;

}

histosupp::histosupp(int idhs)
{
    this->idhs=idhs;


}

int histosupp::getidhs(){return idhs;}

void histosupp::setidhs(int idhs){this->idhs=idhs;}


bool histosupp :: ajoutSupp()
{

    QSqlQuery query;

    //Prendra la requête en paramètre pour la préparer à l’exécution.
    query.prepare("insert into histosuppa (idhs)" "values (:idhs)");

    //bindValue+requete
    query.bindValue(":idhs", idhs);




    return  query.exec();
}
QSqlQueryModel * histosupp :: affichSupp()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM histosuppa");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));


    return model;
}






