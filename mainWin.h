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
   void UpdatePlayer();
   void updateSearch(); 
   
  private:
  QTimer *timer;
  QTimer *PlayerUpTimer;
   Canvas *canvas; 
   QComboBox *obj; 
   QPushButton *next;
   QPushButton *close, *pause, *reset, *d;


};

#endif
