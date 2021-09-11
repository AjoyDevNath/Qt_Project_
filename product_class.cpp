#include "product_class.h"
#include "ui_product_class.h"

#include "product_one_db.h"

Product_class::Product_class(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Product_class)
{
    ui->setupUi(this);
}

Product_class::~Product_class()
{
    delete ui;
}

void Product_class::on_pushButton_grocery_clicked()
{
    hide();
    /*product_one_db_obj = new product_one_db;
    product_one_db_obj->show();*/

    product_one_db product_one_db_object;
    product_one_db_object.setModal(true);
    product_one_db_object.exec();


    /*if(db.open())
    {
        QMessageBox :: information(this,"Connector","Database connected");
    }
    else
    {
        QMessageBox :: information(this,"Connector","Database not connected");
    }*/
}
