/*

Author: Saqibul Chowdhury
Course: CSCI-136
Instructor: Anoop Aroor
Assignment: Lab1C

This program finds the leap year

*/

#include <iostream>

using namespace std;

int main()
{
	int x = 0;

	cout << "Enter the year: "<< endl;
	cin >> x;

	if (x % 4 == 0)
	{	if (x % 100 == 0)
		{	if (x % 400 == 0)
			{	cout << x << " is a leap year" << endl;
			}
			else
			{	cout << x << " is a common year" << endl;
			}
		}
		else
		{	cout << x << " is a leap year" << endl;
		}
	}
	else
	{	cout << x << " is a common year" << endl;
	}
}
