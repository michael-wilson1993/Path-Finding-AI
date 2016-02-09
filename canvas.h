
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

 Canvas(QWidget *parent = 0);
 void startPlayer();
 public slots:
   /*
   - void updatePaint();
   - this is a slot that will update the player and the it will repaint the canvas...
   */
   void updatePaint();
   /*
    - void StartSearch();
    - this will start the players search algorithm to find the shortest path through the field
   */
    void StartSearch();


  protected:
    /*
     - void paintEvent();
     - this will paint all the objects onto the canvas
    */
     void paintEvent(QPaintEvent *);
   /*
    - void mouseMoveEvent(QMouseEvent *e);
    - detects when a mouse event happens. 
    - if left clicked, sets the starting point for the path finding.
    - if right clicked, sets the goal point for the path finding.
   */
    void mouseMoveEvent(QMouseEvent *e);

  private:


  searcher *player;
  std::vector< shape > nonCollisionShapes; // player start, goal
  shape *playerShape; // playershape is a shape that we get from player to display on the canvas
  std::pair< int, int > pl, gl; // pl is player coordinates, and gl is goal coordinates.
  std::vector< std::pair< int, int > > path; // is the shortest path found by player
  std::vector< shape > listOfShapes;// shapes on the board
 
};

#endif
