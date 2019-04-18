#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	int b = 33;

	cout << &a << endl;

	int *ptr;

	ptr = &a;

	cout << ptr << endl;
	cout << *ptr << endl;

	ptr = &b;

	cout << ptr << endl;
	cout << *ptr << endl;
}
