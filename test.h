#ifndef TEST_H
#define TEST_H

#include <QDialog>
#include <QFile>
#include <QDebug>
//#include <mainwindow.h>

namespace Ui {
class Test;
}

class Test : public QDialog
{
    Q_OBJECT

public:
    explicit Test(QWidget *parent = nullptr);
    void readTest(int);
    void setUser(QString);
    QString getUser();
    ~Test();

signals:
    void test();
    void back_to_lec();

private slots:
    void on_next_clicked();

    void on_back_clicked();

private:
    Ui::Test *ui;
    void setNum (int);
    int num;
    int counter = 0;
    int mark = 0;
    int all = 0;
    QString answer;
    QString user;
};

#endif // TEST_H
