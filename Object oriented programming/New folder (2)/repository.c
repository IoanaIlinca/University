#include "repository.h"
#include "domain.h"
#include "dynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialiseRepo(Repo *repoPointer)
{
    repoPointer->mapsList = createDynamicArray(5, &destroyMap);
    repoPointer->numberOfMaps =0 ;
}

Map** getAllMaps(Repo *repoPointer)
{
    Map** copyOfMapArray;
    copyOfMapArray = (Map**)malloc(sizeof(Map*) * repoPointer->numberOfMaps);
    for (int i = 0; i < repoPointer->numberOfMaps; i++) {
       copyOfMapArray[i] = getElementAtPosition(repoPointer->mapsList, i);;
    }
    return copyOfMapArray;
}

int numberOfMaps(Repo *repoPointer)
{
    return repoPointer->numberOfMaps;
}
int searchMap(Repo* repoPointer, int catalogueNumberKey)
{
    for (int i = 0; i < repoPointer->numberOfMaps; i++) {

        Map* currentElement = getElementAtPosition(repoPointer->mapsList, i);
        if (currentElement->mapCatalogueNumber == catalogueNumberKey)
        {
            //printf("%d\n", i);
            return i;
        }
    }
    return -1;
}

int addMap(Repo *repoPointer, Map* mapToAdd)
{

    if(searchMap(repoPointer, mapToAdd->mapCatalogueNumber)!=-1)
        return -1;
    else
    {
        add(repoPointer->mapsList, mapToAdd);
        repoPointer->numberOfMaps ++;
        return 0;
    }
}

int updateMap(Repo *repoPointer, Map *updatedMap)
{
    int index = searchMap(repoPointer, updatedMap->mapCatalogueNumber);
    if(index==-1)
        return -1;
    else
    {
        substitute(repoPointer->mapsList, index, updatedMap);
        return 0;
    }
}

int removeMap(Repo *repoPointer, int catalogueNumberKeyToRemove)
{
    int index = searchMap(repoPointer, catalogueNumberKeyToRemove);
     if(index==-1)
        return -1;
    else
    {
        deleteElement(repoPointer->mapsList, index);
        repoPointer->numberOfMaps--;
        return 0;
    }
}

void freeRepoMemory(Repo* repoPointer)
{
    destroy(repoPointer->mapsList);
}
//add 123, 2, 22, 2

Map* getMapWithId(Repo* repoPointer, int catalogueNumberKeyToFind)
{
    int index = searchMap(repoPointer, catalogueNumberKeyToFind);
    return getElementAtPosition(repoPointer->mapsList, index);

}