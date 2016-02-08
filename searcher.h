#ifndef SEARCHER_H
#define SEARCHER_H
#include "shape.h"
#include <vector>
#include <cstdlib>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
// class searcher
// uses a search algorithm to find the fastest path from point a to point b

struct node
{
	long int cost;
	std::vector< std::pair< int, int > > best;
	bool noMoreOptions, GoalFound;
};

class searcher
{
public:
	searcher(int x, int y);
	shape* getShape() { return player; };
	//sets the coordingates for the field
	void setField(std::vector< shape >setter);
	void update();
	node AstarSearch(std::pair < int, int > currState, std::pair < int, int > goalState, int currentState, double cost, std::vector< std::pair < int, int >  > visited);
private:


	//functions
	bool intersect(std::pair< int, int > aa, std::pair< int, int > bb, std::pair< int, int > cc, std::pair< int, int > dd);
	int dist(std::pair< int, int > aa, std::pair< int, int > bb);
	bool validMove(std::pair< int, int > st, std::pair < int, int> shapeClosest);
	bool visitedCheck(std::vector< std::pair< int, int > > list, std::pair < int, int > ch);
	int currentshape(std::pair < int, int> p);
	//actions
	int pickclosestCoor(shape p);

	//variables
	int cost;
	shape *player;
	std::pair< int, int > start;
	std::pair< int, int > next;
	std::pair< int, int > endgoal;
	// cost per level of the tree, if you get a better one update it.
	std::vector< int > currentLowCost;
	int currentBest;
	std::vector< std::pair < int, int > > retTemp;
	std::vector< shape > field;
	std::vector< std::pair< int, int > >  goalstep;

	int currLoc, vertCount;
};


#endif