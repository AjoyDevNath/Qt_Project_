#include "user_profile_window.h"
#include "ui_user_profile_window.h"

user_profile_window::user_profile_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_profile_window)
{
    ui->setupUi(this);
}

user_profile_window::~user_profile_window()
{
    delete ui;
}

void user_profile_window::on_pushButton_2_clicked()
{
    hide();
    user_profile_class_ptr = new user_profile_class;
    user_profile_class_ptr->show();
}
