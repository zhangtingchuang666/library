#ifndef SELECT_BORROW_H
#define SELECT_BORROW_H

#include <QWidget>
#include <globe.h>
namespace Ui {
class select_borrow;
}

class select_borrow : public QWidget
{
    Q_OBJECT

public:
    explicit select_borrow(QWidget *parent = 0);
    ~select_borrow();

private slots:
    void on_back_clicked();

private:
    Ui::select_borrow *ui;
};

#endif // SELECT_BORROW_H
