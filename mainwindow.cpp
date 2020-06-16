#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <employe.h>
#include<depart.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/LENOVO/Downloads/hotel2.png");
    ui->label->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connecter_clicked()
{
    employe e;
    int poste;
    QString username = ui->login_2->text();
    QString password = ui ->mdp->text();
    if (e.verifierCompte(username,password)==2||e.verifierCompte(username,password)==1)
    {
            poste=e.verifierStatut(username,password);

            ui->mdp->clear();
            ui->login_2->clear();
        if (poste==0)
        {
            QMessageBox::information(this, "login","Admin");
            class depart e;
            e.setModal(true);
            e.exec();
        }
        if (poste==1)
        {
            QMessageBox::information(this, "login","Agent des departements");
            class depart e;
            e.setModal(true);
            e.exec();
        }
    /*    else if (poste==2)
        {
            QMessageBox::information(this, "login","");
            Bus r;
            r.setModal(true);
            r.exec();
        }
        else if (poste==3)
        {
            QMessageBox::information(this, "login","");
            gestionTrajet r;
            r.setModal(true);
            r.exec();
        }
        else if (poste==4)
        {
            QMessageBox::information(this, "login","");
            Gestionpromo = new gestionpromo();
            Gestionpromo->show();
        }
        else if (poste==5)
        {
            QMessageBox::information(this, "login","");
            gestion r;
            r.setModal(true);
            r.exec();
        }*/
    }
    else
    {
       QMessageBox::warning(this, "login","username and password are not correct");
    }
}
