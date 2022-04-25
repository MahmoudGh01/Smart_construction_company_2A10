#include "employes.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

employes::employes()
{
   id=0; prenom="";nom="";email="";motdepasse="";
}
employes::employes(int id,QString prenom,QString nom,QString email,QString motdepasse)
{
 this->id=id;
 this->prenom=prenom;
 this->nom=nom;
 this->email=email;
 this->motdepasse=motdepasse;
}
bool employes::Ajouter()
{

  QSqlQuery query;
  QString res=QString ::number(id);
       query.prepare("INSERT INTO EMPLOYES (id, prenom, nom,email,motdepasse) "
                     "VALUES (:id, :prenom, :nom, :email, :motdepasse)");
       query.bindValue(":id",res);
       query.bindValue(":prenom", prenom);
       query.bindValue(":nom", nom);
       query.bindValue(":email", email);
       query.bindValue(":motdepasse", motdepasse);
       return query.exec();
}
bool employes::supprimer(int id)
{

    QSqlQuery query;
    QString res=QString ::number(id);
         query.prepare("Delete from EMPLOYES where ID=:id");
         query.bindValue(":id",res);
         return query.exec();
}
QSqlQueryModel * employes::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT * FROM EMPLOYES");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("motdepasse"));
         return model;
}
bool employes:: modifier(int id)
{
QSqlQuery query;
QString res= QString::number(id);

query.prepare("UPDATE EMPLOYES set ID=:id, PRENOM=:prenom, NOM=:nom, EMAIL=:email,MOTDEPASSE=:motdepasse  where ID=:id");
query.bindValue(":id", res);
query.bindValue(":prenom", prenom);
query.bindValue(":nom", nom);
query.bindValue(":email", email);
query.bindValue(":motdepasse", motdepasse);


return  query.exec();
}

    QSqlQueryModel * employes :: rechercher(QString ch)
    {
        QSqlQueryModel * model= new QSqlQueryModel();
        QString str="select * from EMPLOYES where id like '"+ch+"%' or prenom like '"+ch+"%' or nom like '"+ch+"%'    ";
        model->setQuery(str);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("email "));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("motdepasse"));
        return model;
    }


