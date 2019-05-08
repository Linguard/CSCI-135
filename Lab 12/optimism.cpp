/*
Name: Saqibul Islam Chowdhury
CSCI 136
Instructor: Genday Maryash
Lab Instructor: Anoop Aroor
Lab 12B
This program implements the function vector<int> goodVibes(vector<int> v);
that, given a vector of integers, 
returns a vector with only the positive integers in the same order.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> goodVibes(vector<int> v)
{
	vector<int> positive;
	
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > 0)
		{
			positive.push_back(v[i]);
		}
	}
	return positive;
}

int main()
{
	vector<int> v1{1,2,-1,3,4,-1,6};
	vector<int> v2;
	
	v2 = goodVibes(v1);
	
	cout << v1.size() << endl;
	cout << v2.size() << endl;
	cout << endl;
	
	for(int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << endl;
	}
}