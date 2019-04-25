/*
Name: Saqibul Chowdhury
CSCI 136
Lab 4B
Instructor: Anoop Aroor
This program asks the user to input width and height and prints a rectangular checkerboard of the requested size using asterisks and spaces (alternating).
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

	for (x = 0; x < height; x++) {
		if (x%2 == 0)	{				//If the line is even, the line starts with a (space)
			for (i = 0; i < width; i++)	{
				if (i%2 == 0)	{
					cout << "*";
				}
				else	{
					cout << " ";
				}
			}
		}
		else {
			for (i = 0; i < width; i++)	{	//Ifthe line is odd, the asterisk goes first
				if (i%2 == 0)	{
					cout << " ";
				}
				else	{
					cout << "*";
				}
			}
		}
		cout << endl;				//After each height loop is completed, create a new line
	}
}
