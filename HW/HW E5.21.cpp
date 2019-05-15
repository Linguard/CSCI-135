/*
Name: Saqibul Chowdhury
CSCI 135
Instructor: Genady Maryash
HW E5.21
Write a recursive function
string reverse(string str);
that computes the reverse of a string.
For example, reverse("flow") should return "wolf".
Hint: Reverse the substring starting at the second character, then add the first character at the end.
For example, to reverse "flow", first reverse "low" to "wol", then add the "f" at the end.
*/

#include <iostream>
#include<string>

using namespace std;

string reverse(string str)
{
	string reverse_string;

	if (str.length() == 1)
	{
		return str;
	}
	else
	{
		char first = str[0];
		reverse_string = reverse(str.substr(1, str.length() - 1)) + first;
	}

	return reverse_string;
}

int main()
{
	string str1;

	cout << "Enter a string: ";
	cin >> str1;

	string str2 = reverse(str1);

	cout << str2;
}