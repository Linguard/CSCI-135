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
#include <climits>

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
int getLumberCount(Dwarf & dwarf, int r, int c);
bool check_PreviousMax(int r, int c);
Lumber getMaxLumber_Location(Dwarf & dwarf);
void setLumber_Locations(Dwarf & dwarf);
bool isFenceOnMap(Dwarf & dwarf);

bool isNextToATree(Dwarf & dwarf, int r, int c)		// Checks if standing 1 space away from tree
{
	int x = r;
	int y = c;
	
	// Look if there is a tree on the right of the dwarf
	if (dwarf.look(x, y + 1) == PINE_TREE or dwarf.look(x, y + 1) == APPLE_TREE)
	{
		return true;
	}
	// Look if there is a tree on the left of the dwarf
	else if (dwarf.look(x, y - 1) == PINE_TREE or dwarf.look(x, y - 1) == APPLE_TREE)
	{
		return true;
	}
	// Look if there is a tree below the dwarf
	else if (dwarf.look(x + 1, y) == PINE_TREE or dwarf.look(x + 1, y) == APPLE_TREE)
	{
		return true;
	}
	// Look if there is a tree above the dwarf
	else if (dwarf.look(x - 1, y) == PINE_TREE or dwarf.look(x - 1, y) == APPLE_TREE)
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

int getLumberCount(Dwarf & dwarf, int r, int c)
{
	int lumber_count = 0;
	int locations[4][2] = {{r, c + 1}, {r, c - 1}, {r + 1, c}, {r - 1, c}};
	
	for (int i = 0; i < 4; i++)
	{
		if (dwarf.look(locations[i][0], locations[i][1]) == PINE_TREE)
		{
			lumber_count += 10;							// Pine trees give 10 lumber
		}
		else if (dwarf.look(locations[i][0], locations[i][1]) == APPLE_TREE)
		{
			lumber_count += 3;							// Apple trees give 3 lumber
		}
	}
	return lumber_count;
}

bool check_PreviousMax(int r, int c)
{
	for (size_t i = 0; i < Lumber_Locations.size(); i++)		// Change this to int at some point
	{
		if (Lumber_Locations[i].x == r and  Lumber_Locations[i].y == c)
		{
			return true;
		}
	}
	return false;
}

Lumber getMaxLumber_Location(Dwarf & dwarf)
{
	int count = 0;
	int maxcount = 0;
	Lumber Tree_Loc = {-1, -1};
	
	for (int i = 0; i <= ROWS; i++)
	{
		for (int j = 0; j <= COLS; j++)
		{
			if (dwarf.look(i, j) == EMPTY and isNextToATree(dwarf, i, j) == true)
			{
				count = getLumberCount(dwarf, i, j);		// Gets number of lumber available at that location
				if (count > maxcount and check_PreviousMax(i, j) == false)
				{
					maxcount = count;
					Tree_Loc.x = i;
					Tree_Loc.y = j;
				}
			}
		}
	}
	return Tree_Loc;
}

void setLumber_Locations(Dwarf & dwarf)
{
	Lumber temp = getMaxLumber_Location(dwarf);
	
	while (temp.x != -1 && temp.y != -1)
	{
		Lumber_Locations.insert(Lumber_Locations.begin(), temp);
	}
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
	
	setLumber_Locations(dwarf);
	
	// Only dwarf 5 will build fences
	if (dwarf.lumber() > 9 and dwarf.name() == 5)		//visual studio 
	{
		for (int i = 0; i <= ROWS; i++)
		{
			for (int j = 0; j <= COLS; j++)
			{
				if (isFenceOnMap(dwarf) == true)
				{
					if(isNextToAFence(dwarf, r, c) == true)
					{
						if (dwarf.look(r, c + 1) == EMPTY and dwarf.look(r, c + 2) == FENCE)
						{
							log << "Build a fence" << endl;
							dwarf.start_build(EAST);
							return;
						}
						else if (dwarf.look(r, c - 1) == EMPTY and dwarf.look(r, c - 2) == FENCE)
						{
							log << "Build a fence" << endl;
							dwarf.start_build(WEST);
							return;
						}
						else if (dwarf.look(r + 1, c) == EMPTY and dwarf.look(r + 2, c) == FENCE)
						{
							log << "Build a fence" << endl;
							dwarf.start_build(SOUTH);
							return;
						}
						else if (dwarf.look(r - 1, c) == EMPTY and dwarf.look(r - 2, c) == FENCE)
						{
							log << "Build a fence" << endl;
							dwarf.start_build(NORTH);
							return;
						}
					}
					else if (dwarf.look(i, j) == EMPTY and isNextToAFence(dwarf, i, j) == true)
					{
						log << "Dwarf " << dwarf.name() << " walking to " << i << " " << j << endl;
						dwarf.start_walk(i, j);
						return;
					}
				}
				else
				{
					if (dwarf.look(r, c + 1) == EMPTY)
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
					else if (dwarf.look(r - 1, c) == EMPTY)
					{
						log << "Build a fence" << endl;
						dwarf.start_build(NORTH);
						return;
					}
				}
			}
		}
	}
	
	// Look if there is a tree on the right of the dwarf
	if (dwarf.look(r, c + 1) == PINE_TREE or dwarf.look(r, c + 1) == APPLE_TREE)
	{
		// If there is a pine tree, chop it
		log << "Dwarf " << dwarf.name() << " found a tree -- chop" << endl;
		dwarf.start_chop(EAST);
		return;
	}
	// Look if there is a tree on the left of the dwarf
	else if (dwarf.look(r, c - 1) == PINE_TREE or dwarf.look(r, c - 1) == APPLE_TREE)
	{
		// If there is a pine tree, chop it
		log << "Dwarf " << dwarf.name() << " found a tree -- chop" << endl;
		dwarf.start_chop(WEST);
		return;
	}
	// Look if there is a tree below the dwarf
	else if (dwarf.look(r + 1, c) == PINE_TREE or dwarf.look(r + 1, c) == APPLE_TREE)
	{
		// If there is a pine tree, chop it
		log << "Dwarf " << dwarf.name() << " found a tree -- chop" << endl;
		dwarf.start_chop(SOUTH);
		return;
	}
	// Look if there is a tree above the dwarf
	else if (dwarf.look(r - 1, c) == PINE_TREE or dwarf.look(r - 1, c) == APPLE_TREE)
	{
		// If there is a pine tree, chop it
		log << "Dwarf " << dwarf.name() << " found a tree -- chop" << endl;
		dwarf.start_chop(NORTH);
		return;
	}
	
	Lumber walk_location = Lumber_Locations.back();	// Assign the last known value to the dwarf.
	Lumber_Locations.pop_back();					// Remove from vector so that it cannot be used by another dwarf.
	
	log << "Dwarf " << dwarf.name() <<  " walking to " << walk_location.x << " " << walk_location.y << endl;
	dwarf.start_walk(walk_location.x, walk_location.y);
	return;
}

/*
STATS:
Time needed to process a new command and display a message after chopping wood is completed = 3 minutes;
Time needed to process a new command and display a message after walking is completed = 6 minutes;
Time needed to chop 1 wood = 3 minutes;
Time needed to start walking after message is displated = 3 seconds;
Time needed to walk 1 square = 3 minutes;
Time needed to build 1 fence = ;
Time needed to pick 1 apple = ;
Time needed to pick 1 pumpkin = ;
*/