#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <lesson.h>
#include <teacher.h>

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

private:
    Ui::MainWindow *ui;
    Lesson *lection;
    Teacher *teach;
};

#endif // MAINWINDOW_H
