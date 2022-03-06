#ifndef BATIMENT_H
#define BATIMENT_H
#include<QString>
#include<QSqlQueryModel>



class Batiments
{
public:
    Batiments();
    Batiments(QString,QString,QString,QString);
    void setid(QString id);
    void setresponsable(QString responsable);
    void settype (QString type);
    void setadresse (QString adresse);
    bool ajouter();
    bool supprimer(QString);

    QSqlQueryModel* afficher();

    QString get_id();
    QString get_responsable ();
    QString get_type ();
    QString get_adresse();



private:
    QString type,responsable,adresse,id;

};


#endif // BATIMENT_H
