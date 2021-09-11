#include "admin_login_window.h"
#include "ui_admin_login_window.h"
#include <QPixmap>
#include<QMessageBox>
#include "admin_second_window.h"

Admin_login_Window::Admin_login_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_login_Window)
{
    ui->setupUi(this);

    //adding photo for admin panel

    QPixmap pix_object("C:/Users/user/Dropbox/My PC (ERROR-404)/Downloads/xyz.jpg");
    ui->label_admin_pic->setPixmap(pix_object.scaled(400,400,Qt::KeepAspectRatio));
}

Admin_login_Window::~Admin_login_Window()
{
    delete ui;
}

void Admin_login_Window::on_pushButton_admin_login_clicked()
{
    QString email,password;

    email = ui->lineEdit_admin_email->text();
    password = ui->lineEdit_admin_password->text();

    MyWindow conn;

    if(!conn.connection_open())//!false = true hole execute korbe
    {
        ui->label_checker->setText("Failed to open database");
        //QMessageBox::information(this,"Connection","Database not open bro!");
    }
    else{
        ui->label_checker->setText("Open database");
        //QMessageBox::information(this,"Connection","Database open bro!");
    }

    conn.connection_open();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM Admin_login WHERE Email='"+email+"' AND Password='"+password+"'");
    //qry.prepare("SELECT * FROM user_login WHERE username  ='"+user_name+"' AND Password ='"+pass_word+"'");

    if(qry.exec())
    {
        int count = 0;

        while(qry.next())
        {
            count++;
        }
        if(count == 1)
        {
            QMessageBox::information(this,"Login","Login Successfull");
            conn.connection_closed();

            hide();
            Admin_second_window Admin_second_window_object;
            Admin_second_window_object.setModal(true);
            Admin_second_window_object.exec();
        }
        if(count < 1)
        {
            QMessageBox::information(this,"Login","Password incorrect");
        }
    }

    /*if(email == "admin" && password == "admin")
    {
        QMessageBox :: information(this,"Login","Login successfully");

        hide();
        admin_second_window_Object = new  Admin_second_window;
        admin_second_window_Object -> show();
    }
    else
    {
        QMessageBox :: warning(this,"Login","Incorrect password!");
    }*/
}
