#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    newtest = new AddTest();
    connect(newtest, &AddTest::testWindow, this, &Admin::show);
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
