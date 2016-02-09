#include<QtGui>
#include "canvas.h"

// creates the objects
Canvas::Canvas(QWidget *parent)
{
  // single location to specift goal and player start, makes it easy to change all values at once
   pl.first = 50;
   pl.second = 550;
   gl.first = 500;
   gl.second = 100;
   //create player
   player = new searcher(pl.first, pl.second, gl.first, gl.second);



   

    // - pushing 4 shapes onto a vector making it easy to change them and draw them.

   listOfShapes.push_back(shape(true));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(100,250));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(200,100));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(275,250));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(225,325));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(125,325));

   listOfShapes.push_back(shape(true));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(200,450));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(300,250));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(325,450));

   listOfShapes.push_back(shape(true));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(350,400));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(350,175));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(450,125));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(500,210));

   listOfShapes.push_back(shape(true));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(550,125));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(550,400));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(700,400));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(700,125));


   // - starting point and ending point vertices
   nonCollisionShapes.push_back(shape(true));
   nonCollisionShapes[nonCollisionShapes.size()-1].shapePoints.push_back(std::pair<int, int>(gl.first -7,gl.second-7));
   nonCollisionShapes[nonCollisionShapes.size()-1].shapePoints.push_back(std::pair<int, int>(gl.first-7,gl.second+7));
   nonCollisionShapes[nonCollisionShapes.size()-1].shapePoints.push_back(std::pair<int, int>(gl.first+7,gl.second+7));
   nonCollisionShapes[nonCollisionShapes.size()-1].shapePoints.push_back(std::pair<int, int>(gl.first+7,gl.second-7));

   nonCollisionShapes.push_back(shape(true));
   nonCollisionShapes[nonCollisionShapes.size()-1].shapePoints.push_back(std::pair<int, int>(pl.first -7,pl.second-7));
   nonCollisionShapes[nonCollisionShapes.size()-1].shapePoints.push_back(std::pair<int, int>(pl.first-7,pl.second+7));
   nonCollisionShapes[nonCollisionShapes.size()-1].shapePoints.push_back(std::pair<int, int>(pl.first+7,pl.second+7));
   nonCollisionShapes[nonCollisionShapes.size()-1].shapePoints.push_back(std::pair<int, int>(pl.first+7,pl.second-7));

   // - sets the players field by default. this can change at any time, when you move stuff around.
   player->setField(listOfShapes);
   // - gets the player shape to display on the screen.
   playerShape = player->getShape();

}

// slot so paint can be updated!
void Canvas::updatePaint()
{  
   // - moves the little green dot. dont have to use this.
   player->update();
   // - this will update the paintEvent, it is for QT
   update();
}

// draws shapes, paths, start, goal and path when it is found
void Canvas::paintEvent(QPaintEvent *event)
{
   
   QPainter paint(this); 
   // draws the shapes
   for (int x = 0; x < listOfShapes.size(); x++)
   {
   		for(int y = 0 ; y < listOfShapes[x].shapePoints.size()-1; y++ )
   		{
         paint.setPen(QPen(Qt::black, 2, Qt::SolidLine));
	 		paint.drawLine(listOfShapes[x].shapePoints[y].first,
	 						listOfShapes[x].shapePoints[y].second,
	 						listOfShapes[x].shapePoints[y+1].first,
	 						listOfShapes[x].shapePoints[y+1].second);
   		}
   		if(listOfShapes[x].isConnected())
   		{
	 		paint.drawLine(listOfShapes[x].shapePoints[0].first,
	 						listOfShapes[x].shapePoints[0].second,
	 						listOfShapes[x].shapePoints[   listOfShapes[x].shapePoints.size()-1		].first,
	 						listOfShapes[x].shapePoints[   listOfShapes[x].shapePoints.size()-1		].second);
   		}
   }

   // - this will draw the collision shapes like the starting point or goal point
   for (int x = 0; x < nonCollisionShapes.size(); x++)
   {
         for(int y = 0 ; y < nonCollisionShapes[x].shapePoints.size()-1; y++ )
         {
         paint.setPen(QPen(Qt::blue, 2, Qt::SolidLine));
         paint.drawLine(nonCollisionShapes[x].shapePoints[y].first,
                     nonCollisionShapes[x].shapePoints[y].second,
                     nonCollisionShapes[x].shapePoints[y+1].first,
                     nonCollisionShapes[x].shapePoints[y+1].second);
         }
         if(nonCollisionShapes[x].isConnected())
         {
         paint.drawLine(nonCollisionShapes[x].shapePoints[0].first,
                     nonCollisionShapes[x].shapePoints[0].second,
                     nonCollisionShapes[x].shapePoints[   nonCollisionShapes[x].shapePoints.size()-1     ].first,
                     nonCollisionShapes[x].shapePoints[   nonCollisionShapes[x].shapePoints.size()-1     ].second);
         }
   }

   // - draws the player (green dot)
         for(int y = 0 ; y < playerShape->shapePoints.size()-1; y++ )
         {
            paint.setPen(QPen(Qt::green, 2, Qt::SolidLine));
            paint.drawLine(playerShape->shapePoints[y].first,
                     playerShape->shapePoints[y].second,
                     playerShape->shapePoints[y+1].first,
                     playerShape->shapePoints[y+1].second);
         }
         if(playerShape->isConnected())
         {
            paint.setPen(QPen(Qt::green, 2, Qt::SolidLine));
            paint.drawLine(playerShape->shapePoints[0].first,
                     playerShape->shapePoints[0].second,
                     playerShape->shapePoints[     playerShape->shapePoints.size()-1      ].first,
                     playerShape->shapePoints[     playerShape->shapePoints.size()-1      ].second);
         }
         // - if the path was found it will draw it.
         if(path.size() > 0)
         for(int x = 0; x < path.size()-1; x++)
         {
            paint.setPen(QPen(Qt::red, 2, Qt::SolidLine));
            paint.drawLine(path[x].first,
                     path[x].second,
                     path[x+1].first,
                     path[x+1].second);

         }
  
}




void Canvas::mouseMoveEvent(QMouseEvent *e)
{
   // mouse event Rightbutton is pressed
   // changes the coordinates for the starting point
  if(e->buttons() == Qt::RightButton)
  {
   delete player;
   player = new searcher(pl.first, pl.second, e->x()+7, e->y()+7);
   player->setField(listOfShapes);
   playerShape = player->getShape();
   nonCollisionShapes[0].setGlobalCoordinates(e->x(), e->y());
   gl.first = e->x()+7;
   gl.second = e->y()+7;
   update();
   path.clear();
}
if(e->buttons() == Qt::LeftButton)
{
   // mouse event leftbutton is pressed
   // changes the coordinates of the goal location
   delete player;
   player = new searcher(e->x()+7, e->y()+7, gl.first, gl.second);
   player->setField(listOfShapes);
   playerShape = player->getShape();
   nonCollisionShapes[1].setGlobalCoordinates(e->x(), e->y());
   pl.first = e->x()+7;
   pl.second = e->y()+7;
   update();
   path.clear();
}  
}

// starts the search and assignes it to path so QT can draw it
void Canvas::StartSearch()
{
   player->startPlayer();
   path = player->getPath();
}
