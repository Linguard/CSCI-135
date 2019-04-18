/*
Name: Saqibul Chowdhury
CSCI 136
Lab Quiz 5
Instructor: Anoop Aroor
This program prints a rectangle with 5 columns of 6 asterisks each, separated by 4 columns of spaces
*/

#include <iostream>

using namespace std;

int main() {

	int height = 6, width = 5;			//Defining the height and width of the column 

	int x = 0, y = 0;				//Defining necessary variables for the program

	for (x = 0; x < height; x++)	{		//Loop for the column
		for (y = 0; y < width; y++)	{	//Loop for the row
			cout << "*  ";			//Printing an asterisk and two spaces for each loop
		}
		cout << endl;				//Creating a new line after each row is finished printing
	}
}
