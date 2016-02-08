#include<QtGui>
#include "canvas.h"

// creates the objects
Canvas::Canvas(QWidget *parent)
{
   
   player = new searcher(50, 550);

   obj = Text;
 
   listOfShapes.push_back(shape(true));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(100,500));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(100,600));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(450,600));
   listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(450,500));
  
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

   // listOfShapes.push_back(shape(true));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(550,125));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(550,400));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(700,400));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(700,125));

   // listOfShapes.push_back(shape(true));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(400,400));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(500,550));
   // listOfShapes[listOfShapes.size()-1].shapePoints.push_back(std::pair<int, int>(600,475));

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
   			paint.setPen(QPen(Qt::black, 2, Qt::SolidLine));
	 		paint.drawLine(listOfShapes[x].shapePoints[0].first,
	 						listOfShapes[x].shapePoints[0].second,
	 						listOfShapes[x].shapePoints[   listOfShapes[x].shapePoints.size()-1		].first,
	 						listOfShapes[x].shapePoints[   listOfShapes[x].shapePoints.size()-1		].second);
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




   /*
   QRect rect(0,0,200,200);
   QLinearGradient lg(0,0,200,200); 
   switch(obj)
   {
      case Line:
	 paint.setPen(QPen(Qt::black, 2, Qt::SolidLine));
	 paint.drawLine(10,10,1000,700);
	 break;
      case Rect:
	 //paint.setRenderHint(QPainter::Antialiasing, true); 
	 paint.setBrush(QBrush(Qt::red, Qt::SolidPattern));
	 paint.drawRect(rect);
	 break; 
      case RoundRect:
	 paint.setPen(QPen(Qt::blue, 3, Qt::DashDotLine));
	 paint.setBrush(QBrush(Qt::darkMagenta, Qt::DiagCrossPattern)); 
	 paint.drawRoundRect(rect, 25, 25);
	 break; 
      case Ellipse:
	 //paint.setRenderHint(QPainter::Antialiasing, true); 
	 lg.setColorAt(0.0, Qt::white);
	 lg.setColorAt(0.2, Qt::green);
	 lg.setColorAt(1.0, Qt::black);
	 paint.setBrush(lg); 
	 paint.drawEllipse(rect);
	 break; 
      case Text:
	 paint.drawText(rect, Qt::AlignCenter, "Select an Object"); 
   }
   */
}


void Canvas::loadFromFile(QString filename)
{
//still to be made. for now input shapes manualy
	
}