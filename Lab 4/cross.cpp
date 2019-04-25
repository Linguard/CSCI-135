/*
Name: Saqibul Chowdhury
CSCI 136
Lab 4C
Instructor: Anoop Aroor
This program asks the user to input the shape size, and prints a diagonal cross of that dimension.
*/

#include <iostream>

using namespace std;

int main()
{
	int size = 0;				//Initializing my input size
	int i = 0, x = 0;			//initializing variables
	
	cout << "Input size: ";		//Taking size from user and storing it
	cin >> size;

	int s1 = 0, s2 = size-1;
	cout << endl << "Shape:" << endl;

	if (size%2 == 0)	{
		for (x = 0; x < size + 1; x++) {
			if (x < size/2 - 1)	{
				for (i = 0; i < size; i++)	{
					if (i == s1 or i == s2)	{
						cout << "*";
					}
					else	{
						cout << " ";
					}
				}
				s1++;
				s2--;
				cout << endl;
			}
			else {
				for (i = 0; i < size; i++)	{
					if (i == s1 or i == s2)	{
						cout << "*";
					}
					else	{
						cout << " ";
					}
				}
				s1--;
				s2++;
				cout << endl;
			}
			
		}
	}
	else {
		for (x = -1; x < size; x++) {
			if (x < size/2 - 2)	{
				for (i = 0; i < size; i++)	{
					if (i == s1 or i == s2)	{
						cout << "*";
					}
					else	{
						cout << " ";
					}
				}
				s1++;
				s2--;
				cout << endl;
			}
			else {
				s1--;
				s2++;
				for (i = 0; i < size; i++)	{
					if (i == s1 or i == s2)	{
						cout << "*";
					}
					else	{
						cout << " ";
					}
				}
				cout << endl;
			}
			
		}
	}
}
