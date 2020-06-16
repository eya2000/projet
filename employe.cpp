#include "employe.h"
#include <QDebug>

employe::employe()
{
 login="";
 password="";
}

employe::employe(QString login , QString password)
{
  this->login=login;
  this->password=password;
}
int employe::verifierStatut(QString login,QString password)
{
    QSqlQuery query;
    QString role;
    query.exec("SELECT poste FROM employe WHERE nom_employe='"+login+"'AND mdp_employe='"+password+"'");
               // query.first();

    while (query.next())
    {
        role=query.value("POSTE").toString();
    if (role=="Admin")
        return 0;
    if (role=="Agent des departements")
        return 1;
   /* else if (role=="")
        return 2;
    else if (role=="")
        return 3;
    else if (role=="")
        return 4;*/
    else
        return 5;
    }
}

int employe::verifierCompte(QString login,QString password)
{
    QSqlQuery query;
    QString login1,password1;
    if (login=="" || password=="")
        return  0;
    query.exec("SELECT nom_employe,mdp_employe from employe");
        query.last();
        login1=query.value("nom_employe").toString();
        password1=query.value("mdp_employe").toString();
        if (login1==login && password1==password)
        {
            return 1;
        }
            query.exec("SELECT nom_employe,mdp_employe from employe");
            while (query.next())
            {
                login1=query.value("nom_employe").toString();;
                password1=query.value("mdp_employe").toString();;
                query.at();
                if (login1==login && password1==password)
                {
                    return 2;
                }
            }
    return 4;
}
