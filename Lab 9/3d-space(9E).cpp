/*
Name: Saqibul Islam Chowdhury
CSCI 136
Lab 9E
In this program, we add functions that create, delete,
and coordinate objects dynamically
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

double length(Coord3D *p); //Length from origin
//compare lengths
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2);
//change distance from origin based on velocity
void move(Coord3D *ppos, Coord3D *pvel, double dt);
// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z);
void deleteCoord3D(Coord3D *p);	// free memory

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

Coord3D* createCoord3D(double x, double y, double z)
{
	Coord3D * temp = new Coord3D;

	temp->x = x;
	temp->y = y;
	temp->z = z;

	return temp;
}

void deleteCoord3D(Coord3D *p)
{
	delete p;
}

int main() {
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
}

