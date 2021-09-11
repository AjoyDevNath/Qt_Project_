#include "user_profile_class.h"
#include "ui_user_profile_class.h"

user_profile_class::user_profile_class(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_profile_class)
{
    ui->setupUi(this);
}

user_profile_class::~user_profile_class()
{
    delete ui;
}
