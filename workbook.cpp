#include "workbook.h"
#include "ui_workbook.h"

Workbook::Workbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Workbook)
{
    ui->setupUi(this);
    //Workbook * wb = new Workbook();
    //wb -> readFile();
}
/*
void Workbook::readFile()
{
    QFile file("fir.txt");
    QByteArray data;
    if (!file.open(QIODevice::ReadOnly))
        return;
    data = file.readAll();
    qDebug() << QString(data);
}*/

Workbook::~Workbook()
{
    delete ui;
}

void Workbook::on_back_clicked()
{
    this -> close();
    emit lessons();
}
