#pragma once
#include "domain.h"
#include "dynamicArray.h"
typedef struct{
    DynamicArray* mapsList;
    int numberOfMaps;
} Repo;


/// <summary>
/// sets length to 0 and initialise a dynamic array
/// </summary>
void initialiseRepo(Repo *repoPointer);


/// <summary>
/// returns the number of maps stored
/// </summary>
int numberOfMaps(Repo *repoPointer);


/// <summary>
///returns the position of the map corresponding to the catalogue number
///or -1 if no such map exists
/// </summary>
int searchMap(Repo *repoPointer, int catalogueNumberKey);

/// <summary>
///returns 0 and adds aMap to repo if it is not already added
///if it is returns -1
/// </summary>
int addMap(Repo *repoPointer, Map *MapToAdd);



/// <summary>
///returns 0 and upgrades the map with the same id as aMap to aMap if it is in repo,
///if it is not returns - 1 
/// </summary>
int updateMap(Repo *repoPointer, Map *updateMap);



/// <summary>
///returns 0 and deletes the map with the id catalogueNumberKey if it is in repo,
///if it is not returns - 1 
/// </summary>
int removeMap(Repo *repoPointer, int catalogueNumberKeyToRemove);


/// <summary>
///returns a pointer to a copy of the list of all maps
/// </summary>
Map** getAllMaps(Repo *repoPointer);

/// <summary>
/// destroys  repo object and frees memory
/// </summary>
void freeRepoMemory(Repo* repoPointer);

///<summary>
///gets the map with the specified id if it exists
///</summary>
Map* getMapWithId(Repo* repoPointer,int catalogueNumberKeyToFind);