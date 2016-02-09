#include<QtGui>
#include "mainWin.h"
#include "canvas.h"
// main qt window
mainWin::mainWin()
{
   //sets up canvas
   canvas = new Canvas(this);
   //sets up buttons
   next = new QPushButton("Go");
   close = new QPushButton("close");
  
   // QT connections
   connect(next, SIGNAL(clicked()), canvas, SLOT(StartSearch()));
   connect(close, SIGNAL(clicked()), this, SLOT(close()));

   //sets up layout for window
   QGridLayout *layout = new QGridLayout;
   layout -> addWidget(canvas,0,0,4,4);
   layout -> addWidget(next,5,0,1,3);
   layout -> addWidget(close,5,3,1,1);
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

