#include "del_book.h"
#include "ui_del_book.h"
#include "bookmanage.h"
#include "mainwindow.h"
del_book::del_book(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::del_book)
{
    ui->setupUi(this);
}

del_book::~del_book()
{
    delete ui;
}

void del_book::on_pushButton_clicked()
{
    this->close();
    bookmanage *bm=new bookmanage;
    bm->setWindowTitle("图书管理界面");
    bm->setWindowIcon(QIcon(":/logo.ico"));
    bm->show();
}

void del_book::on_del_book_botton_clicked()
{
    QString id=ui->del_input->text();
    qDebug()<<id;
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
    db.exec("SET NAMES 'GBK'");
    QString del=QString("DELETE from book where ISBN =%1").arg(id);
    qDebug()<<del;
    if (query.exec(del))
        {
            qDebug()<< "delete sucess";

        }
        else
        {
            qDebug()<< "delete fail";

        }

}
