#ifndef CONNEXION_H
#define CONNEXION_H
#include <QtSql/QSqlDatabase>

class Connection
{
private:
    QSqlDatabase db;
public:
    Connection();
    bool ouvrirConnection();
    void fermerConnection();

};

#endif // CONNEXION_H
