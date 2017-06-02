#include "n_body_struct.h"
#include "Task.h"

void Nbody_simple(Body particles[N], int numberofiterations)
{
	for (int k = 0; k < numberofiterations; k++) {
		for (int i = 0; i < N; i++)
		{
			particles[i] = resetForce(particles[i]);
			for (int j = 0; j < N; j++)
			{
				if (i != j)
				{
					particles[i] = addForce(particles[i], particles[j]);
				}

			}
		}
		//loop again to update the time stamp here
		for (int i = 0; i < N; i++)
		{
			particles[i] = update(particles[i], TIMESTAMP);
		}
	}
}