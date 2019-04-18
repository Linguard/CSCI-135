/*
Author: Saqibul Chowdhury
Course: CSCI-136
Instructor: Anoop Aroor
Assignment: Lab 2A
*/

//This program asks user for a valid input and bothers them until they do and then returns its square

#include <iostream>

using namespace std;

int main ()
{
	int x = 0;	//Initializing a variable

	cout << "Please enter a number between 0 and 100: " << endl; //Initial input
	cin >> x;				//and storing it in memory

	while (x <= 0 or x >= 100)		//Instructions for validity
	{	cout << "Please enter a number between 0 and 100: " << endl;
		cin >> x;
	}

	cout << x*x << endl; //Return square of the number

}
