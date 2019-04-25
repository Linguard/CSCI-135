/*
Name: Saqibul Chowdhury
CSCI 136
Lab 3D
Instructor: Anoop Aroor
This program asks the user to input two dates (earlier date then later date). The program then reports 
the West basin elevation for all days in the interval in the reverse chronological order.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main()
{
	string date= " ";
	string input1 = " ", input2 = " ";
	
	int i = 0,x = 0;
	
	double eastSt = 0, eastEl = 0, westSt = 0, westEl = 0;
	
	const int CAPACITY = 365;
	double values[CAPACITY];
	string dates[CAPACITY];

	ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
		cerr << "File cannot be opened for reading." << endl;
		exit(1); // exit if failed to open the file
	}

	string junk;        // new string variable
	getline(fin, junk); // read one line from the file and discard it
	
	cout << "Enter earlier date: ";
	cin >> input1;
	cout << "Enter later date: ";
	cin >> input2;
	cout << endl;

	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {	// this loop reads the file line-by-line extracting 5 values on each iteration 
		if (date >= input1 and date <= input2) {
			if (i < CAPACITY)	{
			values[i] = westEl;
			dates[i] = date;
			i++;
			}
		}
	}
	
	for (x = i; x >= 0; x = (x-1))	{
		cout << dates[x] << "  " << values[x] << " ft" << endl;
	}
}