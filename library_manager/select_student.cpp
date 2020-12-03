#include "select_student.h"
#include "ui_select_student.h"
#include<admin_main.h>
select_student::select_student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::select_student)
{
    ui->setupUi(this);
    int col=ui->student->columnCount();
    for(int i=0;i<student_all.size();i++)
    {
        QStringList data=student_all[i].toStringList();
        int row = ui->student->rowCount();
        ui->student->insertRow(row);
        for(int j=0;j<col;j++)
        {
           QTableWidgetItem *item = new QTableWidgetItem();
           item->setText(data.at(j));
           ui->student->setItem(row,j,item);
        }
    }
    ui->student->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可修改
    student_all.clear();
}

select_student::~select_student()
{
    delete ui;
}

void select_student::on_back_clicked()
{
    this->hide();
    studentmanage *m=new studentmanage;
    m->setWindowTitle("学生管理界面");
    m->setWindowIcon(QIcon(":/logo.ico"));
    m->show();
}
