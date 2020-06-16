#ifndef GESTION_PARKING_H
#define GESTION_PARKING_H



#include <QString>
#include <QtSql/QSqlQueryModel>

class gestion_parking
{
public:
    gestion_parking();
    gestion_parking(QString,QString,QString);


    QString get_cin();
    QString get_immatricule();
    QString get_num_tel();


    bool ajouter_parking();
    QSqlQueryModel * afficher_parking();
    bool supprimer_parking(QString cin);
    bool modifier_parking(QString, QString, QString );
    QSqlQueryModel * afficher_Re_parking(QString);
    QSqlQueryModel * afficher_tri_PRK();
    QSqlQueryModel * afficher_tri_PRK_DESC();
      bool existe(QString);
      QSqlQueryModel *afficher_list();

  void setid(QString);

private:
    QString  cin , immatricule , num_tel;

};
#endif // GESTION_PARKING_H
