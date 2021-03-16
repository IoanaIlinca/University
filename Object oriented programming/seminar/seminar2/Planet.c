#define _CRT_SECURE_NO_WARNINGS
#include "Planet.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Planet* createPlanet(char* name, char* type, double distanceFromEarth)
{
	Planet* p = (Planet*)malloc(sizeof(Planet));
	p->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(p->name, name);
	p->type = (char*)malloc(sizeof(char) * (strlen(type) + 1));
	strcpy(p->type, type);

	p->distanceFromEarth = distanceFromEarth;

	return p;
}

void destroyPlanet(Planet* p)
{
	if (p == NULL)
		return;

	// free the memory which was allocated for the component fields
	free(p->name);
	free(p->type);

	// free the memory which was allocated for the planet structure
	free(p);
}

Planet* copyPlanet(Planet* p)
{
	if (p == NULL)
		return NULL;

	Planet* newPlanet = createPlanet(getName(p), getType(p), getDistanceFromEarth(p));
	return newPlanet;
}

char* getName(Planet* p)
{
	if (p == NULL)
		return NULL;
	return p->name;
}

char* getType(Planet* p)
{
	if (p == NULL)
		return NULL;
	return p->type;
}

double getDistanceFromEarth(Planet* p)
{
	if (p == NULL)
		return -1;
	return p->distanceFromEarth;
}

void toString(Planet* p, char str[])
{
	if (p == NULL)
		return;
	sprintf(str, "Planet %s is a %s planet and its distance from Earth is %.2lf.", p->name, p->type, p->distanceFromEarth);
}