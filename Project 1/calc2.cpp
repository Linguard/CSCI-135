/*
Name: Saqibul Chowdhury
CSCI 135
Instructor: Genady Maryash
Project 1C
*/

#include <iostream>

using namespace std;

int main() 
{
	int n = 0, x = 0;	//Initializing the variables
	char c = '0';	//Variable with character data type to read signs

	cin >> n;		//Reading the first number in the file
	x = x + n;		//and adding it

	while (cin >> c >> n) {		//For the following numbers in the file,
		if (c == '-') {		//if the sign in front of them is negative,
			x = x - n;	//they will be subtracted
			}
		else if (c == '+') {	//if the sign in front of them is positive,
			x = x + n;	//they will be added
			}
		else if (c == ';') {	//if the sign is a semi-colon(;)
			cout << x << endl;	//print the value and start a new line
			x = 0;		//Recalibrating the variable x
			x = x + n;	//and adding the next number in the queue to it so that 						the value is not lost
			}
		else {}
	}
	cout << x << endl;		//Printing the final result
}
