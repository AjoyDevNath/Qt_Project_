#include "mywindow.h"
#include "ui_mywindow.h"
#include<QMessageBox>
#include<QPixmap> //addding phto in login form

#include "usersecondwindow.h"
#include "signup.h"
#include "admin_login_window.h"

 //adding database
#include<QtSql>
#include<QSqlDatabase>
#include<QFileInfo>
#include<QDebug>





MyWindow::MyWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyWindow)
{
    ui->setupUi(this);


    //adding photo in login form
    QPixmap pix_object(":/resources/img/shop.jpg");
    ui->label_pic->setPixmap(pix_object.scaled(400,400,Qt::KeepAspectRatio));

    QPixmap pix_object2(":/img-2/img-2/ima.jpg");



    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
}


void MyWindow::showTime()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->digital_clock->setText(time_text);
}

MyWindow::~MyWindow()
{
    delete ui;
}


void MyWindow::on_pushButton_user_login_clicked()
{

    /*QSqlDatabase db;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/Database/Grocery_shop_database.db");
    if(!db.open())
    {
        ui->label_debug->setText("Failedddddd to open database");
    }
    else{
        ui->label_debug->setText("Opennnnnnn database");
    }*/

     QString user_name,pass_word;

     user_name = ui->login_username->text();
     pass_word = ui->login_password->text();


    if(!connection_open())//!false = true hole execute korbe
    {
        //ui->label_debug->setText("Failed to open database");
        QMessageBox::information(this,"Connection","Database not open bro!");
    }
    connection_open();

    QSqlQuery qry;
    qry.prepare("SELECT * FROM user_login WHERE username  ='"+user_name+"' AND Password ='"+pass_word+"'");

    if(qry.exec())
    {
        int count = 0;

        while(qry.next())
        {
            count++;
        }
        if(count == 1)
        {
            QMessageBox::information(this,"Login","Login Successfully");
            connection_closed();
            hide();
            /*secondWindowOb = new UserSecondWindow;
            secondWindowOb -> show();
            */

            UserSecondWindow UserSecondWindow_object;
            UserSecondWindow_object.setModal(true);
            UserSecondWindow_object.exec();
        }
        if(count<1)
        {
            QMessageBox::information(this,"Login","Password incorrect");
        }
        if(count>1)
        {
            QMessageBox::information(this,"Login","Information Duplicated");
        }
    }
}

void MyWindow::on_pushButton_admin_login_clicked()
{
    hide();
    /*admin_loginOb = new Admin_login_Window;
    admin_loginOb -> show();*/
    Admin_login_Window Admin_login_Window_object;
    Admin_login_Window_object.setModal(true);
    Admin_login_Window_object.exec();
}

void MyWindow::on_pushButton_signup_clicked()
{
    hide();
    SignUp SignUp_object;
    SignUp_object.setModal(true);
    SignUp_object.exec();

    /*signup_ptr = new SignUp;
    signup_ptr->show();*/
}
