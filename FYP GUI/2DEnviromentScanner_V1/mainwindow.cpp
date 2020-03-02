/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>

#include "mainwindow.h"
#include "scanMapArea.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ScanMapArea(new scanMapArea(this))
{
    setCentralWidget(ScanMapArea); //set scribble area as main widget

    initActions();    //function for initilising actions
    initMenus();      //function for creating menus

    setWindowTitle(tr("Scan map")); //setting the title for the main window
    resize(600, 600);
}

void MainWindow::closeEvent(QCloseEvent *event)
{

}

void MainWindow::pointColour() //function for saving and sending pen colour to scan area
{
    //get chosen colour from the QColourDialog
    QColor newColour = QColorDialog::getColor(ScanMapArea->getPointColor());

    if (newColour.isValid()) //check that chosen colour is valid
    {
        ScanMapArea->setPointColour(newColour);    //if so set the scan area point colour to new colour
    }

}

void MainWindow::pointWidth()
{
    bool ok;

    //set new width to a value between 1 & 50 with 1 step increments for pen width, & when user clicks ok set ok
    //variable
    int newWidth = QInputDialog::getInt
            (this, tr("Scribble"),tr("Select pen width:"),ScanMapArea->getPointWidth(),1, 50, 1, &ok);

    if (ok) //if user presses okay
    {
         ScanMapArea->setPointWidth(newWidth);   //set the pen width to the new selected width
    }

}


void MainWindow::initActions()    //function for initilsing all the actions
{

    exitAction = new QAction(tr("E&xit"), this);   //create quit action
    exitAction->setShortcuts(QKeySequence::Quit);  //make shortcut for quit
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);    //tie to main window

    pointColourAction = new QAction(tr("&Pen Color..."), this);   //create change colour action
    connect(pointColourAction, &QAction::triggered, this, &MainWindow::pointColour); //tie to main window

    pointWidthAction = new QAction(tr("Pen &Width..."), this);   //create width action
    connect(pointWidthAction, &QAction::triggered, this, &MainWindow::pointWidth); //tie to main window

    clearScanMapAction = new QAction(tr("&Clear Screen"), this);    //create clear screen action
    clearScanMapAction->setShortcut(tr("Ctrl+L"));  //create shortcut
    //connect clearScreen action trigger, to scribbleArea clearImage function
    connect(clearScanMapAction, &QAction::triggered,
            ScanMapArea, &scanMapArea::clearScanMap);

}

void MainWindow::initMenus()
{

    //add actions to the file menu
    fileMenu = new QMenu(tr("&File"), this);

    fileMenu->addAction(exitAction);

    //add actions to the options menu
    optionMenu = new QMenu(tr("&Options"), this);
    optionMenu->addAction(pointColourAction);
    optionMenu->addAction(pointWidthAction);
    optionMenu->addSeparator();
    optionMenu->addAction(clearScanMapAction);


    //add different menus to the menu bar
    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(optionMenu);
}



