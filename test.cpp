#include "test.h"
#include "ui_test.h"

Test::Test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);
    ui -> back -> hide();

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
            all++;
            counter += 4;
        }
        if (answer == "")
        {
            ui -> wrong ->hide();
            ui -> right -> hide();
            ui -> label_2 -> hide();
            ui -> label_3 -> hide();
            ui -> next -> hide();
            ui -> back ->show();
            mark = 100 * mark / all;
            ui -> question ->setText("<h3 align = \"center\">Your mark is: " + QString::number(mark) + "</h3>");
            QString name = getUser() + ".txt";
            QFile student ("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Results\\" + name);
            if (student.open(QIODevice::Append))
            {
                QString temp = "Lecture " + QString::number(number) + " total mark is " + QString::number(mark) + "\r\n";
                std::string str = temp.toStdString();
                const char* p = str.c_str();
                student.write(p);
                student.close();
            }
            mark = 0;
            counter = 0;
            all = 0;
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

void Test::setUser(QString student)
{
    user = student;
}

QString Test::getUser()
{
    return user;
}

void Test::on_back_clicked()
{
    ui -> wrong ->show();
    ui -> right -> show();
    ui -> label_2 -> show();
    ui -> label_3 -> show();
    ui -> next -> show();
    this -> close();
    emit test();
    ui ->back ->hide();
}
