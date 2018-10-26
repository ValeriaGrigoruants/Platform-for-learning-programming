#ifndef TEACHER_H
#define TEACHER_H

#include <QDialog>
#include <QSqlTableModel>
#include "database.h"
#include "dialogadddevice.h"


namespace Ui {
class Teacher;
}

class Teacher : public QDialog
{
    Q_OBJECT

public:
    explicit Teacher(QWidget *parent = nullptr);
    ~Teacher();
signals:
    void firstWindow();

private:
    Ui::Teacher *ui;
    DataBase *db;
    QSqlTableModel *modelDevice;

private:
    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();
};

#endif // TEACHER_H
