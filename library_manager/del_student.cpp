#include "del_student.h"
#include "ui_del_student.h"
#include "studentmanage.h"
#include "mainwindow.h"
del_student::del_student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::del_student)
{
    ui->setupUi(this);
}

del_student::~del_student()
{
    delete ui;
}

void del_student::on_del_botton_clicked()
{
    QSqlDatabase db;
    db=QSqlDatabase::addDatabase("QMYSQL");
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
    QString id=ui->del_student_input->text();
    QSqlQuery query(db);
    QString del=QString("DELETE from student where id =%1").arg(id);
    if(query.exec(del))
    {
        qDebug()<<"删除成功";
    }
    else
    {
        qDebug()<<"删除失败";
    }
}

void del_student::on_back_clicked()
{
    this->close();
    studentmanage *st=new studentmanage;
    st->setWindowTitle("学生管理界面");
    st->setWindowIcon(QIcon(":/logo.ico"));
    st->show();
}
