#include "student_main.h"
#include "ui_student_main.h"
#include<globe.h>
student_main::student_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::student_main)
{
    ui->setupUi(this);
}

student_main::~student_main()
{
    delete ui;
}

void student_main::on_select_book_s_clicked()
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
  query.exec("select * from book");
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
  select_book_s *sbs=new select_book_s;
  this->close();
  sbs->setWindowTitle("图书查看界面");
  sbs->setWindowIcon(QIcon(":/logo.ico"));
  sbs->show();

}

void student_main::on_borrow_book_clicked()
{
    this->close();
    borrow_book *bb=new borrow_book;
    bb->setWindowTitle("图书借阅");
    bb->setWindowIcon(QIcon(":/logo.ico"));
    bb->show();
}

void student_main::on_select_borrow_clicked()
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
  db.exec("SET NAMES 'GBK'");
  QSqlQuery query(db);
  qDebug()<<id;
  QString bor=QString("select bo_id,bo_name from %1_b").arg(id);
  if(query.exec(bor))
  {
      qDebug()<<"OK";
  }
  else
  {
      qDebug()<<"fail";
  }
  QStringList borrow;
  while (query.next()) {
      borrow.clear();
      QString b_id=query.value(0).toString();
      QString b_name=query.value(1).toString();
      borrow<<b_id<<b_name;
      borrow_all.append(borrow);
  }
select_borrow *sb=new select_borrow;
this->close();
sb->setWindowTitle("查看图书借阅");
sb->setWindowIcon(QIcon(":/logo.ico"));
sb->show();
}
void student_main::on_return_book_clicked()
{
this->close();
back_book *bb=new back_book;
bb->setWindowTitle("图书归还界面");
bb->setWindowIcon(QIcon(":/logo.ico"));
bb->show();
}

