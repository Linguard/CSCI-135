/*
Name: Saqibul Chowdhury
CSCI 136
Instructor: Genady Maryash
Lab Instructor: Anoop Aroor
Lab 13C
This program includes a function
int sumArray(int *arr, int size);
which receives an array (as a pointer to its first element) and the size of the array,
and should return the sum of its elements.
The function itself should not do any new dynamic memory allocations.
*/

#include <iostream>

using namespace std;

void printRange(int left, int right);
int sumRange(int left, int right);
int sumArray(int *arr, int size);

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

int main()
{
	int size = 10;
	int *arr = new int[size]; // allocate array dynamically
	arr[0] = 12;
	arr[1] = 17;
	arr[2] = -5;
	arr[3] = 3;
	arr[4] = 7;
	arr[5] = -15;
	arr[6] = 27;
	arr[7] = 5;
	arr[8] = 13;
	arr[9] = -21;

	int sum1 = sumArray(arr, size); // Add all elements
	cout << "Sum is " << sum1 << endl;  // Sum is 43

	int sum2 = sumArray(arr, 5); // Add up first five elements
	cout << "Sum is " << sum2 << endl;  // Sum is 34

	delete[] arr;         // deallocate it
}