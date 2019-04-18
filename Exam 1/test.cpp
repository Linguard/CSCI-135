#include <iostream>

using namespace std;

int main() {
int x =0, y = 0;
x = 1;
y = x++;			//x = x + 1; y = x;
cout << x << " " << y << endl;

x= 1;
y = ++x;			//y = x; x = x + 1;
cout << x << " " << y << endl;

}


