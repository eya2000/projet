#ifndef GESTION_EVENT_H
#define GESTION_EVENT_H


#include <QString>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>

class gestion_event
{
public:
    gestion_event();
    gestion_event(QString,QString,QString,QString,QString);

    QString get_nom_event();
    QString get_id_event();
    QString get_date_event();
    QString get_type_event();
    QString get_nb_part_event();

    bool ajouter_event();
    QSqlQueryModel * afficher_event();
    bool supprimer_event(QString id_Sevent);
    bool modifier_event(QString, QString, QString ,QString ,QString);
    bool chercher_event();
    QSqlQueryModel * afficher_Re_event(QString);
    QSqlQueryModel * afficher_tri_ID();
    QSqlQueryModel * afficher_tri_ID_DESC();
    bool existe(QString);
private:
    QString  nom_event , id_event , date_event , type_event , email_adherent ,nb_part_event;

};

#endif // GESTION_EVENT_H
