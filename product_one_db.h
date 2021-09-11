#ifndef PRODUCT_ONE_DB_H
#define PRODUCT_ONE_DB_H

#include "mywindow.h"

#include <QDialog>



namespace Ui {
class product_one_db;
}

class product_one_db : public QDialog
{
    Q_OBJECT

public:


    explicit product_one_db(QWidget *parent = nullptr);
    ~product_one_db();

private slots:
    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_addBill_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_pushButton_6_clicked();

    void on_pushButton_payment_clicked();

    void on_label_logout_linkActivated(const QString &link);

private:
    Ui::product_one_db *ui;
};

#endif // PRODUCT_ONE_DB_H
