#ifndef USER_PROFILE_CLASS_H
#define USER_PROFILE_CLASS_H

#include <QDialog>

namespace Ui {
class user_profile_class;
}

class user_profile_class : public QDialog
{
    Q_OBJECT

public:
    explicit user_profile_class(QWidget *parent = nullptr);
    ~user_profile_class();

private:
    Ui::user_profile_class *ui;


};

#endif // USER_PROFILE_CLASS_H
