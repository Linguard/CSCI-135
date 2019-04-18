/*
Name: Saqibul Chowdhury
CSCI 136
Lab 5D
Instructor: Anoop Aroor
This program that defines a function
int countPrimes(int a, int b);
that returns the number of prime numbers in the interval a ≤ x ≤ b
*/

#include <iostream>

using namespace std;

bool isDivisibleBy(int n, int d);		//Check whether 1st number is divisible by the second
bool isPrime(int n);				//Check if prime or not
int nextPrime(int n);				//Find smallest prime greater than n
int countPrimes(int a, int b);			//Returns number of prime numbers in the interval a ≤ x ≤ b

bool isDivisibleBy(int n, int d)
{
	if (d == 0)
	{
		return false;
	}
	else if (n%d == 0)
	{
		return true;
	}
	else
	{
		return false;
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

int nextPrime(int n)
{
	int x = n + 1;					//x has to be larger than n
	
	while (true)					//Infinite loop
	{
		if (isPrime(x) == true)			//If x is a prime number, return the number
		{								
			return x;
		}
	x++;						//Increment after each loop
	}
}

int countPrimes(int a, int b)
{
	int count = 0;
	
	for(int x = a; x<=b; x++)			//For x >= a and x <= b,
	{
		if(isPrime(x) == true)			//Find all prime numbers
		{
			count++;			//If x is a prime number, add it to the count
		}
	}
	return count;
}

int main ()
{
	int a = 0;
	int b = 0;
	
	cout << "Input two integer numbers: " << endl;
	cin >> a >> b;

	cout << countPrimes(a, b) << endl;
}
