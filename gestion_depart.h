#ifndef GESTION_DEPART_H
#define GESTION_DEPART_H








#include <QString>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>

#include <QTableView>

class gestion_depart
{
public:
    gestion_depart();
    gestion_depart(QString,QString);


    QString get_id();
     QString get_poste();

    bool ajouter_depart();
    QSqlQueryModel * afficher_depart();
    bool supprimer_depart(QString id);
    bool modifier_depart(QString, QString);

    QSqlQueryModel * afficher_Re_depart(QString);
    QSqlQueryModel * afficher_tri_ID();
    QSqlQueryModel * afficher_tri_ID_DESC();
    bool existe(QString);

    QSqlQueryModel *afficher_list();

void setid(QString);


private:
    QString  poste , id;

};

#endif
