/*
Name: Saqibul Islam Chowdhury
CSCI 136
Lab 9A
This program finds the length and distance in 3D space
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

double length(Coord3D *p)
{
	double l = p->x;	//Dereferencing p and putting its x value in l
	double w = p->y;	//Dereferencing p and putting its y value in w
	double h = p->z;	//Dereferencing p and putting its z value in h
	double distance = sqrt(l*l + w*w + h*h);
	return distance;
}

int main()
{
	Coord3D pointP = {10, 20, 30};

	cout << length(&pointP) << endl;
}
