/*
Name: Saqibul Islam Chowdhury
CSCI 136
Instructor: Genday Maryash
Lab Instructor: Anoop Aroor
Lab 12A
This program includess a function called vector<int> makeVector(int n)
that returns a vector of n integers that range from 0 to n-1.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> makeVector(int n)
{
	vector<int> result;
	for (int i = 0; i < n; i++)
	{
		result.push_back(i);
	}
	return result;
}

int main()
{
	vector<int> v1;
	
	v1 = makeVector(11);
	
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
}