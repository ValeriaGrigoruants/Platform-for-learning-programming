#include "deletetest.h"
#include "ui_deletetest.h"

DeleteTest::DeleteTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteTest)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:\\Users\\Valeria\\Documents\\LearnProgramming\\back.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
}

DeleteTest::~DeleteTest()
{
    delete ui;
}

void DeleteTest::on_comboBox_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Lecture 1")
    {
       cur_test = "C:\\Users\\Valeria\\Documents\\LearnProgramming\\Tests\\firstlection.txt";
    }
    else if (arg1 == "Lecture 2")
    {
        cur_test = "C:\\Users\\Valeria\\Documents\\LearnProgramming\\Tests\\secondlection.txt";
    }
    else if (arg1 == "Lecture 3")
    {
        cur_test = "C:\\Users\\Valeria\\Documents\\LearnProgramming\\Tests\\thirdlection.txt";
    }
    else if (arg1 == "Lecture 4")
    {
        cur_test = "C:\\Users\\Valeria\\Documents\\LearnProgramming\\Tests\\fourthlection.txt";
    }
    current = 0;
    showTest();
}

void DeleteTest::showTest()
{
    QFile file(cur_test);
    int t = 0;
    QString que;
    QString wr;
    QString rie;
    if (file.open(QIODevice::ReadOnly))
    {
        while (!file.atEnd() && t <= current)
        {
            que = file.readLine();
            wr = file.readLine();
            wr = wr.split("\r").at(0);
            wr = wr.section(' ', 1);
            rie = file.readLine();
            rie = rie.split("\r").at(0);
            rie = rie.section(' ', 1);
            file.readLine();
            t += 4;
        }
        if (t - 4 != current) current -= 4;
        ui ->question ->setText(que);
        ui ->wrong ->setText(wr);
        ui ->right ->setText(rie);
        file.close();
    }
}


void DeleteTest::on_back_clicked()
{
    this ->close();
    emit admin();
}

void DeleteTest::on_previous_clicked()
{
    current -= 4;
    if (current < 0) current = 0;
    showTest();
}

void DeleteTest::on_next_clicked()
{
    current += 4;
    showTest();
}

void DeleteTest::on_delete_2_clicked()
{
    QFile f(cur_test);
    if(f.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QString s;
        QTextStream t(&f);
        int temp = 0;
        while(!t.atEnd())
        {
            QString line = t.readLine();
            if(!(temp >= current && temp <= current + 3))
            {
                s.append(line + "\n");
            }
            temp++;
        }
        f.resize(0);
        t << s;
    }
    current -= 4;
    if (current < 0) current = 0;
    showTest();
}
