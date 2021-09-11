#ifndef USERSECONDWINDOW_H
#define USERSECONDWINDOW_H

#include <QDialog>
#include "user_profile_window.h"
#include "product_class.h"
////
//#include "mywindow.h"


namespace Ui {
class UserSecondWindow;
}

class UserSecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserSecondWindow(QWidget *parent = nullptr);
    ~UserSecondWindow();

private slots:
    void on_pushButton_user_profile_clicked();

    void on_pushButton_user_product_clicked();

    void on_pushButton_user_home_clicked();

private:
    Ui::UserSecondWindow *ui;
    user_profile_window* user_profile_window_ptr;
    //Product_class* product_class_ptr;

    ////
    //MyWindow* MyWindow_ob;
};

#endif // USERSECONDWINDOW_H
