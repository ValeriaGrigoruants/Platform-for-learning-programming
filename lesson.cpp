#include "lesson.h"
#include "ui_lesson.h"

Lesson::Lesson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lesson)
{
    ui->setupUi(this);
    wb1 = new Workbook();
    connect(wb1, &Workbook::lessons, this, &Lesson::show);
}

Lesson::~Lesson()
{
    delete ui;
}

void Lesson::on_pushButton_clicked()
{
    this -> close();
    emit firstWindow();
}

void Lesson::on_les_1_clicked()
{
    wb1 -> show();
    wb1 -> readFile(1);
    this -> close();
}

void Lesson::on_les_2_clicked()
{
    wb1 -> show();
    wb1 -> readFile(2);
    this -> close();
}

void Lesson::on_les_3_clicked()
{
    wb1 -> show();
    wb1 -> readFile(3);
    this -> close();
}

void Lesson::on_les_4_clicked()
{
    wb1 -> show();
    wb1 -> readFile(4);
    this -> close();
}
