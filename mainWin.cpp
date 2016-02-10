/*
   - author: Michael Wilson
   - prof: Yllias Chali
   - school class: Artificial Intelligence 
   - class: mainWin 
   - description ** main window the contains the canvas to draw to **
   - Assignment 1
*/

#include<QtGui>
#include "mainWin.h"
#include "canvas.h"
// main qt window
mainWin::mainWin()
{

   // font for label
   QFont tutFont("Arial", 7);
   QFont mainFont("Arial", 25);

   //sets up canvas
   canvas = new Canvas(this);
   //sets up buttons
   next = new QPushButton("Go");
   close = new QPushButton("close");
   inst  = new QPushButton("move goal = Right click and drag");
   inst2 = new QPushButton("move start = Left click and drag");
   next->setFont(mainFont);
   close->setFont(mainFont);

   // QT connections
   connect(next, SIGNAL(clicked()), canvas, SLOT(StartSearch()));
   connect(close, SIGNAL(clicked()), this, SLOT(close()));

   //sets up layout for window
   QGridLayout *layout = new QGridLayout;
   layout -> addWidget(canvas,0,0,4,4);
   layout -> addWidget(inst,5,0,1,1);
   layout -> addWidget(inst2,5,2,1,1);
   layout -> addWidget(next,7,0,1,3);
   layout -> addWidget(close,7,3,1,1);
   setLayout(layout);

   // sets up timer, connects it then starts it.
   timer = new QTimer(this);
   connect(timer, SIGNAL(timeout()), this, SLOT(updateSearch()));
   timer->start(10);
}

void mainWin::updateSearch()
{
   //starts the time and updates paint canvas
   timer->start(10);
   canvas->updatePaint(); 
}

