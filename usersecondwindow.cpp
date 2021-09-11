#include "usersecondwindow.h"
#include "ui_usersecondwindow.h"

#include"product_class.h"

UserSecondWindow::UserSecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserSecondWindow)
{
    ui->setupUi(this);
}

UserSecondWindow::~UserSecondWindow()
{
    delete ui;
}

void UserSecondWindow::on_pushButton_user_product_clicked()
{
    hide();
    /*product_class_ptr = new  Product_class;
    product_class_ptr->show();*/

    Product_class Product_class_object;
    Product_class_object.setModal(true);
    Product_class_object.exec();
    ////////////////////////////////////////////////
}


void UserSecondWindow::on_pushButton_user_profile_clicked()
{
    hide();
    user_profile_window_ptr = new user_profile_window;
    user_profile_window_ptr->show();
}

void UserSecondWindow::on_pushButton_user_home_clicked()
{
     hide();
     /*MyWindow_ob = new MyWindow;
     MyWindow_ob -> show();*/
}
