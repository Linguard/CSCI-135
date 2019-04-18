/*
Name: Saqibul Chowdhury
CSCI 136
Lab Instructor: ANoop Aroor
This program asks the user to input a line of text (which may possibly include spaces). 
The program should report all characters from the input line together with their ASCII codes.
*/

#include <iostream>

using namespace std;

int main()
{
	string message;

	cout << "Input: ";
	getline (cin, message);				//Use getline, otherwise stops at "space"

	for (int i = 0; i < message.length();i++)	//Instead of writing 2 functions I could have just used this for loop from the beginning
	{
		cout << message[i] << " " << int(message[i]) << endl;
	}
}
