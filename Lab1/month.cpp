/*

Author: Saqibul Chowdhury
Course: CSCI-136
Instructor: Anoop Aroor
Assignment: Lab1D

This program finds the number of days in a month

*/

#include <iostream>

using namespace std;

int main()
{
	int x = 0;
	int y = 0;
	int z = 0;

	cout << "Enter the year: "<< endl;
	cin >> x;

	cout << "Enter the month(1 - 12): "<< endl;
	cin >> y;


	if (x % 4 == 0)
	{	if (x % 100 == 0)
		{	if (x % 400 == 0)
			{	z = 1;
			}
			else
			{	z = 0;
			}
		}
		else
		{	z = 1;
		}
	}
	else
	{	z = 0;
	}


	if (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12)
	{	cout << "31 days" << endl;
	}
	else if (y == 4 || y == 6|| y == 9 || y == 11)
	{	cout << "30 days" << endl;
	}
	else if (y == 2)
	{	if (z == 1)
		{	cout << "29 days" << endl;
		}
		else
		{	cout << "28 days" << endl;
		}
	}
	else
	{	cout << "Please enter a valid year and month" << endl;
	}

}
