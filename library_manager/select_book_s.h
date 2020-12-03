#ifndef SELECT_BOOK_S_H
#define SELECT_BOOK_S_H

#include <QWidget>
#include<mainwindow.h>
#include<globe.h>
namespace Ui {
class select_book_s;
}

class select_book_s : public QWidget
{
    Q_OBJECT

public:
    explicit select_book_s(QWidget *parent = 0);
    ~select_book_s();

private slots:
    void on_back_clicked();

private:
    Ui::select_book_s *ui;
};

#endif // SELECT_BOOK_S_H
