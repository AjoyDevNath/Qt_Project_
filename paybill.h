#ifndef PAYBILL_H
#define PAYBILL_H

#include <QDialog>

namespace Ui {
class paybill;
}

class paybill : public QDialog
{
    Q_OBJECT

public:
    explicit paybill(QWidget *parent = nullptr);
    ~paybill();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::paybill *ui;
};

#endif // PAYBILL_H
