/*
Name: Saqibul Chowdhury
CSCI 136
Lab 5G
Lab Instructor: Anoop Aroor
This program defines a function
int largestTwinPrime(int a, int b);
that returns the largest twin prime in the range a ≤ N ≤ b
*/

#include <iostream>

using namespace std;

bool isPrime(int n);
bool isTwinPrime(int n);
int largestTwinPrime(int a, int b);

bool isPrime(int n)
{
	if (n <= 1)							//If n < 1 or n = 1, not a prime number
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
			if (n%x == 0 || n%(x + 2) == 0)				//If n is divisible by any number smaller than itself, not a prime number
			{
				return false;
			}
		}
	}
	return true;						//If n is not divisible than any number smaller than itself, it is prime number
}

bool isTwinPrime(int n)
{
	int n_plus_two = n + 2;				//Created 2 variables n_plus_two and n_minus_two
	int n_minus_two = n - 2;
	
	if (isPrime(n) == false)					//If n is not a prime number, it cant be a twin prime
	{
		return false;
	}
	else if (isPrime(n_plus_two) == true)		//if (n+2) or (n-2) are true, then return true
	{
		return true;
	}
	else if (isPrime(n_minus_two) == true)
	{
		return true;
	}
	else										//otherwise return false
	{
		return false;
	}
}

int largestTwinPrime(int a, int b)
{
	int largestNum = -1;						//If there are no twin primes, largestNum will return -1
	
	for(int x = a; x <= b; x++)					//The for loop is true for x >= a and x <= b
	{
		if (isTwinPrime(x) == true)				//If x is a Twin Prime
		{
			if (x > largestNum)					//and x is larger than largestNum,
			{
				largestNum = x;					//then save x in largestNum
			}
		}
	}
	return largestNum;							//Return the largest value we get
}

int main ()
{
	int a = 0;									//Initialize two variables
	int b = 0;

	cout << "Input two integer numbers: " << endl;
	cin >> a >> b;									//Save the inputs into the variables
	
	cout << largestTwinPrime(a, b) << endl;		//Print largestTwinPrime
}