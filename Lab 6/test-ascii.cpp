/*
Name: Saqibul Chowdhury
CSCI 136
Lab Instructor: ANoop Aroor
This program asks the user to input a line of text (which may possibly include spaces). 
The program should report all characters from the input line together with their ASCII codes.
*/

#include <iostream>

using namespace std;

int char_to_ascii(char c);				//Function to convert characters to ascii
void string_to_ascii(string s);				//Function to convert characters to ascii

int char_to_ascii(char c)
{
	int ascii;

	ascii = int(c);					//Converts characters to their respective ASCII code

	return ascii;
}

void string_to_ascii(string s)
{
	for (int i = 0; i < s.length();i++)
	{
		cout << s[i] << " " << char_to_ascii(s[i]) << endl;
	}
}

int main()
{
	string message;

	cout << "Input: ";
	getline (cin, message);				//Use getline, otherwise stops at "space"

	string_to_ascii(message);
}
