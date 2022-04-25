#include "connexion.h"


connexion::connexion()
{

}
bool connexion::ouvrirconnexion()
{
   db=QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("Source_Projet2A");
db.setUserName("system");
db.setPassword("madave");


if (db.open()) test = true;


return test;

}
void connexion::fermerconnexion()
{
    db.close();
}
