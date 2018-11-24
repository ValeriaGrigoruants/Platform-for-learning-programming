#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QDialog>
#include <QFile>

namespace Ui {
class AddStudent;
}

class AddStudent : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudent(QWidget *parent = nullptr);
    ~AddStudent();

private slots:
    void on_back_clicked();

    void on_add_clicked();

signals:
    void add();

private:
    Ui::AddStudent *ui;
};

#endif // ADDSTUDENT_H
