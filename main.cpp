/*
   - author: Michael Wilson
   - prof: Yllias Chali
   - school class: Artificial Intelligence 
   - class: main
   - description ** main program **
   - Assignment 1
*/

#include <QtGui>
#include "mainWin.h"

int main(int argc, char *argv[])
{
	//Qapplication for vicuals
	QApplication app(argc,argv);
	// window to paint stuff to
	mainWin draw;
	//make the window the correct size, and label correctly
	draw.resize(1000, 700); 
	draw.setWindowTitle("Path finding program");
	draw.setStyleSheet("background-color: grey;"); 
	draw.show();
	// runs the app
	return app.exec(); 

}
