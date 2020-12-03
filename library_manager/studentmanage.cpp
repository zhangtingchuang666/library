#include "studentmanage.h"
#include "ui_studentmanage.h"
#include<admin_main.h>
studentmanage::studentmanage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::studentmanage)
{
    ui->setupUi(this);
}

studentmanage::~studentmanage()
{
    delete ui;
}

void studentmanage::on_return_student_clicked()
{
    admin_main *m1=new admin_main;
    this->close();
    m1->setWindowTitle("管理员界面");
    m1->setWindowIcon(QIcon(":/logo.ico"));
    m1->show();
}

void studentmanage::on_select_student_clicked()
{
    QSqlDatabase db;
    db=QSqlDatabase::addDatabase("QMYSQL"); // 数据库驱动
    db.setDatabaseName("library");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("123");
    if(db.open())
    {
        qDebug()<<"ok";
    }
    else
    {
        qDebug()<<"fail";
    }
    QSqlQuery query(db);
    query.exec("select id,password from student");
    QStringList student;
    while (query.next()) {
       student.clear();
      QString s_id=query.value(0).toString();
      QString s_password=query.value(1).toString();
      student<<s_id<<s_password;
      student_all.append(student);
    }
    select_student *ss=new select_student;
    this->hide();
    ss->setWindowTitle("学生查看界面");
    ss->setWindowIcon(QIcon(":/logo.ico"));
    ss->show();
}

void studentmanage::on_del_student_clicked()
{
    this->close();
    del_student *dl =new del_student;
    dl->setWindowTitle("学生删除界面");
    dl->setWindowIcon(QIcon(":/logo.ico"));
    dl->show();
}

void studentmanage::on_insert_student_clicked()
{
    this->close();
    insert_student *is =new insert_student;
    is->setWindowTitle("学生插入界面");
    is->setWindowIcon(QIcon(":/logo.ico"));
    is->show();
}

void studentmanage::on_update_student_clicked()
{
    update_student *us=new update_student;
    this->hide();
    us->setWindowTitle("学生修改界面");
    us->setWindowIcon(QIcon(":/logo.ico"));
    us->show();
}

void studentmanage::on_pushButton_clicked()
{
    QSqlDatabase db;
    db=QSqlDatabase::addDatabase("QMYSQL"); // 数据库驱动
    db.setDatabaseName("library");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("123");
    if(db.open())
    {
        qDebug()<<"ok";
    }
    else
    {
        qDebug()<<"fail";
    }
    QSqlQuery query(db);
    query.exec("call aaa");
}
