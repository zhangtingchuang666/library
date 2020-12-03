#include "update_book.h"
#include "ui_update_book.h"

update_book::update_book(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::update_book)
{
    ui->setupUi(this);
}

update_book::~update_book()
{
    delete ui;
}

void update_book::on_update_botton_clicked()
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
    QString a1=ui->update_input1->text();
    QString a2=ui->update_input2->currentText();
    QString a3=ui->result->text();
    QString up=QString("UPDATE book SET %1=\'%2\' where ISBN=\'%3\'").arg(a2).arg(a3).arg(a1);
    qDebug()<<up;
    if(query.exec(up)){
        qDebug()<<"OK";
    }
    else
    {
        qDebug()<<"fail";
    }
}

void update_book::on_back_botton_clicked()
{
    bookmanage *b1=new bookmanage;
    this->close();
    b1->setWindowTitle("图书管理界面");
    b1->setWindowIcon(QIcon(":/logo.ico"));
    b1->show();
}
