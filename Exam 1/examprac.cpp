#include <iostream>

using namespace std;

int sum(int a, int b, int c)	{

	int r = a + b + c;

	return r++;
}

int main ()
{

	int a = 10; int b = 10; int c = 10;

	cout << sum(a++, ++b, c++) << endl;	//++b = pre increment, a++ = post increment
}
