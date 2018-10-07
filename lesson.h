#ifndef LESSON_H
#define LESSON_H

#include <QDialog>
#include <QWidget>
#include <workbook.h>

namespace Ui {
class Lesson;
}

class Lesson : public QDialog
{
    Q_OBJECT

public:
    explicit Lesson(QWidget *parent = nullptr);
    ~Lesson();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

    void on_les_1_clicked();

private:
    Ui::Lesson *ui;
    Workbook * wb1;
};

#endif // LESSON_H
