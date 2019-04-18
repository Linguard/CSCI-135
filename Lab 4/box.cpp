/*
Name: Saqibul Chowdhury
CSCI 136
Lab 4A
Instructor: Anoop Aroor
This program asks the user to input width and height and prints a solid rectangular box of the requested size using asterisks.
*/

#include <iostream>

using namespace std;

int main()
{
	int width = 0, height = 0;		//Initializing my inputs width and height
	int i = 0, x = 0;			//initializing variables
	
	cout << "Input width: ";		//Taking width from user and storing it
	cin >> width;

	cout << "Input height: ";		//Taking height from user and storing it
	cin >> height;

	cout << endl << "Shape:" << endl;

	for (x = 0; x < height; x++) {			//In each line(height), print the amount of asterisks equal to the width
		for (i = 0; i < width; i++)	{	//Putting width loop inside the height loop is the best way to finish the task
			cout << "*";
		}
		cout << endl;				//After each height loop is completed, create a new line
	}
}
