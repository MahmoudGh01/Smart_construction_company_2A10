#ifndef BATIMENT_H
#define BATIMENT_H
#include<QString>
#include<QSqlQueryModel>



class Batiments
{
public:
    Batiments();
    Batiments(QString,QString,QString,QString,QString);

    void setid(QString id);
    void setresponsable(QString responsable);
    void settype (QString type);
    void setadresse (QString adresse);

    void setbudget(QString budget);
    bool ajouter();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel* afficher();

    QString get_id();
    QString get_responsable ();
    QString get_type ();
    QString get_adresse();

    QString get_budget();




private:
    QString type,responsable,adresse,id,budget;

};


#endif // BATIMENT_H
