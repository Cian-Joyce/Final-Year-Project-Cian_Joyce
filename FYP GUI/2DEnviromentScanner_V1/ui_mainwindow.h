/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "scanMapArea.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionErase;
    QWidget *centralwidget;
    scanMapArea *widget;
    QMenuBar *menubar;
    QMenu *menuOptions;
    QMenu *menuPoint_colour;
    QMenu *menuPoint_width;
    QMenu *menuClear_map;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionErase = new QAction(MainWindow);
        actionErase->setObjectName(QString::fromUtf8("actionErase"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new scanMapArea(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(9, 10, 341, 171));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: #C255C255C255;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuPoint_colour = new QMenu(menubar);
        menuPoint_colour->setObjectName(QString::fromUtf8("menuPoint_colour"));
        menuPoint_width = new QMenu(menubar);
        menuPoint_width->setObjectName(QString::fromUtf8("menuPoint_width"));
        menuClear_map = new QMenu(menubar);
        menuClear_map->setObjectName(QString::fromUtf8("menuClear_map"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOptions->menuAction());
        menubar->addAction(menuPoint_colour->menuAction());
        menubar->addAction(menuPoint_width->menuAction());
        menubar->addAction(menuClear_map->menuAction());
        menuOptions->addSeparator();
        menuClear_map->addAction(actionErase);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionErase->setText(QCoreApplication::translate("MainWindow", "Erase", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
        menuPoint_colour->setTitle(QCoreApplication::translate("MainWindow", "Point colour", nullptr));
        menuPoint_width->setTitle(QCoreApplication::translate("MainWindow", "Point width", nullptr));
        menuClear_map->setTitle(QCoreApplication::translate("MainWindow", "Clear map", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
