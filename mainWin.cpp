#include<QtGui>
#include "mainWin.h"
#include "canvas.h"
// main qt window
mainWin::mainWin()
{

   char c = 'd';
   canvas = new Canvas(this);
   next = new QPushButton("Go");
   close = new QPushButton("close");
   pause = new QPushButton("pause");
   reset = new QPushButton("reset");

   connect(next, SIGNAL(clicked()), canvas, SLOT(startPlayer()));
   connect(close, SIGNAL(clicked()), this, SLOT(close()));

   QGridLayout *layout = new QGridLayout;
   layout -> addWidget(canvas,0,0,4,4);
   layout -> addWidget(next,5,1,1,2);
   layout -> addWidget(close,5,3,1,1);

   setLayout(layout);

   timer = new QTimer(this);
   connect(timer, SIGNAL(timeout()), this, SLOT(updateSearch()));
   timer->start(25);
}

void mainWin::updateSearch()
{

   timer->start(25);
   canvas->updatePaint(); 
}

void mainWin::getmouse(QMouseEvent *ev)
{

}