#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_back_clicked()
{
    this -> close();
    emit autorization();
}

void Registration::on_registr_clicked()
{
    bool flag = false;
    QString rx = ui ->namein -> text() + " " + ui -> surnamein -> text();
    QFile f("C:\\Users\\Valeria\\Documents\\LearnProgramming\\students.txt");
    if(f.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QString s;
        QTextStream t(&f);
        while(!t.atEnd())
        {
            QString line = t.readLine();
            if(!line.contains(rx))
            {
                s.append(line + "\n");
                flag = true;
            }
        }
        f.resize(0);
        t << s;
        f.close();
        ui ->namein -> clear();
        ui -> surnamein -> clear();
    }
    if (!flag)
        QMessageBox::information(this, "False", "You can't registrate!");
    else if (ui -> passwin -> text() == ui -> passw2in -> text())
    {
        QString information = ui ->loginin -> text() + " " + ui -> passwin -> text();
        QCryptographicHash hasher(QCryptographicHash::Keccak_256);
        hasher.addData(information.toUtf8());
        QFile file ("C:\\Users\\Valeria\\Documents\\LearnProgramming\\users.txt");
        if (file.open(QIODevice::Append))
        {
            file.write(rx.toUtf8() + ": " + hasher.result().toBase64());
            file.write("\r\n");
            ui -> loginin -> clear();
            ui -> passwin -> clear();
            ui -> passw2in -> clear();
            QMessageBox::information(this, "System", "Registration completed successfully!");
            file.close();
            this -> close();
            emit autorization();
        }
    }
    else
    {
        QMessageBox::information(this, "System", "Passwords do not match");
    }
}
