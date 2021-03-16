#include "service.h"
#include "domain.h"
#include <stdlib.h>
#include <string.h>

void freeStringOfChars(char* string) {
    string = NULL;
    free(string);
}

MapService createMapService(Repo* repo)
{
    MapService mapService;
    mapService.repositoryPointer = repo;
    
    mapService.redoCommandsList = createDynamicArray(5, &freeStringOfChars);
    mapService.undoCommandsList = createDynamicArray(5, &freeStringOfChars);
    mapService.undoCommandArguments = createDynamicArray(5, &destroyMap);
    mapService.redoCommandArguments = createDynamicArray(5, &destroyMap);
    mapService.redoStackOfLists = createDynamicArray(5, &destroy);
    mapService.undoStackOfLists = createDynamicArray(5, &destroy);
    DynamicArray* emptyArray = createDynamicArray(5, &destroy);
    add(mapService.undoStackOfLists, emptyArray);
    return mapService;
}

int serviceNumberOfMaps(MapService* mapServicePointer)
{
    return numberOfMaps(mapServicePointer->repositoryPointer);
}

Map** serviceGetMaps(MapService* mapServicePointer)
{
    return getAllMaps(mapServicePointer->repositoryPointer);
}
int serviceAddMap(MapService* mapServicePointer, int catalogueNumber, char* stateOfDeterioration,char * mapType, int yearsOfStorage)
{
    Map* newMap = createMap(catalogueNumber, stateOfDeterioration, mapType, yearsOfStorage);
    add(mapServicePointer->undoCommandsList, "add");
    add(mapServicePointer->undoCommandArguments, newMap);
    add(mapServicePointer->undoStackOfLists, mapServicePointer->repositoryPointer->mapsList);
    return addMap(mapServicePointer->repositoryPointer, newMap);
}
int serviceUpgradeMap(MapService* mapServicePointer, int catalogueNumber, char* stateOfDeterioration,char * mapType, int yearsOfStorage)
{
    Map* newMap = createMap(catalogueNumber, stateOfDeterioration, mapType, yearsOfStorage);
    add(mapServicePointer->undoCommandsList, "update");
    Map* oldMap = getMapWithId(mapServicePointer->repositoryPointer, catalogueNumber);
    add(mapServicePointer->undoCommandArguments, oldMap);
    add(mapServicePointer->undoStackOfLists, mapServicePointer->repositoryPointer->mapsList);
    return updateMap(mapServicePointer->repositoryPointer, newMap);
}
int serviceRemoveMap(MapService* mapServicePointer, int catalogueNumberKey)
{
    add(mapServicePointer->undoCommandsList, "remove");
    Map* newMap = getMapWithId(mapServicePointer->repositoryPointer, catalogueNumberKey);
    add(mapServicePointer->undoCommandArguments, newMap);
    add(mapServicePointer->undoStackOfLists, mapServicePointer->repositoryPointer->mapsList);
    return removeMap(mapServicePointer->repositoryPointer, catalogueNumberKey);
}

Map** getListByYearsOfStorage(MapService* mapServicePointer, int maxYearsOfStorage, int *lengthOfFinalArray, int (*compareFunction)(void*, void*))
{
    Map** listOfRepo = getAllMaps(mapServicePointer->repositoryPointer);
    int lengthOfInitialList = numberOfMaps(mapServicePointer->repositoryPointer);
    int lengthOfListToSort=0;
    Map** listOfMapsYoungerThanCertainAge;
    listOfMapsYoungerThanCertainAge = (Map**)malloc(sizeof(Map*)*lengthOfInitialList);
    for(int i=0; i<lengthOfInitialList; i++)
        if(listOfRepo[i]->yearsOfStorage <= maxYearsOfStorage)
        {
            listOfMapsYoungerThanCertainAge[lengthOfListToSort] = listOfRepo[i];
            lengthOfListToSort++;
        }
    Map* auxiliaryMap;
    for(int i=0; i<lengthOfListToSort; i++)
        for(int j=i+1; j< lengthOfListToSort; j++)
            if( compareFunction(listOfMapsYoungerThanCertainAge[i], listOfMapsYoungerThanCertainAge[j]) == 1)
            {
                auxiliaryMap = listOfMapsYoungerThanCertainAge[i];
                listOfMapsYoungerThanCertainAge[i] = listOfMapsYoungerThanCertainAge[j];
                listOfMapsYoungerThanCertainAge[j] = auxiliaryMap;
            }
    *lengthOfFinalArray = lengthOfListToSort;
    return listOfMapsYoungerThanCertainAge;
}

void freeServiceMemory(MapService* mapService)
{
    freeRepoMemory(mapService->repositoryPointer);
    destroy(mapService->redoCommandArguments);
    destroy(mapService->redoCommandsList);
    destroy(mapService->undoCommandArguments);
    destroy(mapService->undoCommandsList);
}

///*
void undoAddMap(MapService* mapServicePointer, Map* oldMap)
{
    add(mapServicePointer->redoCommandsList, "remove");
    add(mapServicePointer->redoCommandArguments, oldMap);
    int exitCode=removeMap(mapServicePointer->repositoryPointer, oldMap->mapCatalogueNumber);
}
void undoUpgradeMap(MapService* mapServicePointer,Map* oldMap)
{
    
    add(mapServicePointer->redoCommandsList, "update");
    Map* newMap = getMapWithId(mapServicePointer->repositoryPointer, oldMap->mapCatalogueNumber);
    add(mapServicePointer->redoCommandArguments, newMap);
    int exitCode = updateMap(mapServicePointer->repositoryPointer, oldMap);
}
void undoRemoveMap(MapService* mapServicePointer, Map* oldMap)
{
    add(mapServicePointer->redoCommandsList, "add");
    add(mapServicePointer->redoCommandArguments, oldMap);
    int exitCode = addMap(mapServicePointer->repositoryPointer, oldMap);
}

int undoLastAction(MapService* mapServicePointer)
{
    int lengthOfUndoList = getLength(mapServicePointer->undoCommandsList);
    if (lengthOfUndoList == 0)
        return -1;
    int indexOfLastAction = lengthOfUndoList - 1;
    char* lastAction = getElementAtPosition(mapServicePointer->undoCommandsList, indexOfLastAction);
    Map* lastActionArgument = getElementAtPosition(mapServicePointer->undoCommandArguments, indexOfLastAction);
    if (strcmp(lastAction, "add") == 0) {
        undoAddMap(mapServicePointer, lastActionArgument);
    }
    else
    {
        if( strcmp(lastAction, "remove")==0)
            undoRemoveMap(mapServicePointer, lastActionArgument);
        else
            undoUpgradeMap(mapServicePointer, lastActionArgument);
    }
    deleteElement(mapServicePointer->undoCommandsList, indexOfLastAction);
    deleteElement(mapServicePointer->undoCommandArguments, indexOfLastAction);
}//*/


void redoAddMap(MapService* mapServicePointer, Map* oldMap)
{
    add(mapServicePointer->undoCommandsList, "add");
    add(mapServicePointer->undoCommandArguments, oldMap);
    int exitCode = addMap(mapServicePointer->repositoryPointer, oldMap);
}
void redoUpgradeMap(MapService* mapServicePointer, Map* oldMap)
{

    add(mapServicePointer->undoCommandsList, "update");
    Map* newMap = getMapWithId(mapServicePointer->repositoryPointer, oldMap->mapCatalogueNumber);
    add(mapServicePointer->undoCommandArguments, newMap);
    int exitCode = updateMap(mapServicePointer->repositoryPointer, oldMap);
}
void redoRemoveMap(MapService* mapServicePointer, Map* oldMap)
{
    add(mapServicePointer->undoCommandsList, "remove");
    add(mapServicePointer->undoCommandArguments, oldMap);
    int exitCode = removeMap(mapServicePointer->repositoryPointer, oldMap->mapCatalogueNumber);
}

int redoLastAction(MapService* mapServicePointer)
{
    int lengthOfRedoList = getLength(mapServicePointer->redoCommandsList);
    if (lengthOfRedoList == 0)
        return -1;
    int indexOfLastAction = lengthOfRedoList - 1;
    char* lastAction = getElementAtPosition(mapServicePointer->redoCommandsList, indexOfLastAction);
    Map* lastActionArgument = getElementAtPosition(mapServicePointer->redoCommandArguments, indexOfLastAction);
    if (strcmp(lastAction, "remove") == 0) {
        redoAddMap(mapServicePointer, lastActionArgument);
    }
    else
    {
        if (strcmp(lastAction, "add") == 0)
            redoRemoveMap(mapServicePointer, lastActionArgument);
        else
            redoUpgradeMap(mapServicePointer, lastActionArgument);
    }
    deleteElement(mapServicePointer->redoCommandsList, indexOfLastAction);
    deleteElement(mapServicePointer->redoCommandArguments, indexOfLastAction);
}

///list of lists version
/*
int undoLastAction(MapService* mapServicePointer) {
    int lengthOfUndoStack = getLength(mapServicePointer->undoStackOfLists);
    if (lengthOfUndoStack == 0)
        return -1;
    int indexOfLastList = lengthOfUndoStack - 1;
    DynamicArray* lastAction = getElementAtPosition(mapServicePointer->undoStackOfLists, indexOfLastList);
    copyDynamicArray(mapServicePointer->repositoryPointer->mapsList, lastAction);
    deleteElement(mapServicePointer->undoStackOfLists, indexOfLastList);
    //destroy(lastAction);

}
int redoLastAction(MapService* mapServicePointer);*/