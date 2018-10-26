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
    teach = new Teacher();
    connect(teach, &Teacher::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Start_clicked()
{
    if (ui -> surname -> text() != "Vania" && ui -> surname -> text() != "Lera" && ui -> surname -> text() != "admin")
    {
        QMessageBox::information(this, "False", "You can't open this lessons!");
    }
    else if (ui -> surname -> text() == "admin")
    {
        lection -> show();
        this -> close();
    }
    else
    {
        lection -> show();
        this -> close();
    }
}
