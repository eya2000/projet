#include "gestion_depart.h"

#include <QDebug>
#include <QVariant>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

gestion_depart::gestion_depart()
{

  id="";
    poste="";
}

gestion_depart::gestion_depart(QString id, QString poste)
{

    this->id=id;
    this->poste=poste;
}


QString gestion_depart::get_id(){return id;}
QString gestion_depart::get_poste(){return poste;}

bool gestion_depart::ajouter_depart()
{
    QSqlQuery query;
    query.prepare("INSERT INTO depart (id ,poste)"
                  "VALUES (:id, :poste)");


    query.bindValue(":id",id);
    query.bindValue(":poste",poste);



    return query.exec();
}

bool gestion_depart::supprimer_depart(QString id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM depart WHERE id = :id ");
    query.bindValue(":id", id);

    return  query.exec();
}

bool gestion_depart::modifier_depart(QString poste, QString id)
{
    QSqlQuery query;


        query.prepare("UPDATE depart SET poste=:poste    WHERE id=:id");

        query.bindValue(":id", id);
        query.bindValue(":poste", poste);



        return    query.exec();
}

QSqlQueryModel * gestion_depart::afficher_Re_depart(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from depart where id= '"+val+"'") ;


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Poste"));


    return model;
}









QSqlQueryModel * gestion_depart:: afficher_tri_ID()
 {QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from depart order by id asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Poste"));

    return model;
}

QSqlQueryModel * gestion_depart:: afficher_tri_ID_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from depart order by id desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Poste"));

    return model;
}


bool gestion_depart::existe(QString id)
{
    QSqlQuery query;

    query.prepare("select * from depart where id like '"+id+"%'");
   if(query.exec())
       return true;
   else
       return false;
}





QSqlQueryModel *gestion_depart::afficher_list()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT ID FROM DEPART");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    return model;
}

void gestion_depart::setid(QString c)
{

    id=c;
}





















