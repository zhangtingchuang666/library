#ifndef DEL_BOOK_H
#define DEL_BOOK_H

#include <QWidget>
namespace Ui {
class del_book;
}

class del_book : public QWidget
{
    Q_OBJECT

public:
    explicit del_book(QWidget *parent = 0);
    ~del_book();

private slots:
    void on_pushButton_clicked();

    void on_del_book_botton_clicked();

private:
    Ui::del_book *ui;
};

#endif // DEL_BOOK_H
