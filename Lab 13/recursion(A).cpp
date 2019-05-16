/*
Name: Saqibul Chowdhury
CSCI 136
Instructor: Genady Maryash
Lab Instructor: Anoop Aroor
Lab 13A
This program includes a function
void printRange(int left, int right);
that prints all numbers in range left ≤   x   ≤ right, separated by spaces. 
*/

#include <iostream>

using namespace std;

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

int main()
{
	printRange(-2, 10);
}