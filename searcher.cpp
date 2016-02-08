#include "searcher.h"
#include <iostream>
using namespace std;



struct Point {
	double x, y;
};

int intersect_line(Point a, Point b, Point c, Point d, Point &p);

searcher::searcher(int x, int y)
{
	start.first = x;
	start.second = y;
	//currentLowCost.push_back(00);
	endgoal.first = 800;
	endgoal.second = 200;
	currLoc = 0;
	cost = 0;
	player = new shape(true);

	player->shapePoints.push_back(std::pair<int, int>(x - 2, y - 2));
	player->shapePoints.push_back(std::pair<int, int>(x - 2, y + 2));
	player->shapePoints.push_back(std::pair<int, int>(x + 2, y + 2));
	player->shapePoints.push_back(std::pair<int, int>(x + 2, y - 2));

	goalstep.push_back(start);

	next = goalstep[currLoc];



}

void searcher::setField(std::vector< shape > setter)
{
	field = setter;
	for (int x = 0; x < field.size(); x++)
		vertCount += field[x].getCount();
	std::vector< std::pair < int, int > > temp;

	int cur = 0;
	node t = AstarSearch(start, endgoal, cur, cost, temp);
	cout << endl << t.cost << endl << endl;
	goalstep = t.best;
	/*goalstep.push_back(start);*/
	//goalstep = retTemp;
	//goalstep.push_back(start);
	std::reverse(goalstep.begin(), goalstep.end());
	//std::cerr << t << std::endl;

	for (int x = 0; x < goalstep.size(); x++)
	{
		std::cerr << goalstep[x].first << "," << goalstep[x].second << std::endl;
	}
}

void searcher::update()
{

	if (start != goalstep[goalstep.size() - 1])
	{

		if (start.first < next.first)
		{
			player->move('r');
			start.first += 5;
		}
		else if (start.first > next.first)
		{
			player->move('l');
			start.first -= 5;
		}

		if (start.second > next.second)
		{
			player->move('u');
			start.second -= 5;
		}
		else if (start.second < next.second)
		{
			player->move('d');
			start.second += 5;
		}
		if (start == goalstep[currLoc])
		{
			currLoc++;
			next = goalstep[currLoc];
		}
	}

}

int searcher::pickclosestCoor(shape p)
{
	int shortest, shortestIndex, temp;
	shortest = dist(start, p.shapePoints[0]); // base case for the shortest distance
	shortestIndex = 0;
	for (int x = 1; x < p.shapePoints.size(); x++)
	{
		temp = dist(start, p.shapePoints[x]);
		if (shortest > temp)
		{
			shortest = temp;
			shortestIndex = x;
		}
	}
	return shortestIndex;
}

//check to see if i can reach all the states. recursivly call the ones i can reach no problem.
node searcher::AstarSearch(std::pair < int, int > currState, std::pair < int, int > goalState, int currentState, double cost, std::vector< std::pair < int, int >  > visited)
{

	cout << currState.first << "," << currState.second << endl;
	visited.push_back(currState);

	bool firstFlag = false;
	node adder;
	adder.GoalFound = false;

	if (validMove(currState, goalState))
	{
		cout << goalState.first << "," << goalState.second << endl;
		adder.cost = dist(currState, goalState) + cost;
		adder.best.push_back(goalState);
		adder.best.push_back(currState);
		adder.noMoreOptions = false;
		adder.GoalFound = true;
		cout << "found end here!!!!" << endl;
		return adder;
	}


	for (int x = 0; x < field.size(); x++)
	{
		for (int y = 0; y < field[x].shapePoints.size(); y++)
		{
			if (!visitedCheck(visited, field[x].shapePoints[y]) && validMove(field[x].shapePoints[y], currState))
			{

				node temp = AstarSearch(field[x].shapePoints[y], goalState, currentState, cost + dist(currState, field[x].shapePoints[y]), visited);
				if (!firstFlag)
				{
					firstFlag = true;
					adder = temp;
				}
				if (adder.cost > temp.cost)
				{
					if(temp.GoalFound == true)
						adder = temp;
				}
			}
		}
	}


	adder.best.push_back(currState);
	return adder;
	/*
	currentState++;
	if( currentLowCost.size() < currentState)
	currentLowCost.push_back(100000000000);

	std::pair< int, int > adder;
	visited.push_back(currState);
	std::vector< std::pair < int, int > > smallestlist;
	retTemp.push_back(currState);


	long int smallest = -1;
	if (validMove(currState, goalState))
	{
	retTemp.push_back(goalState);
	return dist(currState, goalState);
	}

	for ( int x = 0; x < field.size(); x++)
	{
	for ( int y = 0; y < field[x].shapePoints.size(); y++)
	{

	if(!visitedCheck(visited , field[x].shapePoints[y]) && validMove(currState, field[x].shapePoints[y]))
	{
	retTemp.clear();
	long int temp = AstarSearch(field[x].shapePoints[y], endgoal, currentState, cost + dist(currState, field[x].shapePoints[y]), visited);
	if(smallest == -1)
	{
	adder = field[x].shapePoints[y];
	smallest = temp;
	smallestlist = retTemp;
	retTemp.clear();
	}
	if(smallest > temp)
	{
	adder = field[x].shapePoints[y];
	smallest = temp;
	smallestlist = retTemp;
	retTemp.clear();
	}
	if(temp < currentLowCost[currentState])
	{
	goalstep = retTemp;
	currentLowCost[currentState] = temp;
	}
	}
	}
	}
	retTemp = smallestlist;
	std::cerr << currentState << std::endl;
	return smallest + cost;
	*/
}

bool searcher::validMove(std::pair< int, int > st, std::pair < int, int> shapeClosest)
{
	std::pair< int, int > a, b;
	a = st;
	b = shapeClosest;
	if (st.first < shapeClosest.first)
	{
		st.first++;
		shapeClosest.first--;
	}
	else
	{
		st.first--;
		shapeClosest.first++;
	}
	if (st.second < shapeClosest.second)
	{
		st.second++;
		shapeClosest.second--;
	}
	else
	{
		st.second--;
		shapeClosest.second++;
	}
	for (int x = 0; x < field.size(); x++)
	{
		for (int y = 0; y < field[x].shapePoints.size() - 1; y++)
		{

			if (a == field[x].shapePoints[y])
			{
				if (field[x].ValidMove(a, b) == 1)
					return true;
				else if (field[x].ValidMove(a, b) == -1)
					return false;
			}
			if (true == intersect(st, shapeClosest, field[x].shapePoints[y], field[x].shapePoints[y + 1])
				&& field[x].shapePoints[y + 1] != shapeClosest
				&& field[x].shapePoints[y] != shapeClosest
				&& field[x].shapePoints[y + 1] != st
				&& field[x].shapePoints[y] != st)
			{
				return false;
			}
		}
		 if(true == intersect(st, shapeClosest, field[x].shapePoints[0], field[x].shapePoints[field[x].shapePoints.size()-1])
		 		&& field[x].shapePoints[0] != shapeClosest
		 		&& field[x].shapePoints[field[x].shapePoints.size()-1] != shapeClosest
		 		&& field[x].shapePoints[0] != st
		 		&& field[x].shapePoints[field[x].shapePoints.size()-1] != st)
		 {
		 	return false;
		 }


	}
	return true;
}
// returns true if there was a intersection. 
bool searcher::intersect(std::pair< int, int > aa, std::pair< int, int > bb, std::pair< int, int > cc, std::pair< int, int > dd)
{

	Point a, b, c, d;
	a.x = aa.first;
	a.y = aa.second;

	b.x = bb.first;
	b.y = bb.second;

	c.x = cc.first;
	c.y = cc.second;

	d.x = dd.first;
	d.y = dd.second;

	Point temp;

	if (intersect_line(a, b, c, d, temp) == 1 || intersect_line(a, b, c, d, temp) == -1)
	{
		//goalstep.push_back(std::pair < int, int > (temp.x, temp.y));
		return true;

	}
	return false;
}

int searcher::dist(std::pair< int, int > aa, std::pair< int, int > bb)
{
	int d1 = aa.first - bb.first;
	int d2 = aa.second - bb.second;
	int r1, r2;
	r1 = d1 * d1;
	r2 = d2 * d2;
	return r1 + r2;
}

/*
* 2-D Line Intersection
*
* Author: Howard Cheng
* Reference:
*   http://www.exaflop.org/docs/cgafaq/cga1.html
*
* This routine takes two line segments specified by endpoints, and
* determines whether they intersect at one point, infinitely points,
* or no points.  In the first case, the point of intersection is also
* returned.  The endpoints of a line must be different (otherwise,
* the line is not defined).
*
*/
/* returns 1 if intersect at a point, 0 if not, -1 if the lines coincide */
int intersect_line(Point a, Point b, Point c, Point d, Point &p)
{


	const double EPSILON = 1E-8;
	Point t;
	double r, s;
	double denom, num1, num2;

	num1 = (a.y - c.y)*(d.x - c.x) - (a.x - c.x)*(d.y - c.y);
	num2 = (a.y - c.y)*(b.x - a.x) - (a.x - c.x)*(b.y - a.y);
	denom = (b.x - a.x)*(d.y - c.y) - (b.y - a.y)*(d.x - c.x);

	if (fabs(denom) >= EPSILON) {
		r = num1 / denom;
		s = num2 / denom;
		if (0 - EPSILON <= r && r <= 1 + EPSILON &&
			0 - EPSILON <= s && s <= 1 + EPSILON) {

			p.x = a.x + r*(b.x - a.x);
			p.y = a.y + r*(b.y - a.y);
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (fabs(num1) >= EPSILON) {
			return 0;
		}
		else {

			if (a.x > b.x || (a.x == b.x && a.y > b.y)) {
				t = a;
				a = b;
				b = t;
			}
			if (c.x > d.x || (c.x == d.x && c.y > d.y)) {
				t = c;
				c = d;
				d = t;
			}
			if (a.x == b.x) {

				if (b.y == c.y) {
					p = b;
					return 1;
				}
				else if (a.y == d.y) {
					p = a;
					return 1;
				}
				else if (b.y < c.y || d.y < a.y) {
					return 0;
				}
				else {
					return -1;
				}
			}
			else {
				if (b.x == c.x) {
					p = b;
					return 1;
				}
				else if (a.x == d.x) {
					p = a;
					return 1;
				}
				else if (b.x < c.x || d.x < a.x) {
					return 0;
				}
				else {
					return -1;
				}
			}

			return -1;
		}
	}
}
// returns true if ch is present in list
bool searcher::visitedCheck(std::vector< std::pair< int, int > > list, std::pair < int, int > ch)
{
	for (int x = 0; x < list.size(); x++)
	{
		if (list[x] == ch)
			return true;
	}
	return false;
}

//bool searcher::VisitedAll(std::vector < std::pair< int, int > >listOfPairs, std::vector< shape > shapeList)
//{
//	for (int x = 0; x < shapeList.size(); x++)
//	{
//		for (int y = 0; y < shapeList[x].shapePoints.size(); y++)
//		{
//			(!visitedCheck(listOfPairs, shapeList[x].shapePoints[y]))
//		}
//	}
//
//}

int searcher::currentshape(std::pair < int, int> p)
{
	for (int x = 0; x < field.size(); x++)
	{
		for (int y = 0; y < field[x].shapePoints.size(); y++)
		{
			if (field[x].shapePoints[y] == p)
				return x;
		}
	}
}