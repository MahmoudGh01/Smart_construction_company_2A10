#ifndef HISTOMOD_H
#define HISTOMOD_H
#include <QString>
#include<QDate>
#include<QSqlQuery>
#include <QSqlQueryModel>
class histomod
{
public:
    //constructeurs
    histomod();
    histomod(int,int,QString);

    //Getters
    int getidhm(){return idhm;}
    int getprixhm(){return prixhm;}
    QString getnom_produithm(){return nom_produithm;}

    //Setters
    void setidhm(int idhm){this->idhm=idhm;}
    void setprixhm(int prixhm){this->prixhm=prixhm;}
    void setnom_produithm(QString nom_produithm){this->nom_produithm = nom_produithm;}

    //méthodes
    bool ajouter();
    QSqlQueryModel * afficher();


    bool modifier();


    //métiers

private:
    int idhm,prixhm;
    QString nom_produithm;

};
#endif // HISTOMOD_H
