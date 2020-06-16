#include "depart.h"
#include "ui_depart.h"

#include <QMessageBox>
#include <QTableWidget>
#include "gestion_depart.h"
#include "gestion_parking.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QDebug>
#include <QVariant>


#include <QDate>
#include <QPrinter>
#include<QTextDocument>
#include <QPrintDialog>
#include <QGraphicsScene>
#include <QSqlRecord>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>


depart::depart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::depart)
{
    ui->setupUi(this);
    ui->table_depart->setModel(tmpdepart.afficher_depart());
    //ui->table_client_2->setModel(tmpclient.afficher_client());
    /*QPixmap pix("C:/Users/HP/Desktop/event/hotel2.png");
    ui->label_pic_2->setPixmap(pix);
    ui->label_pic_3->setPixmap(pix);
    ui->label_pic_4->setPixmap(pix);
    ui->label_pic->setPixmap(pix);
    ui->label_pic_5->setPixmap(pix);*/
}

depart::~depart()
{
    delete ui;
}

void depart::on_Ajouter_depart_2_clicked()
{



QString id = ui->ajouter_id_2->text();
QString poste = ui->ajouter_poste_2->text();




if (id=="")
    {
     QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Champ vide"),QMessageBox::Ok);
    }
     else {

     gestion_depart e(id,poste);
     if(!e.existe(e.get_id()))
         QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Depart existe"),QMessageBox::Ok);
     else {
         bool test=e.ajouter_depart();
         if(test)
             {
                 ui->table_depart->setModel(tmpdepart.afficher_depart());
                 QMessageBox::information(nullptr, QObject::tr("Ajouter une depart"),QObject::tr("Depart ajoutee.\n""Click cancel to exit."),QMessageBox::Cancel);
             }
    }
}
            ui->ajouter_id_2->clear();
            ui->ajouter_poste_2->clear();

}


QSqlQueryModel * gestion_parking::afficher_parking()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM parking");


model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Immatricule"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Num_tel"));


return model;
}


QSqlQueryModel * gestion_depart::afficher_depart()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM depart");


model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Poste"));



return model;
}

void depart::on_supprimer_depart_3_clicked()
{
    QString id = ui->supprimer_depart->text();
    bool test = tmpdepart.supprimer_depart(id);

    if(test)
    {
        ui->table_depart->setModel(tmpdepart.afficher_depart());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un depart"),
                        QObject::tr("depart supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un depart"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }



void depart::on_Ajouter_parking_2_clicked()
{
    QString cin = ui->Ajouter_cin_2->text();
    QString immatricule = ui->ajouter_immatricule_2->text();
    QString num_tel = ui->ajouter_num_tel_2->text();



    if (cin=="")
        {
         QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Champ vide"),QMessageBox::Ok);
        }
         else {

         gestion_parking pa(cin,immatricule,num_tel);
         if(!pa.existe(pa.get_cin()))
             QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Place existe"),QMessageBox::Ok);
         else {
             bool test=pa.ajouter_parking();
             if(test)
                 {
                     ui->table_parking->setModel(tmpparking.afficher_parking());
                     QMessageBox::information(nullptr, QObject::tr("Ajouter une voiture"),QObject::tr("voiture ajoutee.\n""Click cancel to exit."),QMessageBox::Cancel);
                 }
        }
    }
                ui->Ajouter_cin_2->clear();
                ui->ajouter_immatricule_2->clear();
                ui->ajouter_num_tel_2->clear();

}




/*void depart::on_supprimer_parking_2_clicked()
{
    QString cin = ui->supprimer_parking->text();
    bool test = tmpparking.supprimer_parking(cin);

    if(test)
    {
        ui->table_parking->setModel(tmpparking.afficher_parking());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une voiture"),
                        QObject::tr("Voiture supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer une voiture"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}*/


void depart::on_chercher_modif_depart_clicked()
{

    QString id = ui->chercher_depart->text();

        ui->table_Re_depart->setModel(tmpdepart.afficher_Re_depart(id));//refresh

}


void depart::on_modifier_depart_clicked()
{


        // QString poste_depart = ui->modifier_nom_event->text();
        QString id = ui->modifier_id->text();
        QString poste = ui->modifier_poste->text();


    bool test=tmpdepart.modifier_depart(poste,id);


    if (test)
      {
        ui->table_depart->setModel(tmpdepart.afficher_depart());//refresh
      ui->table_Re_depart->setModel(tmpdepart.afficher_Re_depart(id));//refresh

    QMessageBox::information(nullptr, QObject::tr("modifier un depart"),
                    QObject::tr("depart modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un depart"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

 void depart::on_modifier_parking_clicked()
{

    QString cin = ui->modifier_cin->text();
    QString immatricule = ui->modifier_immatricule->text();
    QString num_tel = ui->modifier_num_tel->text();



bool test=tmpparking.modifier_parking(cin,immatricule,num_tel);


if (test)
  {

    ui->table_parking->setModel(tmpparking.afficher_parking());//refresh
    ui->table_Re_parking->setModel(tmpparking.afficher_Re_parking(cin));


QMessageBox::information(nullptr, QObject::tr("modifier une voiture"),
                QObject::tr("Voiture modifier.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("modifier une voiture"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}



 void depart::on_chercher_parking_clicked()
 {

     QString cin = ui->recherche_parking_cin->text();

     ui->table_Re_parking->setModel(tmpparking.afficher_Re_parking(cin));//refresh

 }




void depart::on_tri_asc_clicked()
{
    ui->table_depart->setModel(tmpdepart.afficher_tri_ID());

}

void depart::on_tri_desc_clicked()
{
    ui->table_depart->setModel(tmpdepart.afficher_tri_ID_DESC());
}

void depart::on_tri_asc_dpt_clicked()
{
    ui->table_parking->setModel(tmpparking.afficher_tri_PRK());
}

void depart::on_tri_desc_dpt_clicked()
{
    ui->table_parking->setModel(tmpparking.afficher_tri_PRK_DESC());
}

void depart::on_pushButtonPDF_1_clicked()
{
     QString strStream;
     QTextStream out(&strStream);

                const int rowCount = ui->table_depart->model()->rowCount();
                const int columnCount = ui->table_depart->model()->columnCount();
                QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                out <<"<html>\n"
                      "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    << "<title>Depart<title>\n "
                    << "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<h1 style=\"text-align: center;\"><strong> ******LISTE DES Departements ****** "+TT+"</strong></h1>"
                    "<table style=\"text-align: center; margin:auto; font-size: 20px;\" border=1>\n "
                      "</br> </br>";
                // headers
                out << "<thead><tr bgcolor=#d6e5ff>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->table_depart->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->table_depart->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++)
                {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->table_depart->isColumnHidden(column)) {
                            QString data =ui->table_depart->model()->data(ui->table_depart->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                if (dialog->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }


                delete document;
}





void depart::on_pushButtonPDF_2_clicked()
{
     QString strStream;
     QTextStream out(&strStream);

                const int rowCount = ui->table_parking->model()->rowCount();
                const int columnCount = ui->table_parking->model()->columnCount();
                QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                out <<"<html>\n"
                      "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    << "<title>Events<title>\n "
                    << "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<h1 style=\"text-align: center;\"><strong> ******LISTE DES Evenements ****** "+TT+"</strong></h1>"
                    "<table style=\"text-align: center; margin:auto; font-size: 20px;\" border=1>\n "
                      "</br> </br>";
                // headers
                out << "<thead><tr bgcolor=#d6e5ff>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->table_parking->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->table_parking->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++)
                {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->table_parking->isColumnHidden(column)) {
                            QString data =ui->table_parking->model()->data(ui->table_parking->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                if (dialog->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }


                delete document;
}






void depart::on_comboBox_6_activated(const QString &arg1)
{
    ui->sup_2->setText(arg1);
}

void depart::on_supprimer_2_clicked()
{

    QString id=ui->sup_2->text();
    gestion_depart de;
    de.setid(id);

    bool test=de.supprimer_depart(id);
    if(test)
    {

        ui->comboBox_6->setModel(tmpdepart.afficher_list());

    }

    }


void depart::on_comboBox_8_activated(const QString &arg2)
{
    ui->sup_9->setText(arg2);
}

void depart::on_supprimer_9_clicked()
{

    QString cin=ui->sup_9->text();
    gestion_parking pa;
    pa.setid(cin);

    bool test=pa.supprimer_parking(cin);
    if(test)
    {

        ui->comboBox_8->setModel(tmpdepart.afficher_list());

    }

    }




