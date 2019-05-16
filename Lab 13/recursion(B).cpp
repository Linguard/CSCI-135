/*
Name: Saqibul Chowdhury
CSCI 136
Instructor: Genady Maryash
Lab Instructor: Anoop Aroor
Lab 13B
This program includes a function
int sumRange(int left, int right);
that computes the sum of all numbers in range left ≤   x   ≤ right.
*/

#include <iostream>

using namespace std;

void printRange(int left, int right);
int sumRange(int left, int right);

void printRange(int left, int right)
{
	if (left > right)
	{
		return;
	}
	else
	{
		cout << left << " ";
		printRange(left + 1, right);
		return;
	}
}

int sumRange(int left, int right)
{
	int sum = 0;
	
	if (left > right)
	{
		return sum;
	}
	else
	{
		sum = left + sumRange(left + 1, right);
		return sum;
	}
}

int main()
{
	int x = sumRange(1, 3);
	cout << "This is " << x << endl;   // 6

	int y = sumRange(-2, 10);
	cout << "That is " << y << endl;   // 52
}