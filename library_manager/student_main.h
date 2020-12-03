#ifndef STUDENT_MAIN_H
#define STUDENT_MAIN_H

#include <QWidget>
#include<select_book_s.h>
#include<select_borrow.h>
#include<borrow_book.h>
#include<back_book.h>
namespace Ui {
class student_main;
}

class student_main : public QWidget
{
    Q_OBJECT

public:
    explicit student_main(QWidget *parent = 0);
    ~student_main();

private slots:
    void on_select_book_s_clicked();

    void on_borrow_book_clicked();

    void on_select_borrow_clicked();

    void on_return_book_clicked();

private:
    Ui::student_main *ui;
};

#endif // STUDENT_MAIN_H
