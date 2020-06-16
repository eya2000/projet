#ifndef EVENT_H
#define EVENT_H


#include <QDialog>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include "gestion_event.h"
#include "gestion_clt.h"
#include "statistique_event.h"
#include <QGraphicsScene>

namespace Ui {
class event;
}

class event : public QDialog
{
    Q_OBJECT

public:
    explicit event(QWidget *parent = nullptr);
    ~event();
    bool controle(QString);
    QSqlQueryModel *Product_type_pro_list();
    QGraphicsScene *StatPromo_Product_type();
private slots:
    void on_Ajouter_event_2_clicked();

    void on_supprimer_event_2_clicked();

    void on_Ajouter_client_2_clicked();

    void on_supprimer_client_2_clicked();

    void on_chercher_modif_event_clicked();

    void on_modifier_event_clicked();

    void on_modifier_client_clicked();

    void on_chercher_client_clicked();

    void on_Statistique_client_clicked();

    void on_tri_asc_clicked();

    void on_tri_desc_clicked();

    void on_tri_asc_clt_clicked();

    void on_tri_desc_clt_clicked();

    void on_pushButtonPDF_1_clicked();

    void on_pushButtonPDF_2_clicked();

private:
    Ui::event *ui;
    gestion_event tmpevent;
    gestion_clt tmpclient;
    gestion_clt    TMP;
        gestion_event TMPe;

};
#endif // EVENT_H
