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
    this -> close();
}
