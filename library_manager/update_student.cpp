#include "update_student.h"
#include "ui_update_student.h"
#include<mainwindow.h>
update_student::update_student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::update_student)
{
    ui->setupUi(this);
}

update_student::~update_student()
{
    delete ui;
}

void update_student::on_pushButton_clicked()
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
    QString a1=ui->update1->text();
    QString a2=ui->update2->currentText();
    QString a3=ui->update3->text();
    QString up=QString("UPDATE student SET %1=\'%2\' where id=\'%3\'").arg(a2).arg(a3).arg(a1);
    qDebug()<<up;
    if(query.exec(up)){
        qDebug()<<"OK";
    }
    else
    {
        qDebug()<<"fail";
    }
}

void update_student::on_pushButton_2_clicked()
{
    studentmanage *s1=new studentmanage;
    this->close();
    s1->setWindowTitle("图书管理界面");
    s1->setWindowIcon(QIcon(":/logo.ico"));
    s1->show();
}
