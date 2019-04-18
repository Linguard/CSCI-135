/*
Name: Saqibul Chowdhury
CSCI 136
Lab 5A
Instructor: Anoop Aroor
This program that defines a function
bool isDivisibleBy(int n, int d);
If n is divisible by d, the function should return true, otherwise return false.
*/

#include <iostream>

using namespace std;

bool isDivisibleBy(int n, int d);		//Check whether 1st number is divisible by the second

bool isDivisibleBy(int n, int d)
{
	if (d == 0)				//Special case: N can not be divided by zero
	{
		return false;
	}
	else if (n%d == 0)			//If N is divisible by zero, return true
	{
		return true;
	}
	else
	{
		return false;			//Otherwise, return false
	}
}

int main ()
{
	int a = 0;
	int b = 0;

	cout << "Input two integer numbers: " << endl;
	cin >> a >> b;

	if (isDivisibleBy(a, b) == true)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}
