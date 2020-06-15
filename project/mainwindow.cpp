#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personnel.h"
#include <QMessageBox>
#include <QPixmap>
#include<QSystemTrayIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabpersonnel->setModel(tmppersonnel.afficher());
    ui->tab_tri->setModel(tmppersonnel.afficher_personnel_trier());
   for(int i=25 ;i<60;i++)

            {

                ui->comboBox->addItem(QString::number(i)+"ans");

             }
}

MainWindow::~MainWindow()
{
    delete ui;
}







void MainWindow::on_ajouter_personnel_clicked()
{   mSystemTrayIcon->showMessage(tr("Ajouter un personnel!"),
                                 tr("personnel ajouté.\n"));
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString  age= ui->comboBox->currentText();
    int id_service = ui->lineEdit_id_service->text().toInt();

  Personnel p(id,nom,prenom,age,id_service);
  bool test=p.ajouter();
  if(test)
{
      ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
         ui->tab_tri->setModel(tmppersonnel.afficher_personnel_trier());
QMessageBox::information(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("Personnel ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}
  else

            QMessageBox::critical(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_rechercher_personnel_clicked()
{
    mSystemTrayIcon->showMessage(tr("rechercher un service!"),
                                     tr("service recherché.\n"));
    QString str=ui->lineEdit_id_4->text();
    ui->tableView_3->setModel(tmppersonnel.recherche(str));
}

void MainWindow::on_supprimer_personnel_clicked()
{
    mSystemTrayIcon->showMessage(tr("supprimer un personnel!"),
                                   tr("personnel supprimé .\n"));
   int id = ui->tmppersonnel->text().toInt();
   bool test=tmppersonnel.supprimer(id);
   if(test)
   {
       ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
      ui->tab_tri->setModel(tmppersonnel.afficher_personnel_trier());
       QMessageBox::information(nullptr, QObject::tr("Supprimer un personnel"),
                   QObject::tr("Personnel supprimé.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Supprimer un personnel"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);




}

void MainWindow::on_modifier_persoonel_clicked()
{
    mSystemTrayIcon->showMessage(tr("modifier un personnel!"),
                                  tr("personnel modifié.\n"));
        int id = ui->lineEdit_idm->text().toInt();
        QString nom= ui->lineEdit_nomm->text();
        QString prenom= ui->lineEdit_premomm->text();
         QString age= ui->lineEdit_agem->text();
         int id_service = ui->lineEdit_37->text().toInt();

       Personnel p(id,nom,prenom,age,id_service);
      bool test=p.modifier(id);
      if(test)
    {ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
       ui->tab_tri->setModel(tmppersonnel.afficher_personnel_trier());
    QMessageBox::information(nullptr, QObject::tr("Modifier un personnel"),
                      QObject::tr("Personnel modifier.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier personnel"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_verifier_personnel_clicked()
{
    mSystemTrayIcon->showMessage(tr("Verifier un personnel!"),
                                          tr("personnel verifié.\n"));
    int id = ui->lineEdit_38->text().toInt();

       Personnel test= tmppersonnel.verifier(id);

       if (test.get_id()==id)

      {

           QMessageBox::information(nullptr, QObject::tr("Rechercher un Personnel"),

                           QObject::tr("Personnel trouvé.\n"

                                       "Click Cancel to exit."),
QMessageBox::Cancel);

            }

       else


       {

           QMessageBox::critical(nullptr, QObject::tr("Error !"),

           QObject::tr("Echech de l'Opération !.\n"

                        "Click Cancel to exit."), QMessageBox::Cancel);

       }

}

void MainWindow::on_actionQuitter_triggered()
{
     close();
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::information(nullptr, QObject::tr("info !"),

    QObject::tr("information qt !.\n"

                 "Click Cancel to exit."), QMessageBox::Cancel);
}
