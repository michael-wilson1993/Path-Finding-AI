
#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <cstdlib>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


class shape
{
public:
	// constructor
	shape(bool closed = 0);
	// copy constructor to add the points into...
	void setup(std::vector< std::pair< int, int > > temp) { shapePoints = temp; };
	// returns connectShape which will connect the last and first coordinate.
	bool isConnected() { return connectShape; };
	// moves the coordinates for this entire shape in one direction.
	void move(char dir);
	// public vector that holds all the coordinates for the vertices.
	std::vector< std::pair< int, int > >  shapePoints;

	// returns vertice count
	int getCount() { return shapePoints.size(); };
	//checks if the move is possible within to shape. so you cannot just pass through a shape.
	int ValidMove(std::pair< int, int > st, std::pair< int, int > go);


private:
	bool connectShape;




};


#endif