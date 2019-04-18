/*
Name: Saqibul Islam Chowdhury
CSCI 136
Lab Quiz 8
Instructor: Anoop Aroor

Write a function, which takes a string parameter, and returns the number of un-balanced blocks { } in it.
As it goes through the string, it must look for opening and closing curly braces to keep track of how many blocks are currently open.
In the end, if input was perfectly balanced, the return should be 0. If there are un-closed blocks, the return will be a positive integer.
If more blocks were closed than opened, the return will be a negative integer.

*/

#include <iostream>

using namespace std;

int countChar(string line);

int countChar(string line)
{
	int count = 0;

	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == '{')
		{
			count += 1;
		}
		else if (line[i] == '}')
		{
			count -= 1;
		}
	}

	return count;
}

int main()
{
	string line = " {}{{}} sd sd ";
	cout << countChar(line) << endl;
}
