#-------------------------------------------------
#
# Project created by QtCreator 2018-09-27T20:55:09
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LearnProgramming
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    lesson.cpp \
    workbook.cpp \
    admin.cpp \
    mistakeplace.cpp \
    test.cpp \
    fixlecture.cpp \
    registration.cpp \
    addstudent.cpp \
    allresults.cpp \
    personalresults.cpp \
    total.cpp \
    deletetest.cpp

HEADERS += \
        mainwindow.h \
    lesson.h \
    workbook.h \
    admin.h \
    mistakeplace.h \
    test.h \
    fixlecture.h \
    registration.h \
    addstudent.h \
    allresults.h \
    personalresults.h \
    total.h \
    deletetest.h

FORMS += \
        mainwindow.ui \
    lesson.ui \
    workbook.ui \
    admin.ui \
    mistakeplace.ui \
    test.ui \
    fixlecture.ui \
    registration.ui \
    addstudent.ui \
    allresults.ui \
    personalresults.ui \
    total.ui \
    deletetest.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    first
