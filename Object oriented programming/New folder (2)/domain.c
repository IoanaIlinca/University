#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "domain.h"

Map* createMap(int mapCatalogueNumber, char stateOfDeterioration[], char type[], int yearsOfStorage)
{
    Map* aMap = (Map*)malloc(sizeof(Map));
    aMap->mapCatalogueNumber = mapCatalogueNumber;
    aMap->stateOfDeterioration = (char*)malloc(sizeof(char)*(strlen(stateOfDeterioration)+1));
    strcpy(aMap->stateOfDeterioration, stateOfDeterioration);
    aMap->mapType = (char*)malloc(sizeof(char)*(strlen(type)+1));
    strcpy(aMap->mapType, type);
    aMap->yearsOfStorage = yearsOfStorage;
    return aMap;
}

void destroyMap(Map* aMap)
{
    if (aMap == NULL)
		return;
    aMap->stateOfDeterioration = NULL;
    aMap->mapType = NULL;
    free(aMap->stateOfDeterioration);
    free(aMap->mapType);
    aMap = NULL;
    free(aMap);
}

char* getStateOfDeterioration(Map* aMap)
{
    return aMap->stateOfDeterioration;
}

char* getTypeOfMap(Map * aMap)
{
    return aMap->mapType;
}

int getYearsOfStorage(Map* aMap)
{
    return aMap->yearsOfStorage;
}
void setStateOfDeterioration(Map* aMap, char stateOfDeterioration[])
{
    strcpy(aMap->stateOfDeterioration, stateOfDeterioration);
}
void setType(Map* aMap, char type[])
{
    strcpy(aMap->mapType, type);
}
void setYearsOfStorage(Map* aMap, int yearsOfStorage)
{
    aMap->yearsOfStorage = yearsOfStorage;
}

void convertMapToString( Map* aMap, char* mapString)
{
    char catalogueNumberString[33], yearsOfStorageString[33];
	_itoa(aMap->mapCatalogueNumber, catalogueNumberString, 10);
	_itoa(aMap->yearsOfStorage, yearsOfStorageString, 10);
    strcpy(mapString,"Catalogue number:");
    strcat(mapString,catalogueNumberString);
    strcat(mapString," State:");
    strcat(mapString,aMap->stateOfDeterioration);
    strcat(mapString," Type:");
    strcat(mapString,aMap->mapType);
    strcat(mapString," Years of storage:");
    strcat(mapString,yearsOfStorageString);
}

int CompareAscendingByStateofDeterioration(Map* mapA, Map* mapB)
{
    return strcmp(mapA->stateOfDeterioration, mapB->stateOfDeterioration);
}

int CompareDescendingByStateofDeterioration(Map* mapA, Map* mapB)
{
    return -(strcmp(mapA->stateOfDeterioration, mapB->stateOfDeterioration));
}

int filterByStateOfDeterioration(Map* mapA, char* state)
{
    if (strcmp(mapA->stateOfDeterioration, state) == 0)
        return 1;
    return 0;
}

int filterByMapType(Map* mapA, char* type)
{
    if (strcmp(mapA->mapType, type) == 0)
        return 1;
    return 0;
}