#ifndef MYWINDOW_H
#define MYWINDOW_H
#include "usersecondwindow.h"
#include "admin_login_window.h"
#include "signup.h"

#include <QMainWindow>

#include "ui_mywindow.h"

//data_base_header_file

#include<QtSql>
#include<QSqlDatabase>
#include<QFileInfo>
#include<QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class MyWindow; }
QT_END_NAMESPACE

class MyWindow : public QMainWindow
{
    Q_OBJECT


public:

    //add database
    QSqlDatabase db;


    //close_database_connection
    void connection_closed()
    {
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }

    //open_database_connetion
    bool connection_open()
    {
        QSqlDatabase db = QSqlDatabase :: addDatabase("QSQLITE");

        db.setDatabaseName("E:/Database/Grocery_shop_database.db");


        if(!db.open())
        {
            //QMessageBox :: information(this,"Connection","Not open database");
            //ui->label_debug->setText("Failed open database");
            return false;
        }
        else
        {
            //QMessageBox :: information(this,"Connection","Open database");
           // ui->label_debug->setText("Database is open");
            return true;
        }
    }

public:
    MyWindow(QWidget *parent = nullptr);
    ~MyWindow();


private slots:
    void on_pushButton_user_login_clicked();

    void on_pushButton_admin_login_clicked();

    void on_pushButton_signup_clicked();

    void showTime();

private:
    Ui::MyWindow *ui;

    //UserSecondWindow* secondWindowOb;

    //Admin_login_Window* admin_loginOb;
    //SignUp* signup_ptr;
};
#endif // MYWINDOW_H
