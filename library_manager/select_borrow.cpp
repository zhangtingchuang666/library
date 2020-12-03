#include "select_borrow.h"
#include "ui_select_borrow.h"
#include<student_main.h>
select_borrow::select_borrow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::select_borrow)
{
    ui->setupUi(this);
    int col=ui->borrow->columnCount();
    for(int i=0;i<borrow_all.size();i++)
    {
        QStringList data=borrow_all[i].toStringList();
        int row = ui->borrow->rowCount();
        ui->borrow->insertRow(row);
        for(int j=0;j<col;j++)
        {
           QTableWidgetItem *item = new QTableWidgetItem();
           item->setText(data.at(j));
           ui->borrow->setItem(row,j,item);
        }
    }
    ui->borrow->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可修改
    borrow_all.clear();
}

select_borrow::~select_borrow()
{
    delete ui;
}

void select_borrow::on_back_clicked()
{
    this->close();
    student_main *sm=new student_main;
    sm->setWindowTitle("学生界面");
    sm->setWindowIcon(QIcon(":/logo.ico"));
    sm->show();
}
