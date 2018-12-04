#include "workbook.h"
#include "ui_workbook.h"

Workbook::Workbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Workbook)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:\\Users\\Valeria\\Documents\\LearnProgramming\\back.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    test = new Test();
    connect(test, &Test::test, this, &Workbook::show);
}

void Workbook::setNum (int i)
{
    num = i;
}

int Workbook::getNum()
{
    return num;
}

void Workbook::readFile(int number)
{
    setNum(number);
    if (number == 1)
    {
        QFile file("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Lectures\\first.txt");
        if (file.open(QIODevice::ReadOnly))
        {
            ui->textBrowser->setText(file.readAll());
            file.close();
        }
    }
    else if (number == 2)
    {
        QFile file("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Lectures\\second.txt");
        if (file.open(QIODevice::ReadOnly))
        {
            ui->textBrowser->setText(file.readAll());
            file.close();
        }
    }
    else if (number == 3)
    {
        QFile file("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Lectures\\third.txt");
        if (file.open(QIODevice::ReadOnly))
        {
            ui->textBrowser->setText(file.readAll());
            file.close();
        }
    }
    else if (number == 4)
    {
        QFile file("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Lectures\\fourth.txt");
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

void Workbook::on_test_clicked()
{
    int temp = 0;
    QFile file ("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Results\\" + getUser() + ".txt");
    if (file.open(QIODevice::ReadOnly))
    {
        while (!file.atEnd())
        {
            if (file.readLine().size() > 6)
                temp++;
        }
    }
    if (temp == getNum() - 1)
    {
        this -> close();
        test -> setUser(getUser());
        test -> show();
        test -> readTest(getNum());
    }
    else
    {
        QMessageBox::information(this, "System", "You have already passed this test!");
    }
}

void Workbook::setUser(QString student)
{
    user = student;
}

QString Workbook::getUser()
{
    return user;
}
