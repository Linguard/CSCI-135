/*
Name: Saqibul Chowdhury
CSCI 136
Instructor: Anoop Aroor
Lab 3D
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main()
{
	int x = 0;
	string date = " ", input1 = " ", input2 = " ";
	double eastSt = 0, eastEl = 0, westSt = 0, westEl = 0;

	const int CAPACITY = 365;		//Creating an array called array with 365 spaces
	double values[CAPACITY];
	string dates[CAPACITY];
	int size = 0;
	double input;

	ifstream reservoir("Current_Reservoir_Levels.tsv");
	if (reservoir.fail())	{
		cerr << "File cannot be opened for reading." << endl;
		exit(1); //exit if failed to open the file
	}

	cout << "Enter earlier date: ";
	cin >> input1;

	cout << "Enter later date: ";
	cin >> input2;

	cout << endl;

	string junk;			//new string variable
	getline(reservoir, junk);	//read one line from the file and discare it

	while(reservoir >> date >> eastSt >> eastEl >> westSt >> westEl)	{
		if (date >= input1 && date <= input2)	{
			if (size < CAPACITY)	{
				values[size] = westEl;
				dates[size] = date;
				size++;
			}
		}
	}
	for (x = size; x >= 0; x = (x-1))	{

		cout << dates[x] << "  " << values[x] << " ft" << endl;

	}
	reservoir.close();
}
