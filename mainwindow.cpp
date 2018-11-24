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
    new_user = new Registration();
    connect(new_user, &Registration::autorization, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Start_clicked()
{
    QFile file("C:\\Users\\Valeria\\Documents\\LearnProgramming\\users.txt");
    bool all_right = false;
    QString sur = ui -> surname -> text() + " " + ui -> password -> text();
    QString firstWord;
    QCryptographicHash hasher(QCryptographicHash::Keccak_256);
    hasher.addData(sur.toUtf8());
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        QString s;
        QTextStream t(&file);
        while(!t.atEnd())
        {
            QString line = t.readLine();
            if(line.contains(hasher.result().toBase64()))
            {
                all_right = true;
                firstWord = line.split(": ").at(0);
                break;
            }
        }

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
        int count = 0;
        QFile file ("C:\\Users\\Valeria\\Documents\\LearnProgramming\\Results\\" + firstWord + ".txt");
        if (file.open(QIODevice::ReadOnly))
        {
            while (!file.atEnd())
            {
                if (file.readLine().size() > 3)
                    count ++;
            }
        }
        if (count < 4)
        {
            lection -> setUser(firstWord);
            lection -> show();

        }
        else
        {
            total = new Total();
            total ->setUser(firstWord);
            total ->makeTable();
            total ->show();
            this ->close();
        }
        this -> close();
    }
    ui -> surname -> clear();
    ui -> password -> clear();
}

void MainWindow::on_registration_clicked()
{
    this -> close();
    new_user -> show();
}
