/*
	- author: Michael Wilson
	- prof: Yllias Chali
	- school class: Artificial Intelligence 
	- class: searcher
	- description ** it is a class that finds the shortest path from point a to b through a field of obsticles **
	- Assignment 1
*/



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

/*
- node is a basic struct that contains a list of pairs , float cost,  and bool values noMoreOptions, GoalFound
- cost - will be the cost to take that path
- noMoreOptions - is true if there are no more options and the goal is not reachable
- GoalFound - is true if the goal is found and you are returning the path back
- best - contains the path this node is currently on.
*/
struct node
{
	float cost;
	std::vector< std::pair< int, int > > best;
	bool noMoreOptions, GoalFound;
};

class searcher
{
public:
	/*
	 - searcher(int x, int y, int gx, int gy);
	  - constructor for the player setting the start and goal for the search.
	*/
	searcher(int x, int y, int gx, int gy);
	/*
	 - shape* getShape();
	 - returns a pointer to the shape of the player
	*/
	shape* getShape() { return player; }; 
	/*
	 - void setField(std::vector< shape > setter)
	 - sets the field with a list of objects passed in as setter
	*/
	void setField(std::vector< shape >setter);
	/*
	 - void update();
	 - updates the players location and moves the shape accordingly
	*/
	void update();
	/*
	 - void startPlayer();
	 - starts the search algorith to find the shortest path
	*/
	void startPlayer();
	/*
	 - node searchDFS(std::pair < int, int > currState, std::pair < int, int > goalState, int currentState, double cost, std::vector< std::pair < int, int >  > visited);
	 - recursivly searches through the field to find the shortest path
	 - the search will only move along a shape or jump to another one
	*/
	node searchDFS(std::pair < int, int > currState, std::pair < int, int > goalState, int currentState, double cost, std::vector< std::pair < int, int >  > visited);
	/*
	 - std::vector< std::pair< int, int > > getPath() {return goalstep;}
	 - returns a vector of coordinates making up the shortest path.
	*/
	std::vector< std::pair< int, int > > getPath() {return goalstep;};
private:


	//functions
	/*
	 - bool intersect(std::pair< int, int > aa, std::pair< int, int > bb, std::pair< int, int > cc, std::pair< int, int > dd);
	 - checks if the line between aa to bb and cc to dd intersect with each other
	*/
	bool intersect(std::pair< int, int > aa, std::pair< int, int > bb, std::pair< int, int > cc, std::pair< int, int > dd);
	/*
	 - float dist(std::pair< int, int > aa, std::pair< int, int > bb);
	 - finds the distance between two points and returns the distance
	*/
	float dist(std::pair< int, int > aa, std::pair< int, int > bb);
	/*
	 - bool validMove(std::pair< int, int > st, std::pair < int, int> go);
	 - determines if the move between st and go is valid through the field
	 - returns true if it is valid, and false otherwise
	*/
	bool validMove(std::pair< int, int > st, std::pair < int, int> go);
	/*
	 - bool visitedCheck(std::vector< std::pair< int, int > > list, std::pair < int, int > ch);
	 - checks to see if ch is contatined in the list
	 - if ch is in list it will return true, else return false
	*/
	bool visitedCheck(std::vector< std::pair< int, int > > list, std::pair < int, int > ch);
	/*
	 - int currentshape(std::pair < int, int> p);
	 - returns what shape the vertice p belongs to.
	 - returns the index of what p belongs to in the field
	*/
	int currentshape(std::pair < int, int> p);
	/*
	 - bool isInTheSameShape(std::pair< int, int> a, std::pair< int, int > b, int &one, int &two);
	 - determines the a and b are in the same shape. 
	 - if they are in the same shape it will return true;
	 - if they are in seperate shapes it will return false and put the corrisponding shapes into one and two
	*/
	bool isInTheSameShape(std::pair< int, int> a, std::pair< int, int > b, int &one, int &two);

	//variables
	int cost; // cost that gets passed through recursive search
	shape *player; // is the shape of the player... you can change this in the constructor to what ever you want
	std::pair< int, int > start; // coordinate for the start of the search
	std::pair< int, int > next; // coordinate for the next spot to go to( this is for the animation)
	std::pair< int, int > endgoal; // coordinate for the goal for the search
	std::vector< int > currentLowCost; // cost per level of the tree, if you get a better one update it.
	std::vector< shape > field; // is the vector of shapes the make up the field of collidable objects.
	std::vector< std::pair< int, int > >  goalstep; // goalstep is steps it takes for the shortest path. 
	int currLoc; // stores the current location in the goalstey vector( to display the player moving... animation)
};


#endif