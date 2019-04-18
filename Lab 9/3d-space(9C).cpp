/*
Name: Saqibul Islam Chowdhury
CSCI 136
Lab 9C
Write a function
void move(Coord3D *ppos, Coord3D *pvel, double dt);
which gets the position and the velocity of an object and has to compute object’s new coordinates after the time interval dt. The function does not return any values, instead, it should update the object’s position ppos with its new position coordinates.
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
void move(Coord3D *ppos, Coord3D *pvel, double dt);

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
	if (length(p1) > length(p2))	//Dont use '&' cuz already pointers
	{
		return p1;	//Return address, not the value
	}
	else
	{
		return p2;
	}
}

void move(Coord3D *ppos, Coord3D *pvel, double dt)
{
	ppos->x = ppos->x + ((pvel->x) * dt);	//x = x + v(x).dt 
	ppos->y = ppos->y + ((pvel->y) * dt);	//y = y + v(y).dt 
	ppos->z = ppos->z + ((pvel->z) * dt);	//x = z + v(z).dt 
}

int main() {
	Coord3D pos = {0, 0, 100.0};
	Coord3D vel = {1, -5, 0.2};

	move(&pos, &vel, 2.0); // object pos gets changed
	cout << pos.x << " " << pos.y << " " << pos.z << endl;
	// prints: 2 -10 100.4
}


