#include "admin_main.h"
#include "ui_admin_main.h"
namespace Ui {
class admin_main;
}
admin_main::admin_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin_main)
{
    ui->setupUi(this);
}

admin_main::~admin_main()
{
    delete ui;
}
void admin_main::on_student_manage_clicked()
{
    this->close();
    studentmanage *sm = new studentmanage;
    sm->setWindowTitle("学生管理界面");
    sm->setWindowIcon(QIcon(":/logo.ico"));
    sm->show();
}

void admin_main::on_book_manage_clicked()
{
    this->close();
    bookmanage *bm =new bookmanage;
    bm->setWindowTitle("图书管理界面");
    bm->setWindowIcon(QIcon(":/logo.ico"));
    bm->show();
}
