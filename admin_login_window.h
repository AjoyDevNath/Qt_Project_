#ifndef ADMIN_LOGIN_WINDOW_H
#define ADMIN_LOGIN_WINDOW_H

#include <QDialog>
#include "admin_second_window.h"

#include "mywindow.h"

namespace Ui {
class Admin_login_Window;
}

class Admin_login_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_login_Window(QWidget *parent = nullptr);
    ~Admin_login_Window();

private slots:
    void on_pushButton_admin_login_clicked();

private:
    Ui::Admin_login_Window *ui;
    //Admin_second_window* admin_second_window_Object;//modelless approach
};

#endif // ADMIN_LOGIN_WINDOW_H
