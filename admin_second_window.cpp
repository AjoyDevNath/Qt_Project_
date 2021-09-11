#include "admin_second_window.h"
#include "ui_admin_second_window.h"
#include<QMessageBox>
Admin_second_window::Admin_second_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_second_window)
{
    ui->setupUi(this);

}

Admin_second_window::~Admin_second_window()
{
    delete ui;
}



void Admin_second_window::on_pushButton_user_clicked()
{
    ui->label_name->setText("Name");
    ui->label_username->setText("Username");
    ui->label_email->setText("Email");
    ui->label_password->setText("Password");



    MyWindow conn;//mywindow.cpp class er object conn ta/////////////////////////
    QSqlQueryModel* modal = new QSqlQueryModel();

    conn.connection_open();
    QSqlQuery* qry = new QSqlQuery(conn.db);

    qry->prepare("SELECT * FROM user_login");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_user->setModel(modal);
    conn.connection_closed();

    qDebug()<<("modal->rowCount");
}

void Admin_second_window::on_pushButton_item_clicked()
{
    ui->label_name->setText("Product_Name");
    ui->label_username->setText("Product_Code");
    ui->label_email->setText("Weight");
    ui->label_password->setText("Price");

    MyWindow conn;//mywindow.cpp class er object conn ta/////////////////////////
    QSqlQueryModel* modal = new QSqlQueryModel();

    conn.connection_open();
    QSqlQuery* qry = new QSqlQuery(conn.db);

    qry->prepare("SELECT * FROM Grocery_item");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_user->setModel(modal);
    conn.connection_closed();

    qDebug()<<("modal->rowCount");
}

void Admin_second_window::on_tableView_user_activated(const QModelIndex &index)
{
    QString value = ui->tableView_user->model()->data(index).toString();
    MyWindow conn;

    if(!conn.connection_open())
    {
        QMessageBox :: information(this,"Connection","Connection not open");
        return ;
    }

    conn.connection_open();

    QSqlQuery qry;

    qry.prepare("SELECT * FROM user_login WHERE Name ='"+value+"' or username ='"+value+"' or Email ='"+value+"' or Password = '"+value+"'");


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->txt_name->setText(qry.value(0).toString());
            ui->txt_username->setText(qry.value(1).toString());
            ui->txt_email->setText(qry.value(2).toString());
            ui->txt_password->setText(qry.value(3).toString());
        }
        conn.connection_closed();
    }

    /*conn.connection_open();
    qry.prepare("SELECT * FROM Grocery_item WHERE Product_code ='"+value+"' or Product_name ='"+value+"' or Weight ='"+value+"' or Price = '"+value+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->txt_name->setText(qry.value(0).toString());
            ui->txt_username->setText(qry.value(1).toString());
            ui->txt_email->setText(qry.value(2).toString());
            ui->txt_password->setText(qry.value(3).toString());
        }
        conn.connection_closed();
    }*/
    else
    {
        QMessageBox :: information(this,"Connection","Query Not Execute");
    }
}

void Admin_second_window::on_pushButton_save_clicked()
{
    MyWindow conn;

    QString name,username,email,password;

    name = ui->txt_name->text();
    username = ui->txt_username->text();
    email = ui->txt_email->text();
    password = ui->txt_password->text();


    if(!conn.connection_open())//problem lineeee
    {
        QMessageBox::information(this,"connection","connection open");
    }
    else
    {
        QMessageBox::information(this,"connection","connection open");
    }
    conn.connection_open();

    QSqlQuery qry;

    qry.prepare("INSERT INTO user_login(Name,username,Email,Password) VALUES('"+name+"','"+username+"','"+email+"','"+password+"')");

    if(qry.exec())
    {
         QMessageBox :: information(this,"Record","Added new record");
         conn.connection_closed();
    }
    else
    {
        QMessageBox :: critical(this,tr("Record"),"record not saved");
    }
}

void Admin_second_window::on_pushButton_edit_clicked()
{
    MyWindow conn;

    QString name,username,email,password;

    name = ui->txt_name->text();
    username = ui->txt_username->text();
    email = ui->txt_email->text();
    password = ui->txt_password->text();

    conn.connection_open();


    QSqlQuery qry;

    qry.prepare("UPDATE user_login SET Name = '"+name+"', username = '"+username+"',Email = '"+email+"',Password = '"+password+"' WHERE Email='"+email+"' " );

    if(qry.exec())/////////////problem
    {
         QMessageBox :: information(this,"Updated","Updated successfull");
         conn.connection_closed();
    }
    else
    {
        QMessageBox :: critical(this,"Updated","Updated not successfull");
    }
}

void Admin_second_window::on_pushButton_delete_clicked()
{
    MyWindow conn;

    QString name,username,email,password;

    name = ui->txt_name->text();
    username = ui->txt_username->text();
    email = ui->txt_email->text();
    password = ui->txt_password->text();

    conn.connection_open();


    QSqlQuery qry;

    qry.prepare("DELETE FROM user_login WHERE Name = '"+name+"' OR username = '"+username+"' OR Email = '"+email+"' OR Password = '"+password+"'");

    if(qry.exec())/////////////problem
    {
         QMessageBox :: information(this,"Deleted","Delete data successfull");
         conn.connection_closed();
    }
    else
    {
        QMessageBox :: critical(this,"Deleted","Deleted not successfull");
    }
}
