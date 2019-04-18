/*

Author: Saqibul Chowdhury
Course: CSCI-136
Instructor: Anoop Aroor
Assignment: Lab1B

This program finds the smaller of three integers

*/

#include <iostream>

using namespace std;

int main()
{
	int x = 0;
	int y = 0;
	int z = 0;

	cout << "Enter the first number: "<< endl;
	cin >> x;

	cout << "Enter the second number: "<< endl;
	cin >> y;

	cout << "Enter the third number: "<< endl;
	cin >> z;

	if (x == y && x == z)
	{	cout << "The numbers are equal" << endl;
	}
	else if (x < y)
	{	if (x < z)
		{	cout << "The smaller number is " << x << endl;
		}
		else 	{
			cout << "The smaller number is " << z << endl;
			}
	}
	else
	{	if (y < z)
		{	cout << "The smaller number is " << y << endl;
		}
		else 	{
			cout << "The smaller number is " << z << endl;
			}	
	}
}
