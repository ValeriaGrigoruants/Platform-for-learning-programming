#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <addstudent.h>
#include <mistakeplace.h>
#include <fixlecture.h>
#include <allresults.h>
#include <deletetest.h>

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

    void on_student_clicked();

    void on_edit_clicked();

    void on_results_clicked();

    void on_delete_test_clicked();

private:
    Ui::Admin *ui;

    MistakePlace *newtest;

    AddStudent *new_student;

    FixLecture *fix_lecture;

    AllResults *result;

    DeleteTest *del_test;
};

#endif // ADMIN_H
