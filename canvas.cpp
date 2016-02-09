#include<QtGui>
#include "canvas.h"

// creates the objects
Canvas::Canvas(QWidget *parent)
{
  
   pl.first = 50;
   pl.second = 550;
   gl.first = 500;
   gl.second = 100;
   player = new searcher(pl.first, pl.second, gl.first, gl.second);

   obj = Text;
   /*took out a few objects because it take to long with those objects*/
   
   // listOfShapes.push_back(shape(true));
   // //listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(100,500));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(100,600));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(450,600));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(450,500));
   //    listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(100,500));
  
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

   //listOfShapes.push_back(shape(true));
    //listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(400,400));
    //listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(500,550));
    //listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(600,475));

   // listOfShapes.push_back(shape(true));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(725,400));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(675,450));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(675,525));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(725,575));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(775,525));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(775,450));

   // listOfShapes.push_back(shape(true));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(750,125));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(725,150));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(760,400));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(775,150));

   // listOfShapes.push_back(shape(false));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(gl.first,gl.second));


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

   player->setField(listOfShapes);
   playerShape = player->getShape();

}

void Canvas::updatePaint()
{  
   player->update();
   update();
}


void Canvas::paintEvent(QPaintEvent *event)
{
   
   QPainter paint(this); 

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


void Canvas::loadFromFile(QString filename)
{
//still to be made. for now input shapes manualy
	
}

void Canvas::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() == Qt::RightButton)
    {
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
   if(e->buttons() == Qt::LeftButton)
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
}

void Canvas::StartSearch()
{
   player->startPlayer();
   path = player->getPath();


}
