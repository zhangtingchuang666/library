#include "select_book_s.h"
#include "ui_select_book_s.h"

select_book_s::select_book_s(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::select_book_s)
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
    ui->book->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可修改
    book_all.clear();
}

select_book_s::~select_book_s()
{
    delete ui;
}

void select_book_s::on_back_clicked()
{
    this->close();
    student_main *s=new student_main;
    s->setWindowTitle("学生界面");
    s->setWindowIcon(QIcon(":/logo.ico"));
    s->show();
}
