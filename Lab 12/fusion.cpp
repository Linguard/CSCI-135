/*
Name: Saqibul Islam Chowdhury
CSCI 136
Instructor: Genday Maryash
Lab Instructor: Anoop Aroor
Lab 12C
This program implements the function void gogeta(vector<int> &goku, vector<int> &vegeta)
that appends elements of the second vector into the first and empties the second vector.
*/

#include <iostream>
#include <vector>

using namespace std;

void gogeta(vector<int> &goku, vector<int> &vegeta)
{
	vector<int> result;
	
	result = goku;
	
	for (int i = 0; i < vegeta.size(); i++)
	{
		result.push_back(vegeta[i]);
	}

	goku = result;
	vegeta.clear();
}

int main()
{
	vector<int> a = {1, 2, 3, 4, 5};
	vector<int> b = {6, 7, 8, 9, 10};
	
	gogeta(a, b);
	
	cout << a.size() << endl;
	cout << b.size() << endl;
	cout << endl;
	
	for(int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
}