/*
Name: Saqibul Chowdhury
CSCI 135
Instructor: Genady Maryash
HW E6.18
Write a function
vector<int> append(vector<int> a, vector<int> b)
that appends one vector after another.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> append(vector<int> a, vector<int> b);

vector<int> append(vector<int> a, vector<int> b)
{
	vector<int> result;
	
	result = a;
	
	for (int i = 0; i < b.size(); i++)
	{
		result.push_back(b[i]);
	}
	
	return result;
}

int main()
{
	vector<int> a = {1, 4, 9, 16};
	vector<int> b = {9, 7, 4, 9, 11};

	vector<int> c = append(a, b);

	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << endl;
	}
}