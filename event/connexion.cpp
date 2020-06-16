#include "connexion.h"

Connection::Connection()
{}

bool Connection::ouvrirConnection()
{
bool test=false;
    db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_projet_2A");
db.setUserName("Iheb");//inserer nom de l'utilisateur
db.setPassword("esprit19");//inserer mot de passe de cet utilisateur


if (db.open()) test = true;


return test;

}
void Connection::fermerConnection()
{db.close();}
