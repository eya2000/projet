#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>


class employe
{
public:
    employe();
    employe(QString,QString);
    QString get_login;
    QString get_password;

    int verifierStatut(QString,QString);
    int verifierCompte(QString,QString);


private:
    QString login;
    QString password;
};

#endif // EMPLOYE_H
