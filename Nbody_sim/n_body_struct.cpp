#include "general.h";
#include "Task.h"
#include <iostream>
Body update(Body p, float timestamp)
{
	p.velocity.x += timestamp*p.force.x / p.m;
	p.velocity.y += timestamp*p.force.y / p.m;
	p.velocity.z += timestamp*p.force.z / p.m;
	p.position.x += timestamp*p.velocity.x;
	p.position.y += timestamp*p.velocity.y;
	p.position.z += timestamp*p.velocity.z;
	return p;
}

Body resetForce(Body p)
{
	p.force.x = 0.0;
	p.force.y = 0.0;
	p.force.z = 0.0;
	return p;
}

void printParticle(Body p)
{
	printf("rx == %f ry == %f rz == %f\n vx == %f vy == %f vz == %f\n mass == %f\n", p.position.x, p.position.y, p.position.z, p.velocity.x, p.velocity.y, p.velocity.z, p.m);
}

//Add force to particle a by particle b
Body addForce(Body a, Body b)
{
	float EPS = 3E4;      // softening parameter (just to avoid infinities)
	float dx = b.position.x - a.position.x;
	float dy = b.position.y - a.position.y;
	float dz = b.position.z - a.position.z;
	float dist = sqrt(dx*dx + dy*dy + dz*dz);
	float F = (G * a.m * b.m) / (dist*dist + EPS*EPS);
	a.force.x += F * dx / dist;
	a.force.y += F * dy / dist;
	a.force.z += F * dz / dist;
	return a;

}