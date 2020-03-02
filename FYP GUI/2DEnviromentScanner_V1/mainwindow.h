#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scanMapArea.h"

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class scanMapArea;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    //~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);    //event for handling window close

private slots:
    void pointColour(); //slot for point colour change signal
    void pointWidth();   //slot for point width change signal

private:
   // Ui::MainWindow *ui;
    void initActions(); //function for building actions
    void initMenus();   //function for building GUI menus

    scanMapArea *ScanMapArea;   //object for scan map widget
    //Menu widgets
    QMenu *fileMenu;
    QMenu *optionMenu;

    QAction *pointColourAction; //action for changing point colour
    QAction *pointWidthAction;  //action for changing point width
    QAction *clearScanMapAction;//action for clearing the scan map
    QAction *exitAction;

};
#endif // MAINWINDOW_H
