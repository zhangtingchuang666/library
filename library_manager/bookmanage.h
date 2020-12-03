#ifndef BOOKMANAGE_H
#define BOOKMANAGE_H

#include <QWidget>
#include<admin_main.h>
namespace Ui {
class bookmanage;
}

class bookmanage : public QWidget
{
    Q_OBJECT

public:
    explicit bookmanage(QWidget *parent = 0);
    ~bookmanage();

private slots:
    void on_return_book_clicked();

    void on_select_book_clicked();

    void on_del_book_clicked();

    void on_update_book_clicked();

    void on_insert_book_clicked();

private:
    Ui::bookmanage *ui;
};

#endif // BOOKMANAGE_H
