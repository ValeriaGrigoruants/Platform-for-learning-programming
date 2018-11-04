#ifndef TEST_H
#define TEST_H

#include <QDialog>
#include <QFile>
#include <QDebug>

namespace Ui {
class Test;
}

class Test : public QDialog
{
    Q_OBJECT

public:
    explicit Test(QWidget *parent = nullptr);
    void readTest(int);
    ~Test();

signals:
    void test();

private slots:
    void on_next_clicked();

private:
    Ui::Test *ui;
    void setNum (int);
    int num;
    int counter = 0;
    int mark = 0;
    QString answer;
};

#endif // TEST_H
