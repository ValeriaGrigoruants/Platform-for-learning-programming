#ifndef ALLRESULTS_H
#define ALLRESULTS_H

#include <QDialog>
#include <QMap>
#include <QFile>
#include <iostream>
#include <QDebug>

namespace Ui {
class AllResults;
}

class AllResults : public QDialog
{
    Q_OBJECT

public:
    explicit AllResults(QWidget *parent = nullptr);
    void setUser (QString);
    QString getUser();
    ~AllResults();

signals:
    void admin();
    void personal();

private slots:
    void on_back_clicked();


private:
    Ui::AllResults *ui;
    QString user;

};

#endif // ALLRESULTS_H
