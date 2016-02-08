#include <QtGui>
#include "mainWin.h"

int main(int argc, char *argv[])
{
   QApplication app(argc,argv);

   mainWin paint;
   paint.resize(1000, 700); 
   paint.setWindowTitle("2D Symbol Program");
   paint.setStyleSheet("font-size: 24px;"
		       "background-color: grey;"); 
   paint.show();

   return app.exec(); 

}
