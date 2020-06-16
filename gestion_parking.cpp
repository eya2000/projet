#include "gestion_parking.h"
#include <QDebug>
#include <QVariant>
#include <QtSql/QSqlQuery>


gestion_parking::gestion_parking()
{
    cin="";
    immatricule="";
    num_tel="";
}
    gestion_parking::gestion_parking( QString cin, QString immatricule, QString num_tel)
{
    this->cin=cin;
    this->immatricule=immatricule;
    this->num_tel=num_tel;


}

QString gestion_parking::get_cin(){return cin;}
QString gestion_parking::get_immatricule(){return immatricule;}
QString gestion_parking::get_num_tel(){return num_tel;}



bool gestion_parking::ajouter_parking()
{
    QSqlQuery query;
    query.prepare("INSERT INTO parking (cin, immatricule, num_tel)"
                  "VALUES (:cin, :immatricule, :num_tel)");


    query.bindValue(":cin",cin);
    query.bindValue(":immatricule",immatricule);
    query.bindValue(":num_tel",num_tel);


    return query.exec();
}


bool gestion_parking::supprimer_parking(QString cin)
{
    QSqlQuery query;
    query.prepare("DELETE FROM parking WHERE cin= :cin ");
    query.bindValue(":cin", cin);

    return  query.exec();
}

bool gestion_parking::modifier_parking(QString cin, QString immatricule, QString num_tel )
{
    QSqlQuery query;


        query.prepare("UPDATE parking SET cin=:cin , immatricule=:immatricule, num_tel=:num_tel  WHERE cin=:cin");

        query.bindValue(":cin", cin);
        query.bindValue(":immatricule", immatricule);
        query.bindValue(":num_tel", num_tel);




        return    query.exec();
}


QSqlQueryModel * gestion_parking::afficher_Re_parking(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("SELECT * FROM parking WHERE cin= '"+val+"'") ;

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Immatricule"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Num_tel"));

    return model;
}




QSqlQueryModel * gestion_parking:: afficher_tri_PRK()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from parking order by cin ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Immatricule"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Num_telf"));
//model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));

    return model;
}

QSqlQueryModel * gestion_parking:: afficher_tri_PRK_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from parking order by cin desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Immatricule"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Num_tel"));
//model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));

    return model;
}

bool gestion_parking::existe(QString cin)
{
    QSqlQuery query;

    query.prepare("select * from parking where cin like '"+cin+"%'");
   if(query.exec())
       return true;
   else
       return false;
}
QSqlQueryModel *gestion_parking::afficher_list()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT ID FROM PARKING");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("cin"));
    return model;
}

void gestion_parking::setid(QString c)
{

    cin=c;
}
