#ifndef LESSON_H
#define LESSON_H

#include <QDialog>
#include <allresults.h>
#include <QWidget>
#include <workbook.h>
#include <test.h>
#include <personalresults.h>

namespace Ui {
class Lesson;
}

class Lesson : public QDialog
{
    Q_OBJECT

public:
    explicit Lesson(QWidget *parent = nullptr);
    void setUser (QString);
    QString getUser ();
    ~Lesson();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

    void on_les_1_clicked();

    void on_les_2_clicked();

    void on_les_3_clicked();

    void on_les_4_clicked();

    void on_results_clicked();

private:
    Ui::Lesson *ui;

    Workbook * wb1;

    Test * test;

    PersonalResults *result;

    QString student;
};

#endif // LESSON_H
