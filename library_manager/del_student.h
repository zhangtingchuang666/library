#ifndef DEL_STUDENT_H
#define DEL_STUDENT_H

#include <QWidget>
namespace Ui {
class del_student;
}

class del_student : public QWidget
{
    Q_OBJECT

public:
    explicit del_student(QWidget *parent = 0);
    ~del_student();

private slots:
    void on_del_botton_clicked();

    void on_back_clicked();

private:
    Ui::del_student *ui;
};

#endif // DEL_STUDENT_H
