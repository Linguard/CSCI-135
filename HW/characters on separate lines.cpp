/*
Name: Saqibul Chowdhury
CSCI 135
Instructor: Genady Maryash
Homework 4.8
*/

#include <iostream>

using namespace std;

int main()
{

	string s = " ";		//Initializing the variables
	int x = 0, i = 0;

	cout << "Enter a word: ";	//Input
	cin >> s;			//and storage

	x = s.length();		//length of the string

	for (i = 0; i < x; i++)	{
		cout << s[i] << endl;
	}
}	