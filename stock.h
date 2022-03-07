#ifndef STOCK_H
#define STOCK_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class Stock
{
     QString nom_produit ;
    int id, prix;
public:
    //constructeurs
    Stock(){}
    Stock(int,int,QString);

    //Getters
    int getid(){return id;}
    int getprix(){return prix;}
    QString getnom_produit(){return nom_produit;}

    //Setters
    void setid(int i){this->id=i;}
    void setprix(int p){this->prix=p;}
    void setnom_produit(QString np){nom_produit=np;}

    //Fnc de base relatives a l'entité stock
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int id1,QString nom1, int prix1 ) ;







};


#endif // STOCK_H
