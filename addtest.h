#ifndef ADDTEST_H
#define ADDTEST_H

#include <QDialog>
#include <mistakeplace.h>

namespace Ui {
class AddTest;
}

class AddTest : public QDialog
{
    Q_OBJECT

signals:
    void testWindow();

public:
    explicit AddTest(QWidget *parent = nullptr);
    ~AddTest();

private slots:
    void on_back_clicked();

    void on_mistake_clicked();

private:
    Ui::AddTest *ui;
    MistakePlace * mistake;
};

#endif // ADDTEST_H
