#ifndef MISTAKEPLACE_H
#define MISTAKEPLACE_H

#include <QDialog>
#include <QFile>
#include <QString>

namespace Ui {
class MistakePlace;
}

class MistakePlace : public QDialog
{
    Q_OBJECT

signals:
    void mistakeWindow();

public:
    explicit MistakePlace(QWidget *parent = nullptr);
    ~MistakePlace();

private slots:
    void on_back_clicked();

    void on_add_clicked();

private:
    Ui::MistakePlace *ui;
};

#endif // MISTAKEPLACE_H
