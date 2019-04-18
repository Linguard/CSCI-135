/*

Author: Saqibul Chowdhury
Course: CSCI-136
Instructor: Anoop Aroor
Assignment: Lab1A

This program finds the smaller of two integers
This program finds the smaller of two integers

*/

#include <iostream>

using namespace std;

int main()
{
	int x = 0;
	int y = 0;

	cout << "Enter the first number: "<< endl;
	cin >> x;

	cout << "Enter the second number: "<< endl;
	cin >> y;

	if (x < y) {
		cout << "The smaller number is " << x << endl;
	}
	else if (y < x) {
		cout << "The smaller number is " << y << endl;
	}
	else {
		cout << "The numbers are equal" << endl;
	}
}
