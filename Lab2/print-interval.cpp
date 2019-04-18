/*
Author: Saqibul Chowdhury
Course: CSCI-136
Instructor: Anoop Aroor
Assignment: Lab 2B
*/

//This program asks user for two integers and prints all the integers between them

#include <iostream>

using namespace std;

int main ()
{
	int L = 0;	//Initializing the variables
	int U = 0;

	cout << "Please enter the lower limit: " << endl; //Taking first input
	cin >> L;				//and storing it in memory

	cout << "Please enter the upper limit: " << endl; //Taking second input
	cin >> U;				//and storing it in memory

	for (int i = L;i < U; i++) {		//Instructions for writing integers
		cout << i << " ";		//Creating a space after each number and no endl
	}
	
	cout << endl;				//Creating a new line for the next program
}
