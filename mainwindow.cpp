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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Start_clicked()
{
    if (ui -> surname -> text() != "Vania" && ui -> surname -> text() != "Lera")
    {
        QMessageBox::information(this, "False", "You can't open this lessons!");
    }
    else
    {
        lection -> show();
        this -> close();
    }
}
