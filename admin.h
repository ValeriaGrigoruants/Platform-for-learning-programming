#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <addtest.h>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

signals:
    void firstWindow();

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_back_clicked();

    void on_test_clicked();

private:
    Ui::Admin *ui;
    AddTest *newtest;
};

#endif // ADMIN_H
