/*
Name: Saqibul Islam Chowdhury
CSCI 136
Lab 9B
This program receives the coordinates of two points (passed as pointers),
and returns the pointer of the point that is farther away from the origin.
*/

#include <iostream>
#include <cmath>	//For square root operations

using namespace std;

class Coord3D {
public:
    double x;
    double y;
    double z;
};

double length(Coord3D *p);
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2);

double length(Coord3D *p)
{
	double l = p->x;	//Dereferencing p and putting its x value in l
	double w = p->y;	//Dereferencing p and putting its y value in w
	double h = p->z;	//Dereferencing p and putting its z value in h
	double distance = sqrt(l*l + w*w + h*h);
	return distance;
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2)
{
	if (length(p1) > length(p2))
	{
		return p1;
	}
	else
	{
		return p2;
	}
}

int main()
{
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};

    cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl << endl;

    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
   
    cout << "ans = " << ans << endl; // So which point is farther?
}

