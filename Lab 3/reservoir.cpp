/*
Name: Saqibul Chowdhury
CSCI 136
Instructor: Anoop Aroor
Lab 3
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main()
{
	string date = " ";
	double eastSt = 0, eastEl = 0, westSt = 0, westEl = 0;

	ifstream reservoir("Current_Reservoir_Levels.tsv");
	if (reservoir.fail())	{
		cerr << "File cannot be opened for reading." << endl;
		exit(1); //exit if failed to open the file
	}

	string junk;		//new string variable
	getline(reservoir, junk);	//read one line from the file

	while(reservoir >> date >> eastSt >> eastEl >> westSt >> westEl)	{
		reservoir.ignore(INT_MAX, '\n');
		cout << date << " " << eastSt << endl;
	}

	reservoir.close();
}
