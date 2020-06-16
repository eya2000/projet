#include "event.h"
#include "ui_event.h"
#include <QMessageBox>
#include "gestion_event.h"
#include "gestion_clt.h"
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QVariant>
#include <QDate>
#include <QPrinter>
#include<QTextDocument>
#include <QGraphicsScene>
#include <QPrintDialog>
#include <QSqlRecord>
#include <QGraphicsEllipseItem>

event::event(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::event)
{
    ui->setupUi(this);
    ui->table_event->setModel(tmpevent.afficher_event());
    ui->table_client_2->setModel(tmpclient.afficher_client());
    QPixmap pix("C:/Users/HP/Desktop/event/hotel2.png");
    ui->label_pic_2->setPixmap(pix);
    ui->label_pic_3->setPixmap(pix);
    ui->label_pic_4->setPixmap(pix);
    ui->label_pic->setPixmap(pix);
    ui->label_pic_5->setPixmap(pix);
}

event::~event()
{
    delete ui;
}

void event::on_Ajouter_event_2_clicked()
{
    QString nom_event = ui->ajouter_nom_event_2->text();
    QString id_event = ui->ajouter_id_event_2->text();
    QString date_event = ui->ajouter_date_event_2->text();
    QString type_event = ui->ajouter_type_event_2->text();
    QString nb_part_event = ui->Ajouter_nb_part_event_2->text();



    if(id_event=="")
    {
     QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Champ vide"),QMessageBox::Ok);
    }
     else {

     gestion_event ga(nom_event,id_event,date_event,type_event,nb_part_event);
     if(!ga.existe(ga.get_id_event()))
         QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Evenement existe"),QMessageBox::Ok);
     else {
         bool test=ga.ajouter_event();
         if(test)
             {
                 ui->table_event->setModel(tmpevent.afficher_event());
                 QMessageBox::information(nullptr, QObject::tr("Ajouter un evenement"),QObject::tr("Evenement ajoutee.\n""Click cancel to exit."),QMessageBox::Cancel);
             }
    }
}
            ui->ajouter_id_event_2->clear();
            ui->ajouter_nom_event_2->clear();
            ui->ajouter_date_event_2->clear();
            ui->ajouter_type_event_2->clear();
            ui->Ajouter_nb_part_event_2->clear();
}


QSqlQueryModel * gestion_event::afficher_event()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM event");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Participants"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));

    return model;
}


void event::on_supprimer_event_2_clicked()
{
    QString id_event = ui->supprimer_event->text();
    bool test = tmpevent.supprimer_event(id_event);

    if(test)
    {
        ui->table_event->setModel(tmpevent.afficher_event());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un evenement"),
                        QObject::tr("Evenement supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un evenement"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }

bool event::controle(QString test)
{
    for(int i = 0; i < test.length(); i++)
    {
        if (test.at(i)=='@')
        {
            return true;
        }
    }
    return false;
}

void event::on_Ajouter_client_2_clicked()
{
    QString id_client = ui->Ajouter_id_client_2->text();
    QString nom_client = ui->ajouter_nom_client_2->text();
    QString adresse_client = ui->ajouter_adresse_client_2->text();
    QString email_client = ui->ajouter_email_client_2->text();
    QString type_client = ui->ajouter_type_client_2->text();
    if(id_client=="")
    {
     QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Champ vide"),QMessageBox::Ok);
    }
     else {

     gestion_clt gc(id_client,nom_client ,adresse_client,email_client,type_client);
     if(!gc.existe(gc.get_id_client()))
         QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("existe"),QMessageBox::Ok);
     else {
         bool test=gc.ajouter_client();
         if(test)
             {
                 ui->table_client_2->setModel(tmpclient.afficher_client());
                 QMessageBox::information(nullptr, QObject::tr("Ajouter"),QObject::tr(" ajoutee.\n""Click cancel to exit."),QMessageBox::Cancel);
             }
    }
}

    ui->Ajouter_id_client_2->clear();
    ui->ajouter_nom_client_2->clear();
    ui->ajouter_adresse_client_2->clear();
    ui->ajouter_email_client_2->clear();
    ui->ajouter_type_client_2->clear();
}

QSqlQueryModel * gestion_clt::afficher_client()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM client");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type"));

    return model;
}

void event::on_supprimer_client_2_clicked()
{
    QString id_client = ui->supprimer_client->text();
    bool test = tmpclient.supprimer_client(id_client);

    if(test)
    {
        ui->table_client_2->setModel(tmpclient.afficher_client());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                        QObject::tr("Client supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


void event::on_chercher_modif_event_clicked()
{

    QString id_event = ui->chercher_event->text();

        ui->table_Re_event->setModel(tmpevent.afficher_Re_event(id_event));//refresh

}


void event::on_modifier_event_clicked()
{


        QString nom_event = ui->modifier_nom_event->text();
        QString id_event = ui->modifier_id_event->text();
        QString date_event = ui->modifier_date_event->text();
        QString type_event = ui->modifier_type_event->text();
        QString nb_part_event= ui->modifier_nb_part_event->text();

    bool test=tmpevent.modifier_event(nom_event,id_event,date_event,type_event,nb_part_event);


    if (test)
      {
        ui->table_event->setModel(tmpevent.afficher_event());//refresh
        ui->table_Re_event->setModel(tmpevent.afficher_Re_event(id_event));//refresh

    QMessageBox::information(nullptr, QObject::tr("modifier un evenement"),
                    QObject::tr("Evenement modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un evenement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void event::on_modifier_client_clicked()
{

    QString id_client = ui->modifier_id_client->text();
    QString nom_client = ui->modifier_nom_client->text();
    QString adresse_client = ui->modifier_adresse_client->text();
    QString email_client = ui->modifier_email_client->text();
    QString type_client = ui->modifier_type_client->text();


bool test=tmpclient.modifier_client(id_client,nom_client,adresse_client,email_client,type_client);


if (test)
  {

    ui->table_client_2->setModel(tmpclient.afficher_client());//refresh
    ui->table_Re_client->setModel(tmpclient.afficher_Re_client(id_client));


QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                QObject::tr("Client modifier.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void event::on_chercher_client_clicked()
{

    QString id_client = ui->recherche_client_id->text();

    ui->table_Re_client->setModel(tmpclient.afficher_Re_client(id_client));//refresh

}

void event::on_tri_asc_clicked()
{
    ui->table_event->setModel(tmpevent.afficher_tri_ID());

}

void event::on_tri_desc_clicked()
{
    ui->table_event->setModel(tmpevent.afficher_tri_ID_DESC());
}

void event::on_tri_asc_clt_clicked()
{
    ui->table_client_2->setModel(tmpclient.afficher_tri_CLT());
}

void event::on_tri_desc_clt_clicked()
{
    ui->table_client_2->setModel(tmpclient.afficher_tri_CLT_DESC());
}

void statistique::on_pushButton_2_clicked()
{
    //ui->graphicsView->setScene(tmpevent.StatPromo_Product_type());
}


void event::on_pushButtonPDF_1_clicked()
{
     QString strStream;
     QTextStream out(&strStream);

                const int rowCount = ui->table_event->model()->rowCount();
                const int columnCount = ui->table_event->model()->columnCount();
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
                    if (!ui->table_event->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->table_event->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++)
                {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->table_event->isColumnHidden(column)) {
                            QString data =ui->table_event->model()->data(ui->table_event->model()->index(row, column)).toString().simplified();
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

void event::on_pushButtonPDF_2_clicked()
{
     QString strStream;
     QTextStream out(&strStream);

                const int rowCount = ui->table_client_2->model()->rowCount();
                const int columnCount = ui->table_client_2->model()->columnCount();
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
                    if (!ui->table_client_2->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->table_client_2->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++)
                {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->table_event->isColumnHidden(column)) {
                            QString data =ui->table_client_2->model()->data(ui->table_client_2->model()->index(row, column)).toString().simplified();
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

/*QGraphicsScene *event::StatPromo_Product_type()
{
    //Calculer la récurcivité de chaque type de produit
   event tempPromotion;
   QString test;

    int max=0;
    int DIVERTISSANT=0;
    int CHARITE=0;
    int CULTUREL=0;





    QSqlQueryModel * model=tempPromotion.Product_type_pro_list();


    max=model->rowCount();

    for (int i=0;i<model->rowCount();i++)
    {
        test=model->record(i).value(0).toString();





        if(test=="DIVERTISSANT")
        {
            DIVERTISSANT++;
        }
        else if(test=="CHARITE")
        {
            CHARITE++;

        }
        else if(test=="CULTUREL")
        {
            CULTUREL++;

        }


  }





//Génrer la statistiqueistique sur La QGraphiqueView


    QGraphicsScene *  scene = new QGraphicsScene();

    QGraphicsEllipseItem *ellipse1;
    QGraphicsEllipseItem *ellipse2;
    QGraphicsEllipseItem *ellipse3;




    QGraphicsTextItem *tex1;
    QGraphicsTextItem *tex2;
    QGraphicsTextItem *tex3;



    QGraphicsRectItem *rec1;
    QGraphicsRectItem *rec2;
    QGraphicsRectItem *rec3;


    QBrush greenBrush(Qt::green);
    QBrush redBrush(Qt::red);
    QBrush yellowBrush(Qt::yellow);

    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);

    int x=200;
    int y=100;
    int w=250;
    int h=250;


    ellipse1 = scene->addEllipse(x, y, w, h);
    ellipse1->setBrush(greenBrush);
    ellipse1->setStartAngle(((DIVERTISSANT*360)/max)*16);




    ellipse2 = scene->addEllipse(x, y, w, h);
    ellipse2->setBrush(redBrush);
    ellipse2->setStartAngle(((DIVERTISSANT*360)/max)*16);
    ellipse2->setSpanAngle(((CHARITE*360)/max)*16);


    ellipse3 = scene->addEllipse(x, y, w, h);
    ellipse3->setBrush(yellowBrush);
    ellipse3->setStartAngle((((DIVERTISSANT+CHARITE)*360)/max)*16);
    ellipse3->setSpanAngle(((CULTUREL*360)/max)*16);





    float DIVERTISSANT_pourcentage=((((DIVERTISSANT*360)/max))*100)/360;
    float CHARITE_pourcentage=((((CHARITE*360)/max))*100)/360;
    float CULTUREL_pourcentage=((((CULTUREL*360)/max))*100)/360;





    QString DIVERTISSANT_convert=QString::number( DIVERTISSANT_pourcentage);
    QString CHARITE_convert=QString::number(CHARITE_pourcentage);
    QString CULTUREL_convert=QString::number(CULTUREL_pourcentage);


    rec1 = scene->addRect(-20, 2, 20, 20, outlinePen, greenBrush);
    rec2 = scene->addRect(-20, 42, 20, 20, outlinePen, redBrush);
    rec3 = scene->addRect(-20, 80, 20, 20, outlinePen, yellowBrush);



    tex1 = scene->addText("DIVERTISSANT : "+DIVERTISSANT_convert+"%", QFont("Arial", 12));
    tex2 = scene->addText("\n\nCHARITE : "+CHARITE_convert+"%", QFont("Arial", 12) );
    tex3 = scene->addText("\n\n\n\nCULTUREL : "+CULTUREL_convert+"%", QFont("Arial", 12) );




    return scene;


}
*/
