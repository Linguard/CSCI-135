/*
Name: Saqibul Chowdhury
CSCI 136
Lab Instructor: Anoop Aroor
Lab 7B
This program reads input from cin and prints out each input line with leading spaces removed.
It also reads the input line by line and counts the number of open and closed { } in it, 
and keep track of how many blocks is currently open at the beginning of each line.
It then adds that number of tabs at the beginning of each line.
*/

#include <iostream>
#include <string>

using namespace std;

string removeLeadingSpaces(string line);			//This function removes the leading whitespace
int countChar(string line, char c);					//This function calculates tabs

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

int countChar(string line, char c)
{
	int count = 0;
	
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == c)
		{
			count += 1;
		}
	}
	return count;
}

int main()
{
	int tabs = 0;
	string badcode;
	
	while (getline(cin, badcode))
	{
		string goodcode = removeLeadingSpaces(badcode);

		if (goodcode[0] == '}')
		{
			tabs = tabs - 1;
		}
		
		for (int i = 0; i < tabs; i++)
		{
			cout << '\t';
		}
		
		cout << goodcode << endl;
		
		tabs = tabs + countChar(badcode, '{');				//Increase tabs by how many '{' there are
		tabs = tabs - countChar(badcode, '}');				//Decrease tabs by how many '}' there are
	}
}