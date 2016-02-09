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

 
   connect(next, SIGNAL(clicked()), canvas, SLOT(StartSearch()));
   connect(close, SIGNAL(clicked()), this, SLOT(close()));

   QGridLayout *layout = new QGridLayout;
   layout -> addWidget(canvas,0,0,4,4);
   layout -> addWidget(next,5,1,1,2);
   layout -> addWidget(close,5,3,1,1);
   layout -> addWidget(reset,5,0,1,1);

   setLayout(layout);

   timer = new QTimer(this);
   PlayerUpTimer = new QTimer(this);
  // connect(PlayerUpTimer, SIGNAL(timeout()), this, SLOT(UpdatePlayer()));
   connect(timer, SIGNAL(timeout()), this, SLOT(updateSearch()));
   timer->start(100);
}

void mainWin::updateSearch()
{

   timer->start(10);
   canvas->updatePaint(); 
}

void mainWin::UpdatePlayer()
{
   PlayerUpTimer->start(25);
   canvas->startPlayer();

}