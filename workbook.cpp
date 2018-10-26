#include "workbook.h"
#include "ui_workbook.h"

Workbook::Workbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Workbook)
{
    ui->setupUi(this);
}

void Workbook::readFile(int number)
{

    if (number == 1)
    {
        QFile file("C:\\Users\\Valeria\\Documents\\LearnProgramming\\first.txt");
        if (file.open(QIODevice::ReadOnly))
        {
            ui->textBrowser->setText(file.readAll());
            file.close();
        }
    }
    else if (number == 2)
    {
        QFile file("C:\\Users\\Valeria\\Documents\\LearnProgramming\\second.txt");
        if (file.open(QIODevice::ReadOnly))
        {
            ui->textBrowser->setText(file.readAll());
            file.close();
        }
    }
    else if (number == 3)
    {
        QFile file("C:\\Users\\Valeria\\Documents\\LearnProgramming\\third.txt");
        if (file.open(QIODevice::ReadOnly))
        {
            ui->textBrowser->setText(file.readAll());
            file.close();
        }
    }
    else if (number == 4)
    {
        QFile file("C:\\Users\\Valeria\\Documents\\LearnProgramming\\fourth.txt");
        if (file.open(QIODevice::ReadOnly))
        {
            ui->textBrowser->setText(file.readAll());
            file.close();
        }
    }
}

Workbook::~Workbook()
{
    delete ui;
}

void Workbook::on_back_clicked()
{
    this -> close();
    emit lessons();
}
