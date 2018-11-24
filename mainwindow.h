#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <lesson.h>
#include <admin.h>
#include <registration.h>
#include <total.h>
#include <QCryptographicHash>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_Start_clicked();


    void on_registration_clicked();

private:
    Ui::MainWindow *ui;

    Lesson *lection;

    Admin *admin;

    Registration *new_user;

    Total *total;

    QString user;
};

#endif // MAINWINDOW_H
