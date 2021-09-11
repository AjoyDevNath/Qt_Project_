#include "product_one_db.h"
#include "ui_product_one_db.h"

#include<QtSql>
#include<QSqlDatabase>
#include<QFileInfo>
#include<QDebug>
#include<QMessageBox>

#include "paybill.h"


product_one_db::product_one_db(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::product_one_db)
{
    ui->setupUi(this);

    //////////////
    MyWindow conn;
    if(!conn.connection_open())
    {
        ui->label_debug_checker->setText("Failed to open database");
    }
    else
    {
        ui->label_debug_checker->setText("Open database");
    }


    /*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");;

    db.setDatabaseName("E:/Database/Grocery_shop_database.db");

    if(!db.open())
    {
        ui->label_debug_checker->setText("Failed to open database");
    }
    else{
        ui->label_debug_checker->setText("Open database");
    }*/
}

product_one_db::~product_one_db()
{
    delete ui;
}

void product_one_db::on_pushButton_clicked()
{
    MyWindow conn;//mywindow.cpp class er object conn ta/////////////////////////
    QSqlQueryModel* modal = new QSqlQueryModel();

    conn.connection_open();
    QSqlQuery* qry = new QSqlQuery(conn.db);

    qry->prepare("SELECT * FROM Grocery_item");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connection_closed();

    qDebug()<<("modal->rowCount");
}

void product_one_db::on_tableView_activated(const QModelIndex &index)
{
    QString value = ui->tableView->model()->data(index).toString();
    MyWindow conn;

    if(!conn.connection_open())
    {
        QMessageBox :: information(this,"Connection","Connection not open");
        return ;
    }

    QSqlDatabase db;

    //db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("E:/Database/Grocery_shop_database.db");

    /*if(!db.open())
    {
        QMessageBox::information(this,"Connection","Database not open broooooooooo!");
    }
    else
    {
        QMessageBox::information(this,"Connection","Database open broooooooooo!");
    }*/

    conn.connection_open();



    //db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("E:/Database/Grocery_shop_database.db");
    /*if(!db.open())
    {
        QMessageBox::critical(this,"Connection","Database not open bros!");
    }
    else{
        QMessageBox::critical(this,"Connection","Database open bros!");
    }*/

    /*if(!conn.connection_open())
    {
        QMessageBox :: information(this,"Connection","Connection not bro");
    }
    else{
        QMessageBox :: information(this,"Connection","Connection open bro");
    }*/

    QSqlQuery qry;

    qry.prepare("SELECT * FROM Grocery_item WHERE Product_code ='"+value+"' or Product_name ='"+value+"' or Weight ='"+value+"' or Price = '"+value+"'");

    if(qry.exec())
    {
        //QMessageBox :: information(this,"Connection","Query is Execute");
        while(qry.next())
        {
            ui->txt_name->setText(qry.value(1).toString());
            ui->txt_price->setText(qry.value(3).toString());
            ui->txt_code->setText(qry.value(0).toString());
            ui->txt_quantity->setText(qry.value(2).toString());
        }
        conn.connection_closed();
    }
    else
    {
        QMessageBox :: information(this,"Connection","Query Not Execute");
    }
}

void product_one_db::on_pushButton_addBill_clicked()
{

    MyWindow conn;

    QString product_name,product_code,product_price;

    product_name = ui->txt_name->text();
    product_code = ui->txt_code->text();
    product_price = ui->txt_price->text();



    if(!conn.connection_open())//problem lineeee
    {
        QMessageBox::information(this,"connection","connection open");
    }

    conn.connection_open();

    QSqlQuery qry;

    qry.prepare("INSERT INTO Bill_table(Product_name,Product_code,Price) VALUES('"+product_name+"','"+product_code+"','"+product_price+")");

    if(qry.exec())
    {
         QMessageBox :: information(this,"Record","Added");
         conn.connection_closed();
    }
    else
    {
        QMessageBox :: critical(this,tr("Record"),"not added");
    }
}


void product_one_db::on_pushButton_payment_clicked()
{
    hide();
    paybill paybill_object;
    paybill_object.setModal(true);
    paybill_object.exec();
}
