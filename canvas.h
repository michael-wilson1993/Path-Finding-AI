
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

  protected:
   void paintEvent(QPaintEvent *);

  private:
   Object obj;
   searcher *player;
   shape *playerShape;
   
   std::vector< shape > listOfShapes;
   
};

#endif
