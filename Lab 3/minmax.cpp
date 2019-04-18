/*
Name: Saqibul Chowdhury
CSCI 136
Instructor: Anoop Aroor
Lab 3B
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main()
{
	string date = " ";
	double eastSt = 0, min = INT_MAX, max = 0;	//INT_Max is the highest u can go. u need <climits> library tho

	ifstream reservoir("Current_Reservoir_Levels.tsv");	//Reading the file containing the values
	if (reservoir.fail())	{
		cerr << "File cannot be opened for reading." << endl;
		exit(1); //exit if failed to open the file
	}

	string junk;		//new string variable
	getline(reservoir, junk);	//read one line from the file

	while(reservoir >> date >> eastSt)	{
		reservoir.ignore(INT_MAX, '\n');
		while (eastSt > max)	{		//When max gets any value larger than itself, it saves it in its memory
			max = eastSt;
			}
		while (eastSt < min)	{		//When min gets any number smaller than itself, it saves it in its memory
			min = eastSt;
			}
	}

	cout << "Minimum storage in East basin: " << min << " billion gallons" << endl;
	cout << "Maximum storage in East basin: " << max << " billion gallons" << endl;

	reservoir.close();			//Close the file
}
