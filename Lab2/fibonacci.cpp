/*
Author: Saqibul Chowdhury
Course: CSCI-136
Instructor: Anoop Aroor
Assignment: Lab 2D
*/

//This program uses an array to compute and print all Fibonacci numbers from F(0) to F(59)

#include <iostream>

using namespace std;

int main ()
{
	int fib[60];			//Creating the array
	fib[0] = 0;			//Inputting the first two values in the array
	fib[1] = 1;
	int x = 0;			//Initializing the variable

	for (x = 2; x < 60; x++) {	//Calculating the values of the other elements in the array
		fib[x] = fib[x - 1] + fib[x - 2];
	}

	for (x = 0; x < 60; x++) {	//Printing out all the elements in the array 
		cout << fib[x] << endl;
	}

	cout << endl;
}

/*
As the numbers in the array reach 2 billion, they start to exhibit strange behavior. Some of the numbers are negative. Almost none of the numbers reach 2 billion but one number did reach 2.14 billion. The reason for this behavior is int only has 4 bytes. So, it can't reach any value higher than than 2^31. 
*/
