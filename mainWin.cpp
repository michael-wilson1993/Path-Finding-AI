#include<QtGui>

#include "mainWin.h"
#include "canvas.h"

mainWin::mainWin()
{

   char c = 'd';
   canvas = new Canvas(this);
   next = new QPushButton("next step");
   r = new QPushButton("close");

   connect(next, SIGNAL(clicked()), this, SLOT(updateSearch()));
   connect(r, SIGNAL(clicked()), this, SLOT(close()));

   QGridLayout *layout = new QGridLayout;
   layout -> addWidget(canvas,0,0,4,4);
   layout -> addWidget(next,5,1,1,2);
   layout -> addWidget(r,5,3,1,1);

   setLayout(layout);

   timer = new QTimer(this);
   connect(timer, SIGNAL(timeout()), this, SLOT(updateSearch()));
   //timer->start(1000);
}

void mainWin::updateSearch()
{

   timer->start(25);
   canvas->updatePaint(); 
}

void mainWin::getmouse(QMouseEvent *ev)
{

}