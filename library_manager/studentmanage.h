#ifndef STUDENTMANAGE_H
#define STUDENTMANAGE_H
#include <QWidget>
#include<globe.h>
#include<select_student.h>
#include<del_student.h>
#include<update_student.h>
#include<insert_student.h>
#include<mainwindow.h>
namespace Ui {
class studentmanage;
}

class studentmanage : public QWidget
{
    Q_OBJECT

public:
    explicit studentmanage(QWidget *parent = 0);
    ~studentmanage();

private slots:
    void on_return_student_clicked();

    void on_select_student_clicked();

    void on_del_student_clicked();

    void on_insert_student_clicked();

    void on_update_student_clicked();

    void on_pushButton_clicked();

private:
    Ui::studentmanage *ui;
};

#endif // STUDENTMANAGE_H
