
#ifndef CANVAS_H
#define CANVAS_H

#include "searcher.h"
#include <string>
#include <QWidget>
#include <iostream>
#include "shape.h"
#include <vector>
#include <fstream>


class Canvas : public QWidget
{
   Q_OBJECT

   public:
   enum Object { Line, Rect, RoundRect, Ellipse, Text };
   Canvas(QWidget *parent = 0);
   void loadFromFile(QString filename);

   public slots:
   void updatePaint();
   void startPlayer();

  protected:
   void paintEvent(QPaintEvent *);
   void mouseMoveEvent(QMouseEvent *e);

  private:
   Object obj;
   searcher *player;
    std::vector< shape > nonCollisionShapes; // player start, goal
   shape *playerShape, *goalShape, *startShape; 
   std::pair< int, int > pl, gl;
   std::vector< shape > listOfShapes;// shapes on the board
   
};

#endif
