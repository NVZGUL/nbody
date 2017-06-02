#pragma once
#include "general.h";

Body update(Body p, float timestamp);
Body resetForce(Body p);
void printParticle(Body p);
Body addForce(Body a, Body b);