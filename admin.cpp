#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    newtest = new MistakePlace();
    connect(newtest, &MistakePlace::mistakeWindow, this, &Admin::show);

    new_student = new AddStudent();
    connect(new_student, &AddStudent::add, this, &Admin::show);

    fix_lecture = new FixLecture();
    connect (fix_lecture, &FixLecture::admin, this, &Admin::show);

}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_back_clicked()
{
    emit firstWindow();
    this -> close();
}

void Admin::on_test_clicked()
{
    this -> close();
    newtest -> show();
}

void Admin::on_student_clicked()
{
    this ->close();
    new_student ->show();
}

void Admin::on_edit_clicked()
{
    fix_lecture -> show();
    this ->close();
}

void Admin::on_results_clicked()
{
    result = new AllResults();
    result ->setUser("admin");
    connect (result, &AllResults::admin, this, &Admin::show);
    this ->close();
    result ->show();
}
