#include "gestion_event.h"
#include <QDebug>
#include <QVariant>
#include <QtSql/QSqlQuery>

gestion_event::gestion_event()
{
  nom_event="";
  id_event="";
  date_event="";
  type_event="";
  nb_part_event="";
}

gestion_event::gestion_event(QString nom_event, QString id_event,  QString date_event, QString type_event, QString nb_part_event)
{
    this->nom_event=nom_event;
    this->id_event=id_event;
    this->date_event=date_event;
    this->type_event=type_event;
    this->nb_part_event=nb_part_event;
}

QString gestion_event::get_nom_event(){return nom_event;}
QString gestion_event::get_id_event(){return id_event;}
QString gestion_event::get_date_event(){return date_event;}
QString gestion_event::get_type_event(){return type_event;}
QString gestion_event::get_nb_part_event(){return nb_part_event;}

bool gestion_event::ajouter_event()
{
    QSqlQuery query;
    query.prepare("INSERT INTO event (nom_event, id_event, date_event, type_event, nb_part_event)"
                  "VALUES (:nom_event, :id_event, :date_event, :type_event, :nb_part_event)");


    query.bindValue(":nom_event",nom_event);
    query.bindValue(":id_event",id_event);
    query.bindValue(":date_event",date_event);
    query.bindValue(":type_event",type_event);
    query.bindValue(":nb_part_event",nb_part_event);

    return query.exec();
}

bool gestion_event::supprimer_event(QString id_Sevent)
{
    QSqlQuery query;
    query.prepare("DELETE FROM event WHERE id_event = :id_event ");
    query.bindValue(":id_event", id_Sevent);

    return  query.exec();
}

bool gestion_event::modifier_event(QString nom_event, QString id_event, QString date_event , QString type_event, QString nb_part_event)
{
    QSqlQuery query;


        query.prepare("UPDATE event SET nom_event=:nom_event , date_event=:date_event, type_event=:type_event, nb_part_event= :nb_part_event  WHERE id_event=:id_event");

        query.bindValue(":id_event", id_event);
        query.bindValue(":nom_event", nom_event);
        query.bindValue(":date_event", date_event);
        query.bindValue(":type_event", type_event);
        query.bindValue(":nb_part_event", nb_part_event);


        return    query.exec();
}

QSqlQueryModel * gestion_event::afficher_Re_event(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("select * from event where id_event= '"+val+"'") ;


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Participants"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));

    return model;
}


QSqlQueryModel * gestion_event:: afficher_tri_ID()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from event order by nb_part_event asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Participants"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    return model;
}

QSqlQueryModel * gestion_event:: afficher_tri_ID_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from event order by nb_part_event desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Participants"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    return model;
}
bool gestion_event::existe(QString id)
{
    QSqlQuery query;

    query.prepare("select * from event where id_event like '"+id+"%'");
   if(query.exec())
       return true;
   else
       return false;
}

