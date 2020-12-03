#include "mainwindow.h"
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
//    QStringList ab;
//    QString aa="aaaa";
//    QString bb="bbbb";
//    ab<<aa<<bb;
//    qDebug()<<ab;
//    qDebug()<<ab.size();
    QString aaa="aaaaa1";
    QString bbb=QString("aaaa %1").arg(aaa);
    qDebug()<<bbb;
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("library");
    db.setUserName("root");
    db.setPassword("123");
    if (!db.open())
    qDebug() << "Failed to connect to root mysql admin";
    else qDebug() << "open";
    MainWindow w;
    w.setWindowTitle("信闯哥，得永生");
    w.setWindowIcon(QIcon(":/logo.ico"));
    w.show();
    return a.exec();
}
