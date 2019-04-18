/*
Name: Saqibul Chowdhury
CSCI 136
Lab 5B
Instructor: Anoop Aroor
This program defines a function
bool isPrime(int n);
The function should return true if n is a prime, otherwise return false
*/

#include <iostream>

using namespace std;

bool isDivisibleBy(int n, int d);		//Check whether 1st number is divisible by the second
bool isPrime(int n);				//Check if prime or not

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

bool isPrime(int n)
{
	if (n <= 1)
	{
		return false;
	}
	else if (n == 2 || n == 3)
	{
		return true;
	}
	else if (n%2 == 0 || n%3 == 0)
	{
		return false;
	}
	else
	{
		for (int x = 5; x*x < n; x = x + 6)
		{
			if (n%x == 0 || n%(x + 2) == 0)
			{
				return false;
			}
		}
	}
	return true;
}

int main ()
{

	int a = 0;

	cout << "Input two integer numbers: " << endl;
	cin >> a;

	
	if (isPrime(a) == true)
	{								//If n is a prime number, its true
		cout << "true" << endl;
	}
	else
	{								//If n is not a prime number, its false
		cout << "false" << endl;
	}
}
