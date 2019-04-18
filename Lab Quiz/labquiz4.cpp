/*
Name: Saqibul Chowdhury
CSCI 136
Instructor: Anoop Aroor
Lab Quiz 4
This program opens a file stream to a file called "data.txt", which contains names of colors and their RGB values, like this:
red FF0000
blue 0000FF
yellow FFFF00
etc...
The program must print them on screen in a loop, then close the file stream.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	
	string s = "";

	ifstream data("data.txt");
	if (data.fail()) {
    		cerr << "The necessary text file is not present." << endl;
    		exit(1); // exit if failed to open the file
	}
	while(data >> s )	{
			cout << s << endl;
	}
	data.close();
}
