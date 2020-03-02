#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scanMapArea.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //ui(new Ui::scanMapArea)
    ui->setupUi(this);
    initActions();
    initMenus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{

}

void MainWindow::initActions()
{
    QString scanMapName = "scanMapArea";    //make a QString of the UI widget name
    //Getting the pointer to the QWidget named scanMapName from parent UI MainWindow
    QWidget *scanMapWidget = MainWindow::findChild<QWidget *>(scanMapName);
    connect(scanMapWidget, SIGNAL(), this, SLOT(clearScanMap()));
}

void MainWindow::initMenus()
{

}

void MainWindow::clearScanMap()
{

}

