#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class employes
{
public:
    employes();
    employes(int,QString,QString,QString,QString);
    int getid(){return id;}
    QString getprenom(){return nom;}
    QString getnom(){return prenom;}
    QString getemail(){return email;}
    QString getmotdepasse(){return motdepasse;}
    void setid(int);
    void setprenom(QString);
    void setnom(QString);
    void setemail(QString);
    void setmotdepasse(QString);


    bool  Ajouter ();
    bool supprimer(int);
    QSqlQueryModel * afficher();

    bool modifier(int);
      QSqlQueryModel * rechercher(const QString);

 private:

    int id;
    QString prenom,nom,email,motdepasse;



};

#endif // EMPLOYES_H
