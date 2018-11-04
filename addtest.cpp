#include "addtest.h"
#include "ui_addtest.h"

AddTest::AddTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTest)
{
    ui->setupUi(this);
    mistake = new MistakePlace();
    connect(mistake, &MistakePlace::mistakeWindow, this, &AddTest::show);
}

AddTest::~AddTest()
{
    delete ui;
}

void AddTest::on_back_clicked()
{
    emit testWindow();
    this -> close();
}

void AddTest::on_mistake_clicked()
{
    mistake -> show();
    this -> close();
}
