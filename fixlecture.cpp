#include "fixlecture.h"
#include "ui_fixlecture.h"

FixLecture::FixLecture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FixLecture)
{
    ui->setupUi(this);
    QFile file;
    file.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Lectures\\first.txt");
    if (file.open(QIODevice::ReadOnly))
    {
        ui ->text ->setText(file.readAll());
        file.close();
    }
}

FixLecture::~FixLecture()
{
    delete ui;
}

void FixLecture::on_back_clicked()
{
    this -> close();
    emit admin();
}

void FixLecture::on_fix_clicked()
{
    QFile edit;
    QString arg1 = ui -> choose -> currentText();
    if (arg1 == "Lecture 1")
    {
        edit.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Lectures\\first.txt");
    }
    else if (arg1 == "Lecture 2")
    {
        edit.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Lectures\\second.txt");
    }
    else if (arg1 == "Lecture 3")
    {
        edit.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Lectures\\third.txt");
    }
    else if (arg1 == "Lecture 4")
    {
        edit.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Lectures\\fourth.txt");
    }
    if (edit.open(QIODevice::WriteOnly))
    {
        QString New_Text = ui ->text ->toHtml();
        //QString New_Text = ui -> text ->toPlainText();

        edit.write(New_Text.toUtf8());
        edit.close();
    }
}



void FixLecture::on_choose_currentIndexChanged(const QString &arg1)
{
    QFile file;
    if (arg1 == "Lecture 1")
    {
        file.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Lectures\\first.txt");
    }
    else if (arg1 == "Lecture 2")
    {
        file.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Lectures\\second.txt");
    }
    else if (arg1 == "Lecture 3")
    {
        file.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Lectures\\third.txt");
    }
    else if (arg1 == "Lecture 4")
    {
        file.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Lectures\\fourth.txt");
    }
    if (file.open(QIODevice::ReadWrite))
    {
        ui ->text ->setText(file.readAll());
        file.close();
    }
}
