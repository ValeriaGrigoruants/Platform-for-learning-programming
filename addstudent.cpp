#include "addstudent.h"
#include "ui_addstudent.h"

AddStudent::AddStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudent)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:\\Users\\Valeria\\Documents\\LearnProgramming\\back.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
}

AddStudent::~AddStudent()
{
    delete ui;
}

void AddStudent::on_back_clicked()
{
    this -> close();
    emit add();
}

void AddStudent::on_add_clicked()
{
    QString temp = ui -> name -> text() + " " + ui -> surname -> text() + "\r\n";
    QFile student ("C:\\Users\\Valeria\\Documents\\LearnProgramming\\students.txt");
    if (student.open(QIODevice::Append))
    {
        std::string str = temp.toStdString();
        const char* p = str.c_str();
        student.write(p);
        student.close();
    }
    ui -> name -> clear();
    ui -> surname -> clear();
}
