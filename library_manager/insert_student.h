#ifndef INSERT_STUDENT_H
#define INSERT_STUDENT_H

#include <QWidget>

namespace Ui {
class insert_student;
}

class insert_student : public QWidget
{
    Q_OBJECT

public:
    explicit insert_student(QWidget *parent = 0);
    ~insert_student();

private slots:
    void on_insert_botton_clicked();

    void on_back_clicked();

private:
    Ui::insert_student *ui;
};

#endif // INSERT_STUDENT_H
