#ifndef BACK_BOOK_H
#define BACK_BOOK_H

#include <QWidget>
#include<student_main.h>
#include<globe.h>
namespace Ui {
class back_book;
}

class back_book : public QWidget
{
    Q_OBJECT

public:
    explicit back_book(QWidget *parent = 0);
    ~back_book();

private slots:
    void on_back_book_botton_clicked();

    void on_back_botton_clicked();

private:
    Ui::back_book *ui;
};

#endif // BACK_BOOK_H
