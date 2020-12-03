#include "select_book.h"
#include "ui_select_book.h"
#include "bookmanage.h"
#include  "globle.h"
select_book::select_book(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::select_book)
{
    ui->setupUi(this);
    int col=ui->book->columnCount();
    for(int i=0;i<book_all.size();i++)
    {
        QStringList data=book_all[i].toStringList();
        int row = ui->book->rowCount();
        ui->book->insertRow(row);
        for(int j=0;j<col;j++)
        {
           QTableWidgetItem *item = new QTableWidgetItem();
           item->setText(data.at(j));
           ui->book->setItem(row,j,item);
        }
    }
    book_all.clear();
    ui->book->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可修改
}
select_book::~select_book()
{
    delete ui;
}

void select_book::on_back_clicked()
{
    this->close();
    bookmanage *bm=new bookmanage;
    bm->setWindowTitle("图书管理界面");
    bm->setWindowIcon(QIcon(":/logo.ico"));
    bm->show();
}
