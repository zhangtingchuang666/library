#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include<admin_main.h>
#include<student_main.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_login_clicked();

    void on_admin_clicked();


    void on_student_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
