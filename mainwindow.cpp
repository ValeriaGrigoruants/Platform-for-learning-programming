#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lection = new Lesson();
    connect(lection, &Lesson::firstWindow, this, &MainWindow::show);
    admin = new Admin();
    connect (admin, &Admin::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Start_clicked()
{
    QFile file("C:\\Users\\Valeria\\Documents\\LearnProgramming\\students.txt");
    bool all_right = false;
    QString sur = ui -> surname -> text() + " " + ui -> password -> text();
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        QString str="";
        while(!file.atEnd())
        {
            str = file.readLine();
            QString firstWord = str.split(" ").at(0);
            QString sec = str.split("\r").at(0);
            //qDebug() << "there";
            //qDebug() << sec << endl;
            if (sec == sur)
            {
                all_right = true;
                break;
            }
        }
        file.close();
    }
    if (ui -> surname -> text() == "admin")
    {
        admin -> show();
        this -> close();
    }
    else if (!all_right)
    {
        QMessageBox::information(this, "False", "You can't open this lessons!");
    }
    else
    {
        lection -> show();
        this -> close();
    }
}
