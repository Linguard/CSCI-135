/*
Name: Saqibul Chowdhury
CSCI 136
Lab Instructor: Anoop Aroor
HW E6.7
The function void reverse() reverses the sequence of elements in an array
*/

void reverse(int array[], int SIZE)
{
	int reverse [SIZE];					//Creating an new array to store the reversed values
	int reverse_index = SIZE - 1;

	for (int i = 0; i < SIZE; i++)				//For every index in the array
	{
		reverse[reverse_index] = array[i];		//Put the value in the reverse array in the reverse order
		reverse_index--;
	}

	for (int x = 0; x < SIZE; x++)
	{
		array[x] = reverse[x];				//Put the values from the reverse array into the original array
	}
}


#include <iostream>

using namespace std;

int main()
{
	const int SIZE = 10;

	int numbers[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		numbers[i] = i;
	}

	reverse(numbers,SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		cout << numbers[i] << endl;
	}
}
