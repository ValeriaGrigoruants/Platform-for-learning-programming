#ifndef PERSONALRESULTS_H
#define PERSONALRESULTS_H

#include <QDialog>
#include <QFile>
//#include <lesson.h>

namespace Ui {
class PersonalResults;
}

class PersonalResults : public QDialog
{
    Q_OBJECT

public:
    explicit PersonalResults(QWidget *parent = nullptr);
    void setUser(QString);
    QString getUser();
    void makeTable();
    ~PersonalResults();

signals:
    void personal();

private slots:
    void on_back_clicked();

private:
    Ui::PersonalResults *ui;
    QString user;
};

#endif // PERSONALRESULTS_H
