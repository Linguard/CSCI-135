/*
Name: Saqibul Chowdhury
CSCI 135
Instructor: Genady Maryash
HW E3.1
This program carries out the following tasks:
	Open a file with the name hello.txt.
	Store the message “Hello, World!” in the file.
	Close the file.
	Open the same file again.
	Read the message into a string variable and print it.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	string phrase = "Hello, World!";	//Creating a string to be put in the file
	string print = " ";			//Creating an empty string

	ofstream text;
	text.open("hello.text");		//Opening the file
	text << phrase << endl;			//String written onto file

	text.close();				//Closing the file

	ifstream text1("hello.txt");		//Opening the file again
	text1 >> print;				//Reading the file into a string variable

	cout << print << endl;			//Printing the string
}
