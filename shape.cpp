#include "shape.h"

shape::shape(bool closed)
{
	connectShape = closed;
}

void shape::move(char dir)
{
	switch (dir)
	{
	case 'u': // move up one unit
		for (int x = 0; x < shapePoints.size(); x++)
			shapePoints[x].second -= 5;
		break;
	case 'd': // move down one unit
		for (int x = 0; x < shapePoints.size(); x++)
			shapePoints[x].second += 5;
		break;
	case 'r': // move right one unit
		for (int x = 0; x < shapePoints.size(); x++)
			shapePoints[x].first += 5;
		break;
	case 'l': // move left one unit
		for (int x = 0; x < shapePoints.size(); x++)
			shapePoints[x].first -= 5;
		break;
	}
}
// returns 1 if validmove, 0 if goal was not found, -1 if not a validmove
int shape::ValidMove(std::pair< int, int > st, std::pair< int, int > go) // makes sure guy never goes straight through the shape.
{
	bool found = false;
	int location = 0;
	for (int x = 0; x < shapePoints.size(); x++)
	{
		if (shapePoints[x] == go)
		{
			found = true;
			location = x;
		}
	}

	if (location == 0)
	{
		if (shapePoints[location + 1] == st || shapePoints[shapePoints.size() - 1] == st)
			return 1;
	}
	else if (location == shapePoints.size()-1)
	{
		if (shapePoints[shapePoints.size()-2] == st || shapePoints[0] == st)
			return 1;
	}
	else
	{
		if (shapePoints[location + 1] == st || shapePoints[location - 1] == st)
			return 1;
	}
	if (!found)
		return -1;
	if (found)
		return 0;
}

	void shape::setGlobalCoordinates(int x, int y)
	{
		int xdist, ydist;
		xdist = x - shapePoints[0].first;
		ydist = y - shapePoints[0].second;
		for(int x = 0; x < shapePoints.size(); x++)
		{
			shapePoints[x].first += xdist;
			shapePoints[x].second += ydist;
		}

	}