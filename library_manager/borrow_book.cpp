#include "borrow_book.h"
#include "ui_borrow_book.h"
#include"mainwindow.h"
borrow_book::borrow_book(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::borrow_book)
{
    ui->setupUi(this);
}

borrow_book::~borrow_book()
{
    delete ui;
}

void borrow_book::on_borrow_botton_clicked()
{
    QString b_id=ui->borrow_input->text();
    qDebug()<<b_id;
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
    QSqlQuery query1(db);
    QSqlQuery query2(db);
    db.exec("SET NAMES 'GBK'");
    QString a=QString("CREATE TABLE %1_b (bo_id int,bo_name varchar(20))").arg(id);
    qDebug()<<a;
    if(query.exec(a)){
        qDebug()<<"ok";
    }
     else{
        qDebug()<<"fail";
    }
    QString b_name;
    QString sel=QString("select name from book where ISBN=\'%1\'").arg(b_id);
    query1.exec(sel);
    while (query1.next()) {
    b_name=query1.value(0).toString();
    qDebug()<<b_name;
    }
    QString insert=QString("INSERT INTO %1_b VALUES (\'%2\',\'%3\')").arg(id).arg(b_id).arg(b_name);
    qDebug()<<insert;
    QString XIUGAI=QString("UPDATE book SET shuliang=shuliang-1 where ISBN=\'%1\'").arg(b_id);
    if(query1.exec(insert))
    {
        qDebug()<<"ok";
        query2.exec(XIUGAI);

    }
    else
    {
        qDebug()<<"fail";
    }
}

void borrow_book::on_back_clicked()
{
    this->close();
    student_main *sm=new student_main;
    sm->setWindowTitle("学生界面");
    sm->setWindowIcon(QIcon(":/logo.ico"));
    sm->show();
}
