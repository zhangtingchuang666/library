#include "bookmanage.h"
#include "ui_bookmanage.h"
#include<mainwindow.h>
#include<select_book.h>
#include<del_book.h>
#include<update_book.h>
#include<insert_book.h>
#include<globle.h>
bookmanage::bookmanage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookmanage)
{
    ui->setupUi(this);
}

bookmanage::~bookmanage()
{
    delete ui;
}

void bookmanage::on_return_book_clicked()
{
    admin_main *m2=new admin_main;
    this->close();
    m2->setWindowTitle("管理员界面");
    m2->setWindowIcon(QIcon(":/logo.ico"));
    m2->show();
}

void bookmanage::on_select_book_clicked()
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
    db.exec("SET NAMES 'GBK'");
    query.exec("select * from admin_book");
    QStringList book;
    while (query.next()) {
       book.clear();
      QString b_1=query.value(0).toString();
      QString b_2=query.value(1).toString();
      QString b_3=query.value(2).toString();
      QString b_4=query.value(3).toString();
      QString b_5=query.value(4).toString();
      QString b_6=query.value(5).toString();
      QString b_7=query.value(6).toString();
      book<<b_1<<b_2<<b_3<<b_4<<b_5<<b_6<<b_7;
      book_all.append(book);
    }
    this->close();
    select_book *sb=new select_book;
    sb->setWindowTitle("图书查看界面");
    sb->setWindowIcon(QIcon(":/logo.ico"));
    sb->show();

}
void bookmanage::on_del_book_clicked()
{
    del_book *del=new del_book;
    this->hide();
    del->setWindowTitle("图书删除界面");
    del->setWindowIcon(QIcon(":/logo.ico"));
    del->show();
}
void bookmanage::on_insert_book_clicked()
{
    insert_book *ib=new insert_book;
    this->hide();
    ib->setWindowTitle("图书添加界面");
    ib->setWindowIcon(QIcon(":/logo.ico"));
    ib->show();
}

void bookmanage::on_update_book_clicked()
{
    update_book *ub=new update_book;
    this->hide();
    ub->setWindowTitle("图书修改界面");
    ub->setWindowIcon(QIcon(":/logo.ico"));
    ub->show();
}
//void bookmanage::on_return_book_clicked()
//{
//    this->close();
//}
