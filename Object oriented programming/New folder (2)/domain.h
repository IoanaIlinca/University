#pragma once

typedef struct
{
    int mapCatalogueNumber, yearsOfStorage;
    char* stateOfDeterioration;
    char* mapType;
} Map;

/// <summary>
/// creates a Map object 
/// </summary>
/// <param name="mapCatalogueNumber">int, represents the unique id of the map</param>
///<param name = "stateOfDeterioration">string of chars < / param>
///<param name = "type">string of chars< / param>
///<param name = "yearsOFStorage">int< / param>
/// <returns>pointer to a map object with the given attributes/returns>
Map* createMap(int mapCatalogueNumber, char stateOfDeterioration[], char type[], int yearsOfStorage);

char* getStateOfDeterioration(Map* aMap);

char* getType(Map* aMap);

int getYearsOfStorage(Map* aMap);

void setStateOfDeterioration(Map* aMap, char stateOfDeterioration[]);

void setType(Map* aMap, char type[]);

void setYearsOfStorage( Map* aMap, int yearsOfStorage);

void convertMapToString( Map* aMap, char* mapString);

/// <summary>
/// frees the memory allocateed to a map object
/// </summary>
void destroyMap(Map* aMap);
int CompareAscendingByStateofDeterioration(Map* mapA, Map* mapB);

int CompareDescendingByStateofDeterioration(Map* mapA, Map* mapB);

int filterByStateOfDeterioration(Map* mapA, char* state);

int filterByMapType(Map* mapA, char* state);
