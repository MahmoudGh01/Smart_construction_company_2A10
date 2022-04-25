#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QString>

#include<QSqlQuery>
#include <QSqlQueryModel>

class historique
{
        public:
            //constructeurs
            historique();
            historique(int,int,QString);

            //Getters
            int getidh(){return idh;}
            int getprixhm(){return prixh;}
            QString getnom_produithm(){return nom_produith;}

            //Setters
            void setidhm(int idh){this->idh=idh;}
            void setprixhm(int prixh){this->prixh=prixh;}
            void setnom_produithm(QString nom_produith){this->nom_produith = nom_produith;}

            //méthodes
            bool ajouter();
            QSqlQueryModel * afficher();


            bool modifier();


            //métiers

        private:
            int idh,prixh;
            QString nom_produith;

        };

#endif // HISTORIQUE_H
