#include "signup.h"
#include "ui_signup.h"
#include <QMessageBox>

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);


    MyWindow conn;
    if(!conn.connection_open())
    {
        ui->label_connection->setText("Failed to open database");
    }
    else
    {
        ui->label_connection->setText("Open database");
    }
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushButton_signUP_clicked()
{
    QString Name,username,email,password;
    Name = ui->lineEdit_name->text();
    username = ui->lineEdit_username->text();
    email = ui->lineEdit_email->text();
    password = ui->lineEdit_password->text();

    MyWindow conn;

    /*if(!conn.connection_open())
    {
        ui->label_connection->setText("Faileddd to open database");
    }*/
    conn.connection_open();
    QSqlQuery qry;
    qry.prepare("INSERT INTO user_login (Name,username,Email,Password) VALUES('"+Name+"','"+username+"','"+email+"','"+password+"')");
    if(qry.exec())
    {
        QMessageBox::information(this,"Save","Saved data");
        conn.connection_closed();
    }
    else
    {
        QMessageBox::information(this,"Save","Saved data not");
    }



    QMessageBox :: information(this,"Creating Account","Welcome To Our System");

    hide();
    /*userSecondWindowObject = new UserSecondWindow;
    userSecondWindowObject->show();*/
    SignUp SignUp_object;
    SignUp_object.setModal(true);
    SignUp_object.exec();
}
