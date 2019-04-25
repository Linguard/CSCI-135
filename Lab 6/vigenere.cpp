/*
Name: Saqibul Chowdhury
CSCI 136
Lab Instructor: Anoop Aroor
Lab 6C
This program contains a function encryptVigenere implementing this cipher:
string encryptVigenere(string plaintext, string keyword);
*/

#include <iostream>
#include <string>

using namespace std;

char shiftChar(char c, char char_keyword);						//
string encryptVigenere(string plaintext, string keyword);		// Vigenere cipher encryption

char shiftChar(char c, char char_keyword)
{
	int y = int(char_keyword);
	y = y - 97;
	
	int x = int(c);							//Assigning an integer value to the character
	
	if( x >= 65 && x <= 90)					//For A - Z
	{
		x = x - 65;							//Subtracting from 65 to get in the 0-25 range
		x = (x + y)%26;						//Add the vigenere shift and if it exceeds the bounds, wrap it around
		x = x + 65;							//Add the 65 to get the correct ASCII value
	}
	else if(x >=97 && x <= 122)				//for a - z
	{
		x = x - 97;							//Subtracting from 97 to get in the 0-25 range
		x = (x + y)%26;						//Add the vigenere shift and if it exceeds the bounds, wrap it around
		x = x + 97;							//Add the 97 to get the correct ASCII value
	}
	return char(x);
}

string encryptVigenere(string plaintext, string keyword)
{
	string ciphertext = "";
	char char_keyword = '0';
	int j = 0;
	
	for (int i = 0; i < plaintext[i]; i++)
	{
		int x = int(plaintext[i]);
		
		if((x >= 65 && x <= 90)	|| (x >=97 && x <= 122))
		{
			if (j < keyword.length())
			{
				char_keyword = keyword[j];
			}
			else
			{
				char_keyword = keyword[j%keyword.length()];
			}
		
			ciphertext += (shiftChar(plaintext[i], char_keyword));
			j++;
		}
		else
		{
			ciphertext += plaintext[i];
		}
	}
	return ciphertext;
}

int main()
{
	string plaintext;
	string keyword;
	
	cout << "Enter Plaintext : ";
	getline(cin,plaintext);
	
	cout << "Enter keyword   : ";
	cin >> keyword;
	
	cout << "Ciphertext      : " << encryptVigenere(plaintext, keyword) << endl;
}