#pragma once

typedef struct
{
    char name[50];
    char type[50];
    double distanceFromEarth;
} Planet;


/*
    Creates a planet with the given info
    Input: name, type - null terminated byte strings, distance - double
    Output: p - planet, with the attributes provided by the parameters
*/
Planet CreatePlanet(char name[], char type[], double distance);
double GetDistanceFromEarth(Planet p);
char* GetNamePlanet(Planet p);
