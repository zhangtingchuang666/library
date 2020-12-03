#ifndef UPDATE_BOOK_H
#define UPDATE_BOOK_H
#include<mainwindow.h>
#include <QWidget>
#include<student_main.h>
namespace Ui {
class update_book;
}

class update_book : public QWidget
{
    Q_OBJECT

public:
    explicit update_book(QWidget *parent = 0);
    ~update_book();

private slots:
    void on_update_botton_clicked();

    void on_back_botton_clicked();

private:
    Ui::update_book *ui;
};

#endif // UPDATE_BOOK_H
