#ifndef UPDATE_STUDENT_H
#define UPDATE_STUDENT_H

#include <QWidget>

namespace Ui {
class update_student;
}

class update_student : public QWidget
{
    Q_OBJECT

public:
    explicit update_student(QWidget *parent = 0);
    ~update_student();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::update_student *ui;
};

#endif // UPDATE_STUDENT_H
