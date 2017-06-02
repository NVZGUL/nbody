#include "float3.h"
#include "general.h"
#include "body.h"

#include <random>
#include <cmath>

std::random_device rd;
std::mt19937 gen(rd());

float rand(float r) 
{
	std::uniform_real_distribution<float> dis(0, r);
	return dis(gen);
}
float rand(float l, float r)
{
	std::uniform_real_distribution<float> dis(l, r);
	return dis(gen);
}