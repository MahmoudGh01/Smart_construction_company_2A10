#include "connection.h"
//Test Tutoriel Git
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("db");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("asma1234");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
