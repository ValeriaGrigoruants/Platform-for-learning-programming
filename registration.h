#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QtDebug>
#include <QMessageBox>
#include <QCryptographicHash>

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

signals:
    void autorization();

private slots:
    void on_back_clicked();

    void on_registr_clicked();

private:
    Ui::Registration *ui;
};

#endif // REGISTRATION_H
