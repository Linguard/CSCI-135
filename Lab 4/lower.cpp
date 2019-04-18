/*
Name: Saqibul Chowdhury
CSCI 136
Lab 4C
Instructor: Anoop Aroor
This program prints the bottom-left half of a square, given the side length.
*/

#include <iostream>

using namespace std;

int main()
{
	int length = 0;			//Initializing my inputs width and height
	int i = 0, x = 0;			//initializing variables
	
	cout << "Input side length: ";		//Taking width from user and storing it
	cin >> length;

	cout << endl << "Shape:";

	for (x = -1; x < length; x++) {			//In each line(height), print the amount of asterisks equal to the width
		for (i = -1; i < x; i++)	{	//Putting width loop inside the height loop is the best way to finish the task
			cout << "*";
		}
		cout << endl;				//After each height loop is completed, create a new line
	}
}
