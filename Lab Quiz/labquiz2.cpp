/*
Author: Saqibul Chowdhury
Course: CSCI-136
Instructor: Anoop Aroor
Assignment: Lab Quiz 2
*/

//This program asks the user to input two integer numbers and prints out the larger of the two

#include <iostream>

using namespace std;

int main ()
{
	int first = 0;	//Initalizing the variables
	int second = 0;

	cout << "Enter the first number: " << endl;	//Taking first input
	cin >> first;			//and storing it

	cout << "Enter the second number: " << endl;	//Taking second input
	cin >> second;			//and storing it

	if (first > second) {		//If first is greater than second, print first
		cout << "The larger of the two is " << first << endl;
	}
	else {				//else print second
		cout << "The larger of the two is " << second << endl;
	}
}
