#-------------------------------------------------
#
# Project created by QtCreator 2020-11-26T17:09:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = library_manager
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    admin_main.cpp \
    studentmanage.cpp \
    bookmanage.cpp \
    student_main.cpp \
    select_book.cpp \
    globe.cpp \
    del_book.cpp \
    update_book.cpp \
    insert_book.cpp \
    select_book_s.cpp \
    select_student.cpp \
    del_student.cpp \
    insert_student.cpp \
    update_student.cpp \
    select_borrow.cpp \
    borrow_book.cpp \
    back_book.cpp

HEADERS  += mainwindow.h \
    admin_main.h \
    studentmanage.h \
    bookmanage.h \
    student_main.h \
    select_book.h \
    globe.h \
    del_book.h \
    update_book.h \
    insert_book.h \
    select_book_s.h \
    select_student.h \
    del_student.h \
    insert_student.h \
    update_student.h \
    select_borrow.h \
    borrow_book.h \
    back_book.h

FORMS    += mainwindow.ui \
    admin_main.ui \
    studentmanage.ui \
    bookmanage.ui \
    student_main.ui \
    select_book.ui \
    del_book.ui \
    update_book.ui \
    insert_book.ui \
    select_book_s.ui \
    select_student.ui \
    del_student.ui \
    insert_student.ui \
    update_student.ui \
    select_borrow.ui \
    borrow_book.ui \
    back_book.ui
QT       += sql

RESOURCES += \
    logo.qrc
