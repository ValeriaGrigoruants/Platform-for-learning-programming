#ifndef FIXLECTURE_H
#define FIXLECTURE_H

#include <QDialog>
#include <QFile>
#include <QDebug>

namespace Ui {
class FixLecture;
}

class FixLecture : public QDialog
{
    Q_OBJECT

public:
    explicit FixLecture(QWidget *parent = nullptr);
    ~FixLecture();

private slots:
    void on_back_clicked();

    void on_fix_clicked();

    void on_choose_currentIndexChanged(const QString &arg1);

signals:
    void admin();

private:
    Ui::FixLecture *ui;
};

#endif // FIXLECTURE_H
