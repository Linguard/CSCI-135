/*
Name: Saqibul Chowdhury
CSCI 136
Lab Instructor: Anoop Aroor
Lab 6B
Write a program caesar.cpp with functions implementing Caesar cipher encryption
*/

#include <iostream>
#include <string>

using namespace std;

char shiftChar(char c, int rshift);						// A helper function to shift one character by rshift
string encryptCaesar(string plaintext, int rshift);		// Caesar cipher encryption

char shiftChar(char c, int rshift)
{
	int x = int(c);							//Assigning an integer value to the character
	
	if( x >= 65 && x <= 90)					//For A - Z
	{
		x = x - 65;							//Subtracting from 65 to get in the 0-25 range
		x = (x + rshift)%26;				//Add the caesar shift and if it exceeds the bounds, wrap it around
		x = x + 65;							//Add the 65 to get the correct ASCII value
	}
	else if(x >=97 && x <= 122)				//for a - z
	{
		x = x - 97;							//Subtracting from 97 to get in the 0-25 range
		x = (x + rshift)%26;				//Add the caesar shift and if it exceeds the bounds, wrap it around
		x = x + 97;							//Add the 97 to get the correct ASCII value
	}
	
	return char(x);
}

string encryptCaesar(string plaintext, int rshift)
{
	string ciphertext = "";								//the line to be displayed
	
	for (int i = 0; i < plaintext.length();i++)
	{
		ciphertext += (shiftChar(plaintext[i], rshift));		//right-shift each character and append it to the string
	}
	
	return ciphertext;
}

int main()
{
	string plaintext;
	int shift;
	
	cout << "Enter Plaintext : ";
	getline(cin,plaintext);
	
	cout << "Enter shift     : ";
	cin >> shift;
	
	cout << "Ciphertext      : " << encryptCaesar(plaintext, shift) << endl;
}