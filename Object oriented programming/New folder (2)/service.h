#pragma once
#include "repository.h"

typedef struct {
    Repo* repositoryPointer;
    DynamicArray *undoCommandsList, *redoCommandsList, *undoCommandArguments, *redoCommandArguments;
    DynamicArray *undoStackOfLists, *redoStackOfLists;
}MapService;


MapService createMapService(Repo* repo);

/// <summary>
///returns a pointer to a copy of the list of all maps
/// </summary>
Map** serviceGetMaps(MapService* mapServicePointer);

/// <summary>
///returns 0 and adds aMap to repo if it is not already added
///if it is returns -1
/// </summary>
int serviceAddMap(MapService* mapServicePointer, int catalogueNumber, char* stateOfDeterioration,char * mapType, int yearsOfStorage);

/// <summary>
///returns 0 and upgrades the map with the same id as aMap to aMap if it is in repo,
///if it is not returns - 1 
/// </summary>
int serviceUpgradeMap(MapService* mapServicePointer, int catalogueNumber, char* stateOfDeterioration,char * mapType, int yearsOfStorage);

/// <summary>
///returns 0 and deletes the map with the id catalogueNumberKey if it is in repo,
///if it is not returns - 1 
/// </summary>
int serviceRemoveMap(MapService* mapServicePointer, int catalogueNumberKey);

/// <summary>
/// returns the number of maps stored
/// </summary>
int serviceNumberOfMaps(MapService* mapServicePointer);

/// <summary>
///returns a pointer to a a list of all maps under a certain yearsOfStorage number
///and ordered ascending by stateOfDeterioration
/// </summary>
Map** getListByYearsOfStorage(MapService* mapService,int maxYearsOfStorage, int *lengthOfFinalArray, void (*compareFunction)(void *, void *));

/// <summary>
/// destroys service object and frees memory
/// </summary>
void freeServiceMemory(MapService* mapService);

int undoLastAction(MapService* mapServicePointer);

int redoLastAction(MapService* mapServicePointer);
