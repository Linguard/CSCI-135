/*
Name: Saqibul Chowdhury
CSCI 136
Instructor: Anoop Aroor
Lab Quiz 3
*/

//Write a program that creates an array of 10 integers, fills all its cells with values 1 through 10 (using a for loop), and prints all elements of the array on the screen.

#include <iostream>

using namespace std;

int main ()
{
	int array[10];			//Creating the array
	int x = 0;			//Initializing all the variables

	for (x = 0; x < 10; x++) {	//Setting all the elements in the array to 1
		array[x] = x + 1;
	}

	for (x = 0; x < 10; x++) {	//Printing out all the elements in the array 
		cout << array[x] << " ";
	}

	cout << endl;
}

