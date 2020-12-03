#ifndef SELECT_STUDENT_H
#define SELECT_STUDENT_H

#include <QWidget>

namespace Ui {
class select_student;
}

class select_student : public QWidget
{
    Q_OBJECT

public:
    explicit select_student(QWidget *parent = 0);
    ~select_student();

private slots:
    void on_back_clicked();

private:
    Ui::select_student *ui;
};

#endif // SELECT_STUDENT_H
