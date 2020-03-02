#include <QApplication>
#include <stdio.h>
#include <stdlib.h>
#include "mainwindow.h"
#include "scanMapArea.h"
#include "rplidar.h"




int main(int argc, char *argv[])
{
	//----------------------------QT Gui----------------------------------------
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
