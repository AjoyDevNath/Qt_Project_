#ifndef SIGNUP_H
#define SIGNUP_H
#include "mywindow.h"

#include <QDialog>
#include "usersecondwindow.h"

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:

    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_pushButton_signUP_clicked();

private:
    Ui::SignUp *ui;
    //UserSecondWindow* userSecondWindowObject;
};

#endif // SIGNUP_H
