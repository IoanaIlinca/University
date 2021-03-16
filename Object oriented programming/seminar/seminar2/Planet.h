#pragma once

typedef struct
{
	char* name;
	char* type;
	double distanceFromEarth;
} Planet;

Planet* createPlanet(char* name, char* type, double distanceFromEarth);
void destroyPlanet(Planet* p); // the memory is freed
Planet* copyPlanet(Planet* p); // copy a planet and return a pointer to the copy

char* getName(Planet* p);
char* getType(Planet* p);
double getDistanceFromEarth(Planet* p);

void toString(Planet* p, char str[]);