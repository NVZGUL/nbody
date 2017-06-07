#include <iostream>
#include <ctime>
#include <math.h>
#include "general.h"
#include "Task.h"
#include "Simple.h"
#include "Nbody_thread.h"
#include "Nbody_openMP.h"

using namespace std;

float3 getPoint(float r) 
{
	const float
		phi = rand(PI_M2),
		sintheta = rand(-1.f, 1.f),
		costheta = std::sqrt(1.f - sintheta*sintheta);

	float3 point{
		r * std::cos(phi) * sintheta,
		r * std::sin(phi) * sintheta,
		r * costheta
	};

	return point;
}

int main()
{
	Body particles[N];
	Body test;
	test.position = getPoint(1.00);
	//randomly generating N Particles

	for (int i = 0; i < N; i++) {
		float rx = float(1e18*exp(-1.8)*(.5 - rand()));
		float3 point = getPoint(rx);
		particles[i].position.x = point.x;
		particles[i].position.y = point.y;
		particles[i].position.z = point.z;
		float vx = float(1e18*exp(-1.8)*(.5 - rand()));
		particles[i].velocity.x = vx;
		float vy = float(1e18*exp(-1.8)*(.5 - rand()));
		particles[i].velocity.y = vy;
		float vz = float(1e18*exp(-1.8)*(.5 - rand()));
		particles[i].velocity.z = vz;
		float mass = float(1.98892e30*rand() * 10 + 1e20);
		particles[i].m = mass;
	}

	int numberofiterations = 800;
	clock_t start = clock();
	//Nbody_simple(particles, numberofiterations);
	//Nbody_thread(particles, numberofiterations);
	Nbody_openMP(particles, numberofiterations);
	clock_t end = clock();
	std::cout << "time is: " << (float)(end - start) / CLOCKS_PER_SEC << std::endl;

	return 0;
}