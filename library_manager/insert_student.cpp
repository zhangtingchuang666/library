#include "insert_student.h"
#include "ui_insert_student.h"
#include "studentmanage.h"
#include<mainwindow.h>
insert_student::insert_student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::insert_student)
{
    ui->setupUi(this);
}

insert_student::~insert_student()
{
    delete ui;
}

void insert_student::on_insert_botton_clicked()
{
    QString id=ui->insert_id_input->text();
    QString password=ui->insert_password_input->text();
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
    QSqlQuery query(db);
    QString insert=QString("INSERT INTO student VALUES (\'%1\',\'%2\')").arg(id).arg(password);
    qDebug()<<insert;
    if(query.exec(insert))
    {
        qDebug()<<"插入成功";
    }
    else
    {
        qDebug()<<"插入失败";
    }
}

void insert_student::on_back_clicked()
{
    this->close();
    studentmanage *st=new studentmanage;
    st->setWindowTitle("学生管理界面");
    st->setWindowIcon(QIcon(":/logo.ico"));
    st->show();
}
