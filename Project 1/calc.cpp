/*
Name: Saqibul Chowdhury
CSCI 135
Instructor: Genady Maryash
Project 1B
*/

#include <iostream>

using namespace std;

int main() 
{
	int n = 0, x = 0;	//Initializing the variables
	char c = '0';		//Variable with character data type to read sign(+,-)

	cin >> n;		//Reading the first number in the file
	x = x + n;		//and adding it

	while (cin >> c >> n) {		//For the following numbers in the file,
		if (c == '-') {		//if the sign in front of them is negative,
			x = x - n;	//they will be subtracted
			}
		else {			//otherwise, they will be added
			x= x + n;
			}
	}

	cout << x << endl;		//Printing the final result
}
