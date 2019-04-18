/*
Author: Saqibul Chowdhury
Course: CSCI-136
Instructor: Anoop Aroor
Assignment: Lab 2C
*/

//This program asks user to update an array with their own values

#include <iostream>

using namespace std;

int main ()
{
	int myData[10];			//Creating the array
	int x = 0, i = 0, v = 0;	//Initializing all the variables

	for (x = 0; x < 10; x++) {	//Setting all the elements in the array to 1
		myData[x] = 1;
	}	

	do {
		for (x = 0; x < 10; x++) {	//Printing out all the elements in the array 
			cout << myData[x] << " ";
		}

		cout << endl;

		cout << "Input index: ";	//Where in the array to put in
		cin >> i;

		cout << "Input value: ";	//What to put in
		cin >> v;

		if (i >= 0 and i < 10){
		myData[i] = v;
		}
		else {
			break;
		}
	}
	while (i >=0 and i < 10);		//Repeat when values are right
	
	cout << "Index out of range. Exit." << endl;	//When values are not right, print this 								and close

	return 0;
}
