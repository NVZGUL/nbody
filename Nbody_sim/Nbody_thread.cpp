#include "n_body_struct.h"
#include "Task.h"
#include <ppl.h>

void Nbody_thread(Body particles[N], int numberofiterations)
{
	concurrency::parallel_for(int(0), numberofiterations, [&](int) {
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
		for (int i = 0; i < N; i++)
		{
			printParticle(particles[i]);
		}
	});
}