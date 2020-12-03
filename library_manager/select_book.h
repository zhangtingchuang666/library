#ifndef SELECT_BOOK_H
#define SELECT_BOOK_H
#include <QWidget>
#include<mainwindow.h>
namespace Ui {
class select_book;
}

class select_book : public QWidget
{
    Q_OBJECT

public:
    explicit select_book(QWidget *parent = 0);
    ~select_book();
private slots:
    void on_back_clicked();

private:
    Ui::select_book *ui;
};

#endif // SELECT_BOOK_H
