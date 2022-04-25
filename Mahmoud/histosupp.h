#ifndef HISTOSUPP_H
#define HISTOSUPP_H
#include <QString>
#include<QDate>
#include<QSqlQuery>
#include <QSqlQueryModel>
class histosupp
{
public:
    //constructeurs
    histosupp();
    histosupp(int);



    //getters
    int getidhs();//accées lecture//récupérer la valeur d'un attribut


    //setters
    void setidhs(int);



    //méthodes
    bool ajoutSupp();
    QSqlQueryModel * affichSupp();


    bool modifier();


    //métiers

private:

    int idhs;

};


#endif // HISTOSUPP_H
