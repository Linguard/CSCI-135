/*
Name: Saqibul Chowdhury
CSCI 136
Lab 4E
Instructor: Anoop Aroor
This program prints the top-right half of a square, given the side length.
*/

#include <iostream>

using namespace std;

int main()
{
	int length = 0;							//Initializing my inputs width and height
	int i = 0, x = 0;						//initializing variables
	
	cout << "Input side length: ";			//Taking width from user and storing it
	cin >> length;

	int st = length;

	cout << endl << "Shape:" << endl;

	for (x = 0; x < length; x++)
	{											//In each line(height), print the amount of asterisks equal to the width
		for (i = length; i > 0; i--)
		{										//Putting width loop inside the height loop is the best way to finish the task
			if (i <= st)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
	cout << endl;							//After each height loop is completed, create a new line
	st--;
	}
}