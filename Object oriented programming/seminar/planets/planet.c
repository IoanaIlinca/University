#include "Planet.h"
#include <string.h>

Planet CreatePlanet(char name[], char type[], double distance)
{
    Planet p;
    p.distanceFromEarth = distance;
    strcpy(p.name, name);
    strcpy(p.type, type);
    return p;
}

double GetDistanceFromEarth(Planet p)
{
    return p.distanceFromEarth;
}

char* GetNamePlanet(Planet p)
{
    return p.name;
}
