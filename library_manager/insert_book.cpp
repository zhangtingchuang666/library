#include "insert_book.h"
#include "ui_insert_book.h"
#include "bookmanage.h"
#include<mainwindow.h>
insert_book::insert_book(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::insert_book)
{
    ui->setupUi(this);
}

insert_book::~insert_book()
{
    delete ui;
}

void insert_book::on_pushButton_clicked()
{
    this->close();
    bookmanage *bm=new bookmanage;
    bm->setWindowTitle("图书管理界面");
    bm->setWindowIcon(QIcon(":/logo.ico"));
    bm->show();
}

void insert_book::on_insert_book_botton_clicked()
{
    QString i1=ui->i1->text();
    QString i2=ui->i2->text();
    QString i3=ui->i3->text();
    QString i4=ui->i4->text();
    QString i5=ui->i5->text();
    QString i6=ui->i6->text();
    QString i7=ui->i7->text();
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
    QString insert=QString("INSERT INTO book VALUES (\'%1\',\'%2\',\'%3\',\'%4\',\'%5\',\'%6\',\'%7\')").arg(i1).arg(i2).arg(i3).arg(i4).arg(i5).arg(i6).arg(i7);
    qDebug()<<insert;
    if(query.exec(insert))
    {
        qDebug()<<"ok";
    }
    else
    {
        qDebug()<<"fail";
    }

}
