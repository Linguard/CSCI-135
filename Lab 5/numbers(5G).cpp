/*
Name: Saqibul Chowdhury
CSCI 136
Lab 5G
Instructor: Anoop Aroor
This program that defines a function
int largestTwinPrime(int a, int b);
that returns the largest twin prime in the range a ≤ N ≤ b
*/

#include <iostream>

using namespace std;

bool isDivisibleBy(int n, int d);		//Check whether 1st number is divisible by the second
bool isPrime(int n);				//Check if prime or not
int nextPrime(int n);				//Find smallest prime greater than n
int countPrimes(int a, int b);			//Returns number of prime numbers in the interval a ≤ x ≤ b
bool isTwinPrime(int n);			//Checks if twin prime or not
int nextTwinPrime(int n);			//Find smallest twin prime greater than n
int largestTwinPrime(int a, int b);		//Finds largest twin prime in range a ≤ N ≤ b

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

bool isTwinPrime(int n)
{
	int n_plus_two = n + 2;				//Created 2 variable n_plus_2 and n_minus_2
	int n_minus_two = n - 2;
	
	if (isPrime(n) == false)
	{
		return false;
	}
	else if (isPrime(n_plus_two) == true)		//if (n+2) or (n-2) are true then return true; otherwise return false
	{
		return true;
	}
	else if (isPrime(n_minus_two) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int nextTwinPrime(int n)
{
	int x = n + 1;					//x has to be greater than n
	
	while (true)					//infinite loop
	{
		if (isTwinPrime(x) == true)
		{
			return x;
		}
	x++;						//Incrementing each loop
	}
}

int largestTwinPrime(int a, int b)
{
	int largest = -1;				//If no twin primes, return -1
	
	for(int x = a; x <= b; x++)
	{
		if (isTwinPrime(x) == true)		//If x is a twin prime
		{
			if (x > largest)		//And x is larger than largest
			{
				largest = x;		//Store x in largest
			}
		}
	}
	return largest;
}

int main ()
{
	int a = 0;
	int b = 0;

	cout << "Input two integer numbers: " << endl;
	cin >> a >> b;
	
	cout << largestTwinPrime(a, b) << endl;
}
