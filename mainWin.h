/*
   - author: Michael Wilson
   - prof: Yllias Chali
   - school class: Artificial Intelligence 
   - class: mainWin 
   - description ** main window the contains the canvas to draw to **
   - Assignment 1
*/

#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include "canvas.h"
#include <QTimer>
#include <string>
#include <QMouseEvent>

// QT classes needed for GUI
class QTimer;
class Canvas;
class QLabel;
class QPushButton;
class QGridgeLayout;

class mainWin : public QWidget
{

   Q_OBJECT // needed for QT

   public:
    // constructor that sets up the buttons and connects them accordingly
   mainWin();

   private slots:
   // update player will send a message to canvas telling player to find the shortest path
   void updateSearch(); 
   
  private:
   QTimer *timer; // timer making animation possible
   Canvas *canvas; // canvas is the widget allowing me to draw to the screen
   QPushButton *next, *close, *inst, *inst2; // next and close buttons

;


};

#endif
