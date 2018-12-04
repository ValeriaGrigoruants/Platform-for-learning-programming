#include "total.h"
#include "ui_total.h"

Total::Total(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Total)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:\\Users\\Valeria\\Documents\\LearnProgramming\\back.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
}

Total::~Total()
{
    delete ui;
}

void Total::setUser(QString use)
{
    user = use;
}

QString Total::getUser()
{
    return user;
}

void Total::makeTable()
{

    ui ->tableRes ->setRowCount(4);
    ui ->tableRes ->setColumnCount(2);
    ui ->tableRes ->setColumnWidth(0, 433);
    ui ->tableRes ->setColumnWidth(1, 432);
    ui ->tableRes ->setRowHeight(0, 120);
    ui ->tableRes ->setRowHeight(1, 120);
    ui ->tableRes ->setRowHeight(2, 118);
    ui ->tableRes ->setRowHeight(3, 119);
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
        all = 0;
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
            all += mark;
            QTableWidgetItem * item = new QTableWidgetItem (tr("%1").arg(mark));
            item ->setTextAlignment(Qt::AlignCenter);
            ui ->tableRes ->setItem(count, 1, item);
            count ++;
        }
        all /= 4;
        ui ->res ->setText("<font color = \"#ffffff\"><h1 align = \"center\">Your total mark is: " + tr("%1").arg(all) + "</h3></font>");
    }
}



void Total::on_dowload_clicked()
{
    QFile file("C:\\Users\\Valeria\\Documents\\LearnProgramming\\pech.txt");
    QString image;
    if (file.open(QIODevice::ReadOnly))
    {
        image = file.readAll();
        file.close();
    }
    QString html = "<h1 style=\"text-align: center;\"><span style=\"font-family: \'times new roman\', times;\">CERTIFICATE</span></h1>"
            "<p style=\"text-align: left;\">&nbsp;</p>"
            "<p style=\"text-align: left;\">This is to certify that</p>"
            "<p style=\"text-align: left;\"><strong><span style=\"font-size: 14pt;\">" + getUser() + "</span></strong></p>"
            "<p style=\"text-align: left;\">has successfully complited</p>"
            "<p style=\"text-align: left;\"><strong><span style=\"font-size: 14pt;\">C++ cours about arrays</span></strong></p>"
            "<p style=\"text-align: left;\"><span style=\"font-size: 11pt;\">whith the total mark</span></p>"
            "<p style=\"text-align: left;\"><strong><span style=\"font-size: 14pt;\">" + QString::number(all) + "</span></strong></p>"  + image;
    QTextDocument document;
    document.setHtml(html);
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));
    printer.setPaperSize(QPrinter::A6);
    printer.setOutputFileName("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Certificats\\" + getUser() + ".pdf");
    document.print(&printer);

    QDesktopServices::openUrl(QUrl::fromLocalFile("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Certificats\\" + getUser() + ".pdf"));
}
