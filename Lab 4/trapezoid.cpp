/*
Name: Saqibul Chowdhury
CSCI 136
Lab 4E
Instructor: Anoop Aroor
This program prints an upside-down trapezoid of given width and height.
*/

#include <iostream>

using namespace std;

int main()
{
	int width = 0, height = 0;			//Initializing my inputs width and height
	int i = 0, x = 0;					//initializing variables
	
	cout << "Input width: ";			//Taking width from user and storing it
	cin >> width;
	
	cout << "Input height: ";
	cin >> height;
	
	int spaces = 0, stars = width;

	cout << endl << "Shape:" << endl;

		for (x = 0; x < height; x++)	{				//In each line(height), print the amount of asterisks equal to the width
			for (i = 0; i < width; i++)		{		//Putting width loop inside the height loop is the best way to finish the task
				if (i < spaces)	{
					cout << " ";
				}
				else if (i < stars)	{
					cout << "*";
				}
				else	{
					cout << " ";
				}
			}
		spaces += 1;
		stars -= 2;
		cout << endl;							//After each height loop is completed, create a new line
	}
}
