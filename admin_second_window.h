#ifndef ADMIN_SECOND_WINDOW_H
#define ADMIN_SECOND_WINDOW_H

#include <QDialog>
#include "mywindow.h"

namespace Ui {
class Admin_second_window;
}

class Admin_second_window : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_second_window(QWidget *parent = nullptr);
    ~Admin_second_window();

private slots:
    void on_pushButton_user_clicked();

    void on_pushButton_item_clicked();

    void on_tableView_user_activated(const QModelIndex &index);

    void on_pushButton_save_clicked();

    void on_pushButton_edit_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::Admin_second_window *ui;
};

#endif // ADMIN_SECOND_WINDOW_H
