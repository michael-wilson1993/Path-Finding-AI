#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include "canvas.h"
#include <QTimer>
#include <string>
#include <QMouseEvent>


class QTimer;
class Canvas;
class QComboBox;
class QPushButton;
class QGridgeLayout;

class mainWin : public QWidget
{

   Q_OBJECT

   public:
   mainWin();
   void getmouse(QMouseEvent *ev);

   private slots:
   void updateSearch(); 
   
  private:
  QTimer *timer;
   Canvas *canvas; 
   QComboBox *obj; 
   QPushButton *next;
   QPushButton *r, *l, *u, *d;


};

#endif
