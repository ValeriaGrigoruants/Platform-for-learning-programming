#include "test.h"
#include "ui_test.h"

Test::Test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);

}

void Test::readTest(int number)
{
    QFile file;
    num = number;
    if (number == 1)
    {
       file.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Tests\\firstlection.txt");
    }
    else if (number == 2)
    {
        file.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Tests\\secondlection.txt");
    }
    else if (number == 3)
    {
        file.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Tests\\thirdlection.txt");
    }
    else if (number == 4)
    {
        file.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Tests\\fourthlection.txt");
    }
    if (file.open(QIODevice::ReadOnly))
    {
        for (int i = 0; i < counter; ++i)
        {
            if (!file.atEnd())
                file.readLine();
        }
        answer = "";
        if (!file.atEnd())
        {

            ui -> question ->setText("<h3 align = \"center\">" + file.readLine() + "</h3>");
            QString fir = file.readLine();
            QString sec = file.readLine();
            answer = fir.split("\r").at(0) + sec.split("\r").at(0);
            counter += 4;
        }
        if (answer == "")
        {
            ui -> wrong ->close();
            ui -> right -> close();
            ui -> label_2 -> close();
            ui -> label_3 -> close();
            ui -> question ->setText("<h3 align = \"center\">Your mark is: " + QString::number(mark) + "</h3>");
        }
        file.close();
    }
}

Test::~Test()
{
    delete ui;
}

void Test::on_next_clicked()
{
    QString ans = "\tWrong: " + ui -> wrong ->text() + "\tRight: " + ui -> right -> text();
    if (ans == answer)
    {
        mark++;
    }
    ui -> wrong -> clear();
    ui ->right -> clear();
    readTest (num);
}
