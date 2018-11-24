#ifndef TOTAL_H
#define TOTAL_H

#include <QDialog>
#include <QFile>
#include <QDebug>
#include <QTextDocument>
#include <QPdfWriter>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextStream>
#include <QTextDocument>
#include <QDesktopServices>

namespace Ui {
class Total;
}

class Total : public QDialog
{
    Q_OBJECT

public:
    explicit Total(QWidget *parent = nullptr);
    void makeTable();
    void setUser(QString);
    QString getUser();
    ~Total();

private slots:
    void on_dowload_clicked();

private:
    Ui::Total *ui;
    QString user;
    double all = 0;
};

#endif // TOTAL_H
