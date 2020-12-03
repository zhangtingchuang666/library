#include "back_book.h"
#include "ui_back_book.h"
#include<mainwindow.h>

back_book::back_book(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::back_book)
{
    ui->setupUi(this);
}

back_book::~back_book()
{
    delete ui;
}

void back_book::on_back_book_botton_clicked()
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
  QSqlQuery query1(db);
  QString back_id=ui->back_input->text();
  QString b=QString("DELETE FROM %1_b WHERE bo_id= \'%2\'").arg(id).arg(back_id);
  QString XIUGAI=QString("UPDATE book SET shuliang=shuliang+1 where ISBN=\'%1\'").arg(back_id);
  qDebug()<<b;
  if(query.exec(b))
  {
      qDebug()<<"ok";
      qDebug()<<XIUGAI;
      query1.exec(XIUGAI);
  }
  else
  {
      qDebug()<<"fail";
  }
}

void back_book::on_back_botton_clicked()
{
    this->close();
    student_main *s=new student_main;
    s->setWindowTitle("学生界面");
    s->setWindowIcon(QIcon(":/logo.ico"));
    s->show();
}
