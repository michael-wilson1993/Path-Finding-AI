#include <QtGui>
#include "mainWin.h"

int main(int argc, char *argv[])
{
	//Qapplication for vicuals
	QApplication app(argc,argv);
	// window to paint stuff to
	mainWin paint;
	//make the window the correct size, and label correctly
	paint.resize(1000, 700); 
	paint.setWindowTitle("2D Symbol Program");
	paint.setStyleSheet("font-size: 24px;" "background-color: grey;"); 
	paint.show();
	// runs the app
	return app.exec(); 

}
