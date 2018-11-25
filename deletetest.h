#ifndef DELETETEST_H
#define DELETETEST_H

#include <QDialog>
#include <QFile>
#include <QDebug>

namespace Ui {
class DeleteTest;
}

class DeleteTest : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteTest(QWidget *parent = nullptr);
    void showTest();
    ~DeleteTest();

signals:
    void admin();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_back_clicked();

    void on_previous_clicked();

    void on_next_clicked();

    void on_delete_2_clicked();

private:
    Ui::DeleteTest *ui;
    int current = 0;
    QString cur_test = "C:\\Users\\Valeria\\Documents\\LearnProgramming\\Tests\\firstlection.txt";
};

#endif // DELETETEST_H
