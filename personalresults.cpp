#include "personalresults.h"
#include "ui_personalresults.h"

PersonalResults::PersonalResults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonalResults)
{
    ui->setupUi(this);

}

PersonalResults::~PersonalResults()
{
    delete ui;
}

void PersonalResults::setUser(QString use)
{
    user = use;
}

QString PersonalResults::getUser()
{
    return user;
}

void PersonalResults::makeTable()
{

    ui ->tableRes ->setRowCount(4);
    ui ->tableRes ->setColumnCount(2);

    for (int i = 1; i < 5; ++i)
    {
        QTableWidgetItem * item = new QTableWidgetItem ("Lecture " + tr("%1").arg(i));
        ui ->tableRes ->setItem(i - 1, 0, item);
    }


    QFile file("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Results\\" + getUser() + ".txt");

    if (file.open(QIODevice::ReadOnly))
    {
        int count = 0;
        while (!file.atEnd())
        {
            QString line =  file.readLine();
            line = line.split("\r").at(0);
            int t = 1;
            line.toInt();
            double mark = 0;
            for (int i = line.size() - 1; i >= 0 && line[i] != " "; --i)
            {
                mark += line[i].digitValue() * t;
                t *= 10;
            }
            QTableWidgetItem * item = new QTableWidgetItem (tr("%1").arg(mark));
            ui ->tableRes ->setItem(count, 1, item);
            count ++;
        }
        while (count < 5)
        {
            QTableWidgetItem * item = new QTableWidgetItem (tr("%1").arg(0));
            ui ->tableRes ->setItem(count, 1, item);
            count++;
        }
    }
}

void PersonalResults::on_back_clicked()
{
    this ->close();
    emit personal();
}
