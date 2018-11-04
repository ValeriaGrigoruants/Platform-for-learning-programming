#include "mistakeplace.h"
#include "ui_mistakeplace.h"

MistakePlace::MistakePlace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MistakePlace)
{
    ui->setupUi(this);
}

MistakePlace::~MistakePlace()
{
    delete ui;
}

void MistakePlace::on_back_clicked()
{
    emit mistakeWindow();
    this -> close();
}

void MistakePlace::on_add_clicked()
{
    QFile file;
    QFile wrongsen;
    QString sen = ui -> sentence -> text() + "\r\n\tWrong: " + ui -> wrong -> text() + "\r\n\tRight: " + ui -> true_1 -> text() + "\r\n";
    std::string str = sen.toStdString();
    const char* p = str.c_str();
    /*QString wr = ui -> wrong -> text();
    std::string str = sen.toStdString();
    const char* p = str.c_str();
    QString tr = ui -> true_1 -> text();*/
    if (ui -> number -> text() == "1")
    {
        file.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Tests\\firstlection.txt");
    }
    else if (ui -> number -> text() == "2")
    {
        file.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Tests\\secondlection.txt");
    }
    else if (ui -> number -> text() == "3")
    {
        file.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Tests\\thirdlection.txt");
    }
    else if (ui -> number -> text() == "4")
    {
        file.setFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Tests\\fourthlection.txt");
    }
    if (file.open(QIODevice::Append))
    {
        file.write(p);
        file.write("\r\n");
        file.close();
    }
    ui -> number -> clear();
    ui -> sentence -> clear();
    ui -> wrong -> clear();
    ui -> true_1 -> clear();

}
