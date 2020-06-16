#ifndef DEPART_H
#define DEPART_H




#include <QDialog>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include "gestion_depart.h"
#include "gestion_parking.h"
#include <QGraphicsScene>



#include <QGraphicsScene>

namespace Ui {
class depart;
}

class depart : public QDialog
{
    Q_OBJECT

public:
    explicit depart(QWidget *parent = nullptr);
    ~depart();

private slots:
    void on_Ajouter_depart_2_clicked();

    void on_supprimer_depart_3_clicked();

    void on_Ajouter_parking_2_clicked();

   // void on_supprimer_parking_2_clicked();

    void on_chercher_modif_depart_clicked();

    void on_modifier_depart_clicked();

    void on_modifier_parking_clicked();

    void on_chercher_parking_clicked();


    void on_tri_asc_clicked();

  void on_tri_desc_clicked();

   void on_tri_asc_dpt_clicked();

    void on_tri_desc_dpt_clicked();

    void on_pushButtonPDF_1_clicked();

      void on_pushButtonPDF_2_clicked();


void on_comboBox_6_activated(const QString &arg1);
 void on_supprimer_2_clicked();

 void on_comboBox_8_activated(const QString &arg2);
  void on_supprimer_9_clicked();

private:
    Ui::depart *ui;
    gestion_depart tmpdepart;
  gestion_parking tmpparking;

     //depart tmpe;
   // statistique_event tmpstat;

};
#endif // DEPART_H
