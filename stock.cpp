#include "stock.h"

Stock::Stock(int id , int prix ,QString nom_produit)
{
   this->id=id;
    this->prix=prix;
    this->nom_produit=nom_produit;
  }

bool Stock::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);
    //prepare()
    query.prepare("insert into stock (id,prix,nom_produit)" "values (:id, :prix, :nom_produit)");
    //creation des variable liees
    query.bindValue(":id",res);
    query.bindValue(":prix",prix);
    query.bindValue(":nom_produit",nom_produit);

    return query.exec();

}

QSqlQueryModel * Stock::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * From stock");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom_produit"));
    return model;

}

bool Stock::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("delete from stock where id= :id");
    query.bindValue(":id",res);
    return query.exec();
}

bool Stock::modifier(int id,QString nom_produit, int prix )
{
   QSqlQuery query;
   QString id_string= QString::number(id);
    QString prix_string= QString::number(prix);


    query.prepare("update stock set ID=:id, NOM_PRODUIT=:nom , PRIX=:prix where ID=:id");
    query.bindValue(":id", id_string);
    query.bindValue(":nom",nom_produit);
       query.bindValue(":prix",prix_string);



    return query.exec();
}

