#ifndef WORKBOOK_H
#define WORKBOOK_H

#include <QDialog>
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QString>

namespace Ui {
class Workbook;
}

class Workbook : public QDialog
{
    Q_OBJECT


public:

    explicit Workbook(QWidget *parent = nullptr);
    void readFile(int);
    ~Workbook();

signals:
    void lessons();

private slots:
    void on_back_clicked();

private:
    Ui::Workbook *ui;
};

#endif // WORKBOOK_H
