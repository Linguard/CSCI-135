/*
Name: Saqibul Chowdhury
CSCI 136
Instructor: Genady Maryash
Lab Instructor: Anoop Aroor
Lab 13D
This program includes a function
bool isAlphanumeric(string s);
which returns true if all characters in the string are letters and digits,
otherwise returns false.
*/

#include <iostream>

using namespace std;

void printRange(int left, int right);
int sumRange(int left, int right);
int sumArray(int *arr, int size);
bool isAlphanumeric(string s);

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

int sumArray(int *arr, int size)
{
	int sum = 0;
	
	if (size == 0)
	{
		return sum;
	}
	else
	{
		sum = arr[size - 1] + sumArray(arr, size - 1);
		return sum;
	}
}

bool isAlphanumeric(string s)
{
	if (s.length() == 0)
	{
		return true;
	}
	else		// isalnum gives 2 for lowercase and 1 for uppercase
	{
		if (isalnum(s[0]) != 0 and isAlphanumeric(s.substr(1, s.length() - 1)) == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int main()
{
	cout << isAlphanumeric("ABCD") << endl;        // true (1)
	cout << isAlphanumeric("Abcd1234xyz") << endl; // true (1)
	cout << isAlphanumeric("KLMN 8-7-6") << endl;  // false (0)
}