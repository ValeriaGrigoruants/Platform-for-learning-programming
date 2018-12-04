#ifndef WORKBOOK_H
#define WORKBOOK_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <test.h>

namespace Ui {
class Workbook;
}

class Workbook : public QDialog
{
    Q_OBJECT


public:

    explicit Workbook(QWidget *parent = nullptr);
    void readFile(int);
    void setUser(QString);
    QString getUser();
    ~Workbook();

signals:
    void lessons();

private slots:
    void on_back_clicked();

    void on_test_clicked();

private:
    int num;
    void setNum(int);
    int getNum();
    QString user;
    Ui::Workbook *ui;
    Test * test;
};

#endif // WORKBOOK_H
