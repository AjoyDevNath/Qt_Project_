#include "paybill.h"
#include "ui_paybill.h"
#include<QPixmap>


paybill::paybill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paybill)
{
    ui->setupUi(this);
    QPixmap pix("E:/QT project/MyApplication/img/Bkash_logo");
    ui->label_bkash->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));

    QPixmap pix2("E:/QT project/MyApplication/img/Rocket_logo");
    ui->label_rocket->setPixmap(pix2.scaled(100,100,Qt::KeepAspectRatio));

    QPixmap pix3("E:/QT project/MyApplication/img/Nagad_logo");
    ui->label_nagad->setPixmap(pix3.scaled(100,100,Qt::KeepAspectRatio));

    ui->comboBox->addItem("Bkash");
    ui->comboBox->addItem("Rocket");
    ui->comboBox->addItem("Nagad");
}

paybill::~paybill()
{
    delete ui;
}
