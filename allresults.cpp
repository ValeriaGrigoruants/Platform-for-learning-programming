#include "allresults.h"
#include "ui_allresults.h"

AllResults::AllResults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AllResults)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:\\Users\\Valeria\\Documents\\LearnProgramming\\back.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    QMap <QString, double> res;
        QFile file ("C:\\Users\\Valeria\\Documents\\LearnProgramming\\users.txt");
        if (file.open(QIODevice::ReadOnly))
        {
            while (!file.atEnd())
            {
                QString name = file.readLine();
                name = name.split(": ").at(0);
                QFile pers("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Results\\" + name + ".txt");
                double mark = 0;
                if (pers.open(QIODevice::ReadOnly))
                {
                    mark = 0;
                    while (!pers.atEnd())
                    {
                        QString line = pers.readLine();
                        line = line.split("\r").at(0);
                        int t = 1;
                        int t2 = 0;
                        line.toInt();
                        for (int i = line.size() - 1; i >= 0 && line[i] != " "; --i)
                        {
                            t2 += line[i].digitValue() * t;
                            t *= 10;
                        }
                        mark += t2;
                    }
                    mark /= 4;
                    pers.close();
                }
                res[name] = mark;
            }
            file.close();
            QFile file ("C:\\Users\\Valeria\\Documents\\LearnProgramming\\students.txt");
            if (file.open(QIODevice::ReadOnly))
            {
                while (!file.atEnd())
                {
                    QString line = file.readLine();
                    line = line.split("\r").at(0);
                    if (line.size() > 1)
                    {
                        res[line] = 0;
                    }
                }
            }
        }
        ui ->tableRes ->setRowCount(res.size());
        ui ->tableRes ->setColumnCount(2);
        ui ->tableRes ->setColumnWidth(0, 428);
        ui ->tableRes ->setColumnWidth(1, 427);
        for (int i = 0; i < res.size(); ++i)
        {
            ui ->tableRes ->setRowHeight(i, 565 / res.size());
        }
        ui ->tableRes ->setHorizontalHeaderLabels(QStringList() << "The Student" << "Total mark");
        int count = 0;
        for (auto x : res.toStdMap())
        {
            QTableWidgetItem * item = new QTableWidgetItem (x.first);
            ui ->tableRes ->setItem(count, 0, item);
            QTableWidgetItem * item2 = new QTableWidgetItem (tr("%1").arg(x.second));
            ui ->tableRes ->setItem(count, 1, item2);
            count ++;
        }

}

AllResults::~AllResults()
{
    delete ui;
}

QString AllResults::getUser()
{
    return user;
}

void AllResults::on_back_clicked()
{
    this ->close();
    emit admin();
}

void AllResults::setUser(QString use)
{
    user = use;
}
