/*
Name: Saqibul Chowdhury
CSCI 135
Instructor: Genady Maryash
HW E6.21
Write a function that modifies a vector<string>,
moving all strings starting with an upper case letter to the front,
without otherwise changing the order of the elements.
*/

#include <iostream>
#include <vector>

using namespace std;
vector<string> append(vector<string> a, vector<string> b);
vector<string> uppercase_front(vector<string> a);

vector<string> append(vector<string> a, vector<string> b)
{
	vector<string> result;
	
	result = a;
	
	for (int i = 0; i < b.size(); i++)
	{
		result.push_back(b[i]);
	}
	
	return result;
}

vector<string> uppercase_front(vector<string> a)
{
	vector<string> result;
	vector<string> upper;
	vector<string> lower;
	
	string temp;
	
	for (int i = 0; i < a.size(); i++)
	{
		temp = a[i];
		
		if (int(temp[0]) >= 65 and int(temp[0]) <= 90)
		{
			upper.push_back(a[i]);
		}
		else
		{
			lower.push_back(a[i]);
		}
	}

	result = append(upper, lower);
	
	return result;
}

int main()
{
	vector<string> names = {"ham", "Juice", "weird", "Boy", "Harry", "james", "rascal"};
	
	names = uppercase_front(names);

	for (int i = 0; i < names.size(); i++)
	{
		cout << names[i] << endl;
	}
}