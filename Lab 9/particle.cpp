/*
Name: Saqibul Islam Chowdhury
CSCI 136
Lab 9F
Instructor: Anoop Aroor
This program declares a new class Particle, which
stores position and velocity of the particle, and
provides the following programming interface:

Particle* createParticle(double x, double y, double z, 
                         double vx, double vy, double vz);
void setVelocity(Particle *p, double vx, double vy, double vz);
Coord3D getPosition(Particle *p);
void move(Particle *p, double dt);
void deleteParticle(Particle *p);
*/

#include <iostream>
#include <cmath>

using namespace std;

class Particle {
public:
	double x;
	double y;
	double z;
	double vx;
	double vy;
	double vz;
};

class Coord3D {
public:
	double x;
	double y;
	double z;
};

// dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z, 
                         double vx, double vy, double vz);
// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz);
// get its current position
Coord3D getPosition(Particle *p);
// update particle's position after elapsed time dt
void move(Particle *p, double dt);
// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p);


// dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z, 
                         double vx, double vy, double vz)
{
	Particle * temp = new Particle;

	temp->x = x;
	temp->y = y;
	temp->z = z;
	temp->vx = vx;
	temp->vy = vy;
	temp->vz = vz;

	return temp;
}

// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz)
{
	p->vx = vx;
	p->vy = vy;
	p->vz = vz;
}

// get its current position
Coord3D getPosition(Particle *p)
{
	Coord3D point;
	point.x = p->x;
	point.y = p->y;
	point.z = p->z;

	return point;
}

// update particle's position after elapsed time dt
void move(Particle *p, double dt)
{
	p->x = p->x + ((p->vx) * dt);	//x = x + v(x).dt 
	p->y = p->y + ((p->vy) * dt);	//y = y + v(y).dt 
	p->z = p->z + ((p->vz) * dt);	//x = z + v(z).dt 
}

// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p)
{
	delete p;
}

int main()
{
	// make new particle
	Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
	double time = 0.0;
	double dt = 0.1;
	while(time < 3.0)
	{
		// update its velocity
		setVelocity(p, 10.0 * time, 0.3, 0.1);

		// move the particle
		move(p, dt);
		time += dt;

		// reporting its coordinates
		cout << "Time: " << time << " \t";
		cout << "Position: "
			<< getPosition(p).x << ", "
			<< getPosition(p).y << ", "
			<< getPosition(p).z << endl;
	}

	// remove the particle, deallocating its memory
	deleteParticle(p);
}

