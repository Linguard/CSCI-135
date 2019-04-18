/*
Name: Saqibul Chowdhury
CSCI 136
Instructor: Anoop Aroor
Lab 3A
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main()
{
	string date = " ", input = " ";
	double eastSt = 0, eastEl = 0;

	ifstream reservoir("Current_Reservoir_Levels.tsv");
	if (reservoir.fail())	{
		cerr << "File cannot be opened for reading." << endl;
		exit(1); //exit if failed to open the file
	}

	cout << "Enter date: ";
	cin >> input;

	string junk;		//new string variable
	getline(reservoir, junk);	//read one line from the file

	while(reservoir >> date >> eastSt)	{
		reservoir.ignore(INT_MAX, '\n');
		if (date == input) {
		cout << "East basin storage: " << eastSt << " billion gallons" << endl;
		}
	}

	reservoir.close();
}
