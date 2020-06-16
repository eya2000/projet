#include "gestion_clt.h"
#include <QDebug>
#include <QVariant>
#include <QtSql/QSqlQuery>


gestion_clt::gestion_clt()
{
    id_client="";
    nom_client="";
    adresse_client="";
    email_client="";
    type_client="";

}

gestion_clt::gestion_clt( QString id_client, QString nom_client, QString adresse_client, QString email_client,QString type_client)
{
    this->id_client=id_client;
    this->nom_client=nom_client;
    this->adresse_client=adresse_client;
    this->email_client=email_client;
    this->type_client=type_client;

}

QString gestion_clt::get_id_client(){return id_client;}
QString gestion_clt::get_nom_client(){return nom_client;}
QString gestion_clt::get_adresse_client(){return adresse_client;}
QString gestion_clt::get_email_client(){return email_client;}
QString gestion_clt::get_type_client(){return type_client;}


bool gestion_clt::ajouter_client()
{
    QSqlQuery query;
    query.prepare("INSERT INTO client (id_client, nom_client, adresse_client, email_client, type_client)"
                  "VALUES (:id_client, :nom_client, :adresse_client, :email_client, :type_client)");


    query.bindValue(":id_client",id_client);
    query.bindValue(":nom_client",nom_client);
    query.bindValue(":adresse_client",adresse_client);
    query.bindValue(":email_client",email_client);
    query.bindValue(":type_client",type_client);

    return query.exec();
}


bool gestion_clt::supprimer_client(QString id_Sclient)
{
    QSqlQuery query;
    query.prepare("DELETE FROM client WHERE id_client= :id_client ");
    query.bindValue(":id_client", id_Sclient);

    return  query.exec();
}

bool gestion_clt::modifier_client(QString id_client, QString nom_client, QString adresse_client , QString email_client, QString type_client )
{
    QSqlQuery query;


        query.prepare("UPDATE client SET nom_client=:nom_client , adresse_client=:adresse_client, email_client=:email_client, type_client=:type_client  WHERE id_client=:id_client");

        query.bindValue(":id_client", id_client);
        query.bindValue(":nom_client", nom_client);
        query.bindValue(":adresse_client", adresse_client);
        query.bindValue(":email_client", email_client);
        query.bindValue(":type_client", type_client);



        return    query.exec();
}


QSqlQueryModel * gestion_clt::afficher_Re_client(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("SELECT * FROM client WHERE id_client= '"+val+"'") ;

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type"));
    return model;
}


/*bool gestion_clt::chercher_client()
{
    QSqlQuery query;
    query.prepare("SELECT FROM client WHERE id_client = :id_client ");
    query.bindValue(":id_client", id_Rclient);

    return  query.exec();
}*/

QSqlQueryModel * gestion_clt:: afficher_tri_CLT()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client order by id_client asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type"));
    return model;
}

QSqlQueryModel * gestion_clt:: afficher_tri_CLT_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client order by id_client desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type"));
    return model;
}
bool gestion_clt::existe(QString id)
{
    QSqlQuery query;

    query.prepare("select * from client where id_client like '"+id+"%'");
   if(query.exec())
       return true;
   else
       return false;
}
