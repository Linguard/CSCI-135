/*
Name: Saqibul Islam Chowdhury
CSCI 136
Instructor: Genday Maryash
Lab Instructor: Anoop Aroor
Lab 12D
This program implements the function vector<int> sumPairWise(vector<int> &v1, vector<int> &v2)
that returns a vector of integers whose elements
are the pairwise sum of the elements from the two vectors passed as arguments. 
If a vector has a smaller size that the other,
consider extra entries from the shorter vectors as 0.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2)
{
	vector<int> first = v1;
	vector<int> second = v2;
	vector<int> result;

	if (first.size() < second.size())
	{
		for (int i = 0; i < first.size() - second.size(); i++)
		{
			first.push_back(0);
		}
	}
	else if (first.size() > second.size())
	{
		for(int i = 0; i < second.size() - first.size(); i++)
		{
			second.push_back(0);
		}
	}
	
	for (int i = 0; i < first.size(); i++)
	{
		result.push_back(first[i] + second[i]);
	}
	return result;
}

int main()
{
	vector<int> a = {1, 2, 3, 4, 5};
	vector<int> b = {6, 7, 8};
	vector<int> c;
	
	c = sumPairWise(a, b);
	
	cout << a.size() << endl;
	cout << b.size() << endl;
	cout << c.size() << endl;
	cout << endl;
	
	for(int i = 0; i < c.size(); i++)
	{
		cout << c[i] << endl;
	}
}