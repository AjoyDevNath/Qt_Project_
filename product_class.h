#ifndef PRODUCT_CLASS_H
#define PRODUCT_CLASS_H

#include <QDialog>
#include "product_one_db.h"


//database connection
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>

namespace Ui {
class Product_class;
}

class Product_class : public QDialog
{
    Q_OBJECT

public:
    explicit Product_class(QWidget *parent = nullptr);
    ~Product_class();

private slots:
    void on_pushButton_grocery_clicked();

private:
    Ui::Product_class *ui;
    //product_one_db* product_one_db_obj;
};

#endif // PRODUCT_CLASS_H
