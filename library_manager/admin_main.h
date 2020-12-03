#ifndef ADMIN_MAIN_H
#define ADMIN_MAIN_H

#include <QWidget>
#include<bookmanage.h>
#include<studentmanage.h>
namespace Ui {
class admin_main;
}

class admin_main : public QWidget
{
    Q_OBJECT

public:
    explicit admin_main(QWidget *parent = 0);
    ~admin_main();

private slots:

    void on_student_manage_clicked();

    void on_book_manage_clicked();

private:
    Ui::admin_main *ui;
};

#endif // ADMIN_MAIN_H
