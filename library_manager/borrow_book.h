#ifndef BORROW_BOOK_H
#define BORROW_BOOK_H

#include <QWidget>
#include<globe.h>
namespace Ui {
class borrow_book;
}

class borrow_book : public QWidget
{
    Q_OBJECT

public:
    explicit borrow_book(QWidget *parent = 0);
    ~borrow_book();

private slots:
    void on_borrow_botton_clicked();

    void on_back_clicked();

private:
    Ui::borrow_book *ui;
};

#endif // BORROW_BOOK_H
