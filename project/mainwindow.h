#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStackedWidget>
#include <QMainWindow>
#include "personnel.h"
#include <QSystemTrayIcon>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QSystemTrayIcon;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void updateLabel();

    void on_ajouter_personnel_clicked();

    void on_rechercher_personnel_clicked();

    void on_supprimer_personnel_clicked();

    void on_modifier_persoonel_clicked();

    void on_verifier_personnel_clicked();

    void on_actionQuitter_triggered();

    void on_actionAbout_Qt_triggered();



private:
    Ui::MainWindow *ui;

    QSystemTrayIcon *mSystemTrayIcon;

QByteArray data;
 Personnel tmppersonnel;



};
#endif // MAINWINDOW_H

