/*
Name: Saqibul Chowdhury
CSCI 136
Instructor: Anoop Aroor
Lab 3C
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main()
{
	string date = " ", input1 = " ", input2 = " ";
	double eastSt = 0, eastEl = 0, westSt = 0, westEl = 0;

	ifstream reservoir("Current_Reservoir_Levels.tsv");
	if (reservoir.fail())	{
		cerr << "File cannot be opened for reading." << endl;
		exit(1); //exit if failed to open the file
	}

	cout << "Enter starting date: ";
	cin >> input1;

	cout << "Enter ending date: ";
	cin >> input2;

	string junk;		//new string variable
	getline(reservoir, junk);	//read one line from the file

	while(reservoir >> date >> eastSt >> eastEl >> westSt >> westEl)	{
		reservoir.ignore(INT_MAX, '\n');
		if (date >= input1 && date <= input2) {
			if (eastEl > westEl) {					//If eastEl > westEl, print East
				cout << date << " East" << endl;
				}
			else if (westEl > eastEl) {				//If westEl > eastEl, print West
				cout << date << " West" << endl;
				}
			else {							//Otherwise, print equal
				cout << date << " Equal" << endl;
				}
		}
		else {}

	}

	reservoir.close();
}
