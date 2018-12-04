#include "lesson.h"
#include "ui_lesson.h"

Lesson::Lesson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lesson)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:\\Users\\Valeria\\Documents\\LearnProgramming\\back.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    wb1 = new Workbook();
    connect(wb1, &Workbook::lessons, this, &Lesson::show);
    test = new Test();
    connect(test, &Test::back_to_lec, this, &Lesson::show);
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
    wb1 -> setUser(getUser());
    this -> close();
}

void Lesson::on_les_2_clicked()
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
    if (temp >= 1)
    {
        wb1 -> show();
        wb1 -> readFile(2);
        wb1 -> setUser(getUser());
        this -> close();
    }
    else
    {
        QMessageBox::information(this, "System", "You can't open this lecture. Please review the previous ones!");
    }
}

void Lesson::on_les_3_clicked()
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
    if (temp >= 2)
    {
        wb1 -> show();
        wb1 -> readFile(3);
        wb1 -> setUser(getUser());
        this -> close();
    }
    else
    {
        QMessageBox::information(this, "System", "You can't open this lecture. Please review the previous ones!");
    }
}

void Lesson::on_les_4_clicked()
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
    if (temp >= 3)
    {
        wb1 -> show();
        wb1 -> readFile(4);
        wb1 -> setUser(getUser());
        this -> close();
    }
    else
    {
        QMessageBox::information(this, "System", "You can't open this lecture. Please review the previous ones!");
    }
}

void Lesson::setUser (QString st)
{
    student = st;
}

QString Lesson::getUser()
{
    return student;
}

void Lesson::on_results_clicked()
{
    result = new PersonalResults();
    connect (result, &PersonalResults::personal, this, &Lesson::show);
    result ->setUser(getUser());
    result ->makeTable();
    this ->close();
    result ->show();
}
