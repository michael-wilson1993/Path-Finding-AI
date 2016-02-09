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
	float cost;
	std::vector< std::pair< int, int > > best;
	bool noMoreOptions, GoalFound;
};

class searcher
{
public:
	searcher(int x, int y, int gx, int gy);
	shape* getShape() { return player; };
	//sets the coordingates for the field
	void setField(std::vector< shape >setter);
	void update();
	void startPlayer();
	void reset(int x, int y, int gx, int gy);
	node AstarSearch(std::pair < int, int > currState, std::pair < int, int > goalState, int currentState, double cost, std::vector< std::pair < int, int >  > visited);
	std::vector< std::pair< int, int > > getPath() {return goalstep;};
private:


	//functions
	bool intersect(std::pair< int, int > aa, std::pair< int, int > bb, std::pair< int, int > cc, std::pair< int, int > dd);
	float dist(std::pair< int, int > aa, std::pair< int, int > bb);
	bool validMove(std::pair< int, int > st, std::pair < int, int> go);
	bool visitedCheck(std::vector< std::pair< int, int > > list, std::pair < int, int > ch);
	int currentshape(std::pair < int, int> p);
	bool isInTheSameShape(std::pair< int, int> a, std::pair< int, int > b, int &one, int &two);


	//actions
	int pickclosestCoor(shape p);

	//variables
	int cost;
	shape *player;
	std::pair< int, int > start; // coordinate for the start of the search
	std::pair< int, int > next; // coordinate for the next spot to go to( this is for the animation)
	std::pair< int, int > endgoal; // coordinate for the goal for the search

	
	std::vector< int > currentLowCost; // cost per level of the tree, if you get a better one update it.
	std::vector< std::pair < int, int > > retTemp;
	std::vector< shape > field;
	std::vector< std::pair< int, int > >  goalstep;


	int goalsFound;
	int currLoc, vertCount;
};


#endif