/*
Name: Saqibul Chowdhury
CSCI 136
Lab Instructor: Anoop Aroor
Lab 7A
This program reads input from cin and prints out 
each input line with leading spaces removed
*/

#include <iostream>
#include <string>

using namespace std;

string removeLeadingSpaces(string line);			//This function removes the leading whitespace

string removeLeadingSpaces(string line)
{
	string goodcode;
	int len = line.length();
	char c;
	for (int i = 0; i < len; i++)
	{
		c = line[i];
		if (!isspace(c))
		{
			
			goodcode = line.substr(i, len);
			return goodcode;
		}
	}
}

int main()
{
	string badcode;
	
	while (getline(cin, badcode))
	{
		cout << removeLeadingSpaces(badcode) << endl;
	}
}
