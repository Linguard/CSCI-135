/*
Name: Saqibul Chowdhury
CSCI 136
Lab Instructor: Anoop Aroor
Lab 6D
This program contains two functions that decrypt caesar cypher and vigenere cypher
*/

#include <iostream>
#include <string>

using namespace std;

char encryptCaesarChar(char c, int rshift);						// A helper function to shift one character by rshift
string encryptCaesar(string plaintext, int rshift);				// Caesar cipher encryption

char encryptVigenereChar(char c, char char_keyword);			// A helper function to shift one character by char_keyword
string encryptVigenere(string plaintext, string keyword);		// Vigenere cipher encryption

char decryptCaesarChar(char c, int rshift);
string decryptCaesar(string ciphertext, int rshift);			// Caesar cipher decryption

char decryptVigenereChar(char c, char char_keyword);
string decryptVigenere(string ciphertext, string keyword);		// Vigenere cipher decryption

char encryptCaesarChar(char c, int rshift)
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
		ciphertext += (encryptCaesarChar(plaintext[i], rshift));		//right-shift each character and append it to the string
	}
	
	return ciphertext;
}

char encryptVigenereChar(char c, char char_keyword)
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
		
			ciphertext += (encryptVigenereChar(plaintext[i], char_keyword));
			j++;
		}
		else
		{
			ciphertext += plaintext[i];
		}
	}
	return ciphertext;
}

char decryptCaesarChar(char c, int rshift)
{
	int x = int(c);							//Assigning an integer value to the character
	
	if( x >= 65 && x <= 90)					//For A - Z
	{
		x = x - 65;							//Subtracting from 65 to get in the 0-25 range
		x = (x - rshift + 26)%26;						//Add the caesar shift and if it exceeds the bounds, wrap it around
		x = x + 65;							//Add the 65 to get the correct ASCII value
	}
	else if(x >=97 && x <= 122)				//for a - z
	{
		x = x - 97;							//Subtracting from 97 to get in the 0-25 range
		x = (x - rshift + 26)%26;						//Add the caesar shift and if it exceeds the bounds, wrap it around
		x = x + 97;							//Add the 97 to get the correct ASCII value
	}
	
	return char(x);
}

string decryptCaesar(string ciphertext, int rshift)
{
	string plaintext = "";										//the line to be displayed
	
	for (int i = 0; i < ciphertext.length();i++)
	{
		plaintext += (decryptCaesarChar(ciphertext[i], rshift));		//right-shift each character and append it to the string
	}
	
	return plaintext;
}

char decryptVigenereChar(char c, char char_keyword)
{
	int y = int(char_keyword);
	y = y - 97;
	
	int x = int(c);							//Assigning an integer value to the character
	
	if( x >= 65 && x <= 90)					//For A - Z
	{
		x = x - 65;							//Subtracting from 65 to get in the 0-25 range
		x = (x - y + 26)%26;						//Add the vigenere shift and if it exceeds the bounds, wrap it around
		x = x + 65;							//Add the 65 to get the correct ASCII value
	}
	else if(x >=97 && x <= 122)				//for a - z
	{
		x = x - 97;							//Subtracting from 97 to get in the 0-25 range
		x = (x - y + 26)%26;						//Add the vigenere shift and if it exceeds the bounds, wrap it around
		x = x + 97;							//Add the 97 to get the correct ASCII value
	}
	return char(x);
}

string decryptVigenere(string ciphertext, string keyword)
{
	string plaintext = "";
	char char_keyword = '0';
	int j = 0;
	
	for (int i = 0; i < ciphertext[i]; i++)
	{
		int x = int(ciphertext[i]);
		
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
		
			plaintext += (decryptVigenereChar(ciphertext[i], char_keyword));
			j++;
		}
		else
		{
			plaintext += ciphertext[i];
		}
	}
	return plaintext;
}

int main()
{
	string code;
	int shift;

	cout << endl << "Enter Plaintext : ";
	getline(cin,code);
	
	cout << endl;
	cout << "= Caesar =" << endl;
	
	cout << "Enter shift     : ";
	cin >> shift;
	
	string caesar_code;
	caesar_code = encryptCaesar(code, shift);
	
	cout << "Ciphertext      : " << caesar_code << endl;
	cout << "Decrypted       : " << decryptCaesar(caesar_code, shift) << endl;
	
	cout << endl;
	
	cout << "= Vigenere =" << endl;
	
	string keyword;
	
	cout << "Enter keyword   : ";
	cin >> keyword;
	
	string vigenere_code;
	vigenere_code = encryptVigenere(code, keyword);
	
	cout << "Ciphertext      : " << vigenere_code << endl;
	cout << "Decrypted       : " << decryptVigenere(vigenere_code, keyword) << endl;
}
