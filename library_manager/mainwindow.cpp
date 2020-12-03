#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"globe.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->password_input->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_login_clicked()
{if(login_choice==1){
 QString id=ui->id_input->text();
 QString password=ui->password_input->text();
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
 query.exec("select id,password from admin");
 qDebug()<<"开始";
 while(query.next())
 {
     QString id_1=query.value(0).toString();
     QString password_1=query.value(1).toString();
     if(id.compare(id_1)==0&&password.compare(password_1)==0)
     {
         qDebug()<<"账号密码正确";
         admin_main *m=new admin_main;
         m->setWindowTitle("管理员界面");
         m->setWindowIcon(QIcon(":/logo.ico"));
         this->close();
         m->show();

     }
     else
     {
         qDebug()<<"账号或密码错误";
     }

 }}
    else if(login_choice==2)
    {
        id=ui->id_input->text();
        QString password=ui->password_input->text();
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
        query.exec("select id,password from student");
        qDebug()<<"开始";
        while(query.next())
        {
            QString id_1=query.value(0).toString();
            QString password_1=query.value(1).toString();
            if(id.compare(id_1)==0&&password.compare(password_1)==0)
            {
                qDebug()<<"账号密码正确";
                student_main *s=new student_main;
                s->setWindowTitle("学生界面");
                s->setWindowIcon(QIcon(":/logo.ico"));
                this->hide();
                s->show();

            }
            else
            {
                qDebug()<<"账号或密码错误";
            }

        };
    }
}

void MainWindow::on_admin_clicked()
{
    login_choice=1;
}

void MainWindow::on_student_clicked()
{
    login_choice=2;
}
