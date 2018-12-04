#include "personalresults.h"
#include "ui_personalresults.h"

PersonalResults::PersonalResults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonalResults)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:\\Users\\Valeria\\Documents\\LearnProgramming\\back.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

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
    ui ->tableRes ->setColumnWidth(0, 433);
    ui ->tableRes ->setColumnWidth(1, 432);
    ui ->tableRes ->setRowHeight(0, 134);
    ui ->tableRes ->setRowHeight(1, 135);
    ui ->tableRes ->setRowHeight(2, 134);
    ui ->tableRes ->setRowHeight(3, 135);
    ui ->tableRes ->setHorizontalHeaderLabels(QStringList() << "The lecture" << "Your mark");



    for (int i = 1; i < 5; ++i)
    {
        QTableWidgetItem * item = new QTableWidgetItem ("Lecture " + tr("%1").arg(i));
        item ->setTextAlignment(Qt::AlignCenter);
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
            item ->setTextAlignment(Qt::AlignCenter);
            ui ->tableRes ->setItem(count, 1, item);
            count ++;
        }
        while (count < 5)
        {
            QTableWidgetItem * item = new QTableWidgetItem (tr("%1").arg(0));
            item ->setTextAlignment(Qt::AlignCenter);
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
