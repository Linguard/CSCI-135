/*
Name: Saqibul Islam Chowdhury
CSCI 135
Instructor: Genady Maryash
Project 3A
Improve the program so that the dwarf collects lumber more efficiently
*/

#include <cstdlib>
#include <cmath>
#include <iostream>
#include "bot.h"
#include <vector>

using namespace std;

const int MAX_ROWS = 40;
const int MAX_COLS = 40;
const int MAX_NUM = 10;

int ROWS;  // global variables
int COLS;
int NUM;

struct Lumber{
	int x;
	int y;
};

vector<Lumber> Lumber_Locations;

/* onStart: 
An Initialization procedure called at the start of the game.
You can use it to initialize certain global variables, or do 
something else before the actual simulation starts.
Parameters:
	rows: number of rows
	cols: number of columns
	num:  number of dwarfs
	log:  a cout-like log */

void onStart(int rows, int cols, int num, std::ostream &log)
{
	log << "Start!" << endl; // Print a greeting message

	ROWS = rows; // Save values in global variables
	COLS = cols;
	NUM = num;
}

bool isNextToATree(Dwarf & dwarf, int r, int c);
bool isNextToAFence(Dwarf & dwarf, int r, int c);
int getTreeCount(Dwarf & dwarf, int r, int c);
void getLocation(Dwarf & dwarf, int maxtree_location[]);
bool isFenceOnMap(Dwarf & dwarf);

bool isNextToATree(Dwarf & dwarf, int r, int c)
{
	int x = r;
	int y = c;
	
	// Look if there is a tree on the right of the dwarf
	if (dwarf.look(x, y + 1) == PINE_TREE)		// Apple Trees?
	{
		return true;
	}
	// Look if there is a tree on the left of the dwarf
	else if (dwarf.look(x, y - 1) == PINE_TREE)
	{
		return true;
	}
	// Look if there is a tree below the dwarf
	else if (dwarf.look(x + 1, y) == PINE_TREE)
	{
		return true;
	}
	// Look if there is a tree above the dwarf
	else if (dwarf.look(x - 1, y) == PINE_TREE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isNextToAFence(Dwarf & dwarf, int r, int c)	// Checks if standing 2 spaces away from fence
{
	int x = r;
	int y = c;
	
	// Look if there is a tree on the right of the dwarf
	if (dwarf.look(x, y + 2) == FENCE)
	{
		return true;
	}
	// Look if there is a tree on the left of the dwarf
	else if (dwarf.look(x, y - 2) == FENCE)
	{
		return true;
	}
	// Look if there is a tree below the dwarf
	else if (dwarf.look(x + 2, y) == FENCE)
	{
		return true;
	}
	// Look if there is a tree above the dwarf
	else if (dwarf.look(x - 2, y) == FENCE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int getTreeCount(Dwarf & dwarf, int r, int c)
{
	int tree_count = 0;
	int locations[4][2] = {{r, c + 1}, {r, c - 1}, {r + 1, c}, {r - 1, c}};
	
	for (int i = 0; i < 4; i++)
	{
		if (dwarf.look(locations[i][0], locations[i][1]) == PINE_TREE)
		{
			tree_count++;
		}
	}
	return tree_count;
}

void getLocation(Dwarf & dwarf, int maxtree_location[])
{
	int count = 0;
	int maxcount = 0;
	int max_location_x = 0;
	int max_location_y = 0;
	
	for (int i = 0; i <= ROWS; i++)				// Ignore previous max_location ??
	{
		for (int j = 0; j <= COLS; j++)
		{
			if (isNextToATree(dwarf, i, j) == true)
			{
				count = getTreeCount(dwarf, i, j);
				if ( count > maxcount and dwarf.look(i, j) == EMPTY)
				{
					maxcount = count;
					max_location_x = i;
					max_location_y = j;
				}
			}
		}
	}
	
	maxtree_location[0] = max_location_x;
	maxtree_location[1] = max_location_y;
	
	return;
}

bool isFenceOnMap(Dwarf & dwarf)	// Checks for fence on map. Returns true if atleast 1 fence already on map
{
	for (int i = 0; i <= ROWS; i++)
	{
		for (int j = 0; j <= COLS; j++)
		{
			if (dwarf.look(i, j) == FENCE)
			{
				return true;
			}
		}
	}
	return false;
}

/* onAction: 
A procedure called each time an idle dwarf is choosing 
their next action.
Parameters:
	dwarf:   dwarf choosing an action
	day:     day (1+)
	hours:   number of hours in 24-hour format (0-23)
	minutes: number of minutes (0-59)
	log:     a cout-like log  */

void onAction(Dwarf &dwarf, int day, int hours, int minutes, ostream &log)
{
	// Get current position of the dwarf
	int r = dwarf.row();
	int c = dwarf.col();

	static int first_move = 0;
	
	if (dwarf.name() == 5)		//visual studio 
	{
		if (first_move == 0)
		{
			if (dwarf.look(ROWS/2, COLS/2) == EMPTY)
			
		for (int i = ROWS/2; i < 3*ROWS/2; i++)
		{
			if (dwarf.look(r + 1, c) == PINE_TREE)
			{
				// If there is a pine tree, chop it
				log << "Found a tree -- chop" << endl;
				dwarf.start_chop(SOUTH);
				return;
			}
			else if (dwarf.look(r + 1, c) == EMPTY)
			{
				log << "Build a fence" << endl;
				dwarf.start_build(SOUTH);
				return;
			}
			else if (dwarf.look(r + 1, c) == FENCE)
			{
				dwarf.start_walk(r+1, c);
				return;
			}
		}
	}
		/*	if (dwarf.look(r, c + 1) == PINE_TREE)
			{
				// If there is a pine tree, chop it
				log << "Found a tree -- chop" << endl;
				dwarf.start_chop(EAST);
				return;
			}
			// Look if there is a tree on the left of the dwarf
			else if (dwarf.look(r, c - 1) == PINE_TREE)
			{
				// If there is a pine tree, chop it
				log << "Found a tree -- chop" << endl;
				dwarf.start_chop(WEST);
				return;
			}
			// Look if there is a tree below the dwarf
			else if (dwarf.look(r + 1, c) == PINE_TREE)
			{
				// If there is a pine tree, chop it
				log << "Found a tree -- chop" << endl;
				dwarf.start_chop(SOUTH);
				return;
			}
			else if (dwarf.look(r, c + 1) == EMPTY)
			{
				log << "Build a fence" << endl;
				dwarf.start_build(EAST);
				return;
			}
		
			else if (dwarf.look(r, c - 1) == EMPTY)
			{
				log << "Build a fence" << endl;
				dwarf.start_build(WEST);
				return;
			}
			else if (dwarf.look(r + 1, c) == EMPTY)
			{
				log << "Build a fence" << endl;
				dwarf.start_build(SOUTH);
				return;
			}
		*/

		
	// Look if there is a tree on the right of the dwarf
	if (dwarf.look(r, c + 1) == PINE_TREE)
	{
		// If there is a pine tree, chop it
		log << "Found a tree -- chop" << endl;
		dwarf.start_chop(EAST);
		return;
	}
	// Look if there is a tree on the left of the dwarf
	else if (dwarf.look(r, c - 1) == PINE_TREE)
	{
		// If there is a pine tree, chop it
		log << "Found a tree -- chop" << endl;
		dwarf.start_chop(WEST);
		return;
	}
	// Look if there is a tree below the dwarf
	else if (dwarf.look(r + 1, c) == PINE_TREE)
	{
		// If there is a pine tree, chop it
		log << "Found a tree -- chop" << endl;
		dwarf.start_chop(SOUTH);
		return;
	}
	// Look if there is a tree above the dwarf
	else if (dwarf.look(r - 1, c) == PINE_TREE)
	{
		// If there is a pine tree, chop it
		log << "Found a tree -- chop" << endl;
		dwarf.start_chop(NORTH);
		return;
	}

	int maxtree_location[2] = {-1, -1};
	
	getLocation(dwarf, maxtree_location);
	
	log << "Walk to " << maxtree_location[0] << " " << maxtree_location[1] << endl;
	dwarf.start_walk(maxtree_location[0], maxtree_location[1]);
	return;
}