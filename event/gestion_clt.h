#ifndef GESTION_CLT_H
#define GESTION_CLT_H


#include <QString>
#include <QtSql/QSqlQueryModel>

class gestion_clt
{
public:
    gestion_clt();
    gestion_clt(QString,QString,QString,QString,QString);


    QString get_id_client();
    QString get_nom_client();
    QString get_adresse_client();
    QString get_email_client();
    QString get_type_client();

    bool ajouter_client();
    QSqlQueryModel * afficher_client();
    bool supprimer_client(QString id_Sclient);
    bool modifier_client(QString, QString, QString ,QString,QString);
    bool chercher_client();
    QSqlQueryModel * afficher_Re_client(QString);
    QSqlQueryModel * afficher_tri_CLT();
    QSqlQueryModel * afficher_tri_CLT_DESC();
     bool existe(QString);


private:
    QString  id_client , nom_client , adresse_client, email_client,type_client;

};

#endif // GESTION_CLT_H
