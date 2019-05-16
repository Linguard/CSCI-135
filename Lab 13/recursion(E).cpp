/*
Name: Saqibul Chowdhury
CSCI 136
Instructor: Genady Maryash
Lab Instructor: Anoop Aroor
Lab 13E
This program includes a function
bool nestedParens(string s);
which returns true if the string is a sequence of nested parentheses
*/

#include <iostream>

using namespace std;

void printRange(int left, int right);
int sumRange(int left, int right);
int sumArray(int *arr, int size);
bool isAlphanumeric(string s);
bool nestedParens(string s);

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

bool nestedParens(string s)
{
	if (s.length() == 0)
	{
		return true;
	}
	else
	{
		if (s[0] == '('  and s[s.length() - 1] == ')')
		{
			if (nestedParens(s.substr(1, s.length() - 2)) == true)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
}

int main()
{
	cout << nestedParens("((()))") << endl;      // true (1)
	cout << nestedParens("()") << endl;          // true (1)
	cout << nestedParens("") << endl;            // true (1)

	cout << nestedParens("(((") << endl;         // false (0)
	cout << nestedParens("(()") << endl;         // false (0)
	cout << nestedParens(")(") << endl;          // false (0)
	cout << nestedParens("a(b)c") << endl;       // false (0)
}