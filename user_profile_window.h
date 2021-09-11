#ifndef USER_PROFILE_WINDOW_H
#define USER_PROFILE_WINDOW_H

#include <QDialog>
#include "user_profile_class.h"

namespace Ui {
class user_profile_window;
}

class user_profile_window : public QDialog
{
    Q_OBJECT

public:
    explicit user_profile_window(QWidget *parent = nullptr);
    ~user_profile_window();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_2_pro_clicked();

private:
    Ui::user_profile_window *ui;
    user_profile_class*   user_profile_class_ptr;
};

#endif // USER_PROFILE_WINDOW_H
