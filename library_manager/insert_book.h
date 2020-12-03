#ifndef INSERT_BOOK_H
#define INSERT_BOOK_H

#include <QWidget>

namespace Ui {
class insert_book;
}

class insert_book : public QWidget
{
    Q_OBJECT

public:
    explicit insert_book(QWidget *parent = 0);
    ~insert_book();

private slots:
    void on_pushButton_clicked();

    void on_insert_book_botton_clicked();

private:
    Ui::insert_book *ui;
};

#endif // INSERT_BOOK_H
