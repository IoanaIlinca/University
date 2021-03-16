#include "ui.h"
#include "service.h"
#include "domain.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


Console createConsole(MapService* mapServicePointer)
{
    Console console;
    console.mapServicePointer = mapServicePointer;
    return console;
}

void uiAddMap(Console* consolePointer, char* parametersString)
{
    int exitCode;
    int catalogueNumber, yearsOfStorage;
    char *currentParameter, stateOfDeterioration[15], mapType[15];
    currentParameter = strtok(parametersString, ", ");
    catalogueNumber = atoi(currentParameter);
    currentParameter = strtok(NULL, ", ");
    strcpy(stateOfDeterioration, currentParameter);
    currentParameter = strtok(NULL, ", ");
    strcpy(mapType, currentParameter);
    currentParameter = strtok(NULL, ", ");
    yearsOfStorage = atoi(currentParameter);
    exitCode = serviceAddMap(consolePointer->mapServicePointer, catalogueNumber, stateOfDeterioration, mapType, yearsOfStorage);
    if (exitCode == -1)
    {
        printf("No!\n");
    }
}

void uiRemoveMap(Console* consolePointer, char* parametersString)
{
    int exitCode;
    int catalogueNumber = atoi(parametersString);
    exitCode = serviceRemoveMap(consolePointer->mapServicePointer, catalogueNumber);
    if (exitCode == -1)
    {
        printf("No!\n");
    }
}

void uiUpdateMap(Console* consolePointer, char* parametersString)
{
    int exitCode;
    int catalogueNumber, yearsOfStorage;
    char *currentParameter, stateOfDeterioration[15], mapType[15];
    currentParameter = strtok(parametersString, ", ");
    catalogueNumber = atoi(currentParameter);
    currentParameter = strtok(NULL, ", ");
    strcpy(stateOfDeterioration, currentParameter);
    currentParameter = strtok(NULL, ", ");
    strcpy(mapType, currentParameter);
    currentParameter = strtok(NULL, ", ");
    yearsOfStorage = atoi(currentParameter);
    exitCode = serviceUpgradeMap(consolePointer->mapServicePointer, catalogueNumber, stateOfDeterioration, mapType, yearsOfStorage);
    if (exitCode == -1)
    {
        printf("No!\n");
    }
}
/// <summary>
/// lists all maps
/// </summary>
void listMaps(Console* consolePointer)
{
    Map** mapArray = serviceGetMaps(consolePointer->mapServicePointer);
    int i;
    char mapString[150];
    for (i = 0; i < serviceNumberOfMaps(consolePointer->mapServicePointer); i++)
    {
        convertMapToString(mapArray[i], mapString);
        printf("%s\n", mapString);
    }
    free(mapArray);
}


/// <summary>
/// lists maps that suffice the given filtering criteria
/// </summary>
void filteredList(Console* consolePointer,char* filterTerm,int (*filter)(void*, void *))
{
    Map** mapArray = serviceGetMaps(consolePointer->mapServicePointer);  
    int i;
    char mapString[150];
    for (i = 0; i < serviceNumberOfMaps(consolePointer->mapServicePointer); i++)
    {
        if (filter(mapArray[i], filterTerm) == 1)
        {
            convertMapToString(mapArray[i], mapString);
            printf("%s\n", mapString);
        }
    }
}

/// <summary>
/// lists maps that have a certain yearsOfSotorage value lower then  the param yearsOfStorage
/// in ascending order
/// </summary>
void listByYearsOfStorage(Console* consolePointer, int yearsOfStorage, char* wantedOrder)
{
    int lengthOfArray;
    Map** mapArray;
    if (strcmp(wantedOrder, "ascending") == 0) {
        mapArray = getListByYearsOfStorage(consolePointer->mapServicePointer, yearsOfStorage, &lengthOfArray, &CompareAscendingByStateofDeterioration);
    }
    else
    {
        mapArray = getListByYearsOfStorage(consolePointer->mapServicePointer, yearsOfStorage, &lengthOfArray, &CompareDescendingByStateofDeterioration);
    }
    int i;
    char mapString[150];
    for (i = 0; i < lengthOfArray ; i++)
    {
        convertMapToString(mapArray[i], mapString);
        printf("%s\n", mapString);
    }
    free(mapArray);
}

void uiUndo(Console* consolePointer)
{
    int exitCode;
    exitCode = undoLastAction(consolePointer->mapServicePointer);
    if (exitCode == -1)
        printf("No actions left to undo\n");
}

void uiRedo(Console* consolePointer)
{
    int exitCode;
    exitCode = redoLastAction(consolePointer->mapServicePointer);
    if (exitCode == -1)
        printf("No actions left to redo\n");
}

/// <summary>
/// returns a positve integer obtained from stringToCheck
/// if possible or -1 if string has other characters beside digits
/// </summary>
int strToInt(char *inputString)
{
    int i = 0;
    for( i=0; i<strlen(inputString); i++)
        if (inputString[i] <'0' || inputString[i]>'9')
            return -1;
    return atoi(inputString);
}

void freeMemory(Console* consolePointer)
{
    freeServiceMemory(consolePointer->mapServicePointer);
}

int run(Console* consolePointer)
{
    char inputLine[150] = "", * currentWord;
    while (1)
    {
        gets(inputLine);
        currentWord = strtok(inputLine, " ");
        if (strcmp(currentWord, "add") == 0)
        {
            uiAddMap(consolePointer, currentWord + strlen(currentWord) + 1);
            continue;
        }
        if (strcmp(currentWord, "update") == 0)
        {
            uiUpdateMap(consolePointer, currentWord + strlen(currentWord) + 1);
            continue;
        }
        if (strcmp(currentWord, "delete") == 0)
        {
            uiRemoveMap(consolePointer, currentWord + strlen(currentWord) + 1);
            continue;
        }
        if (strcmp(currentWord, "undo") == 0)
            uiUndo(consolePointer);
        if (strcmp(currentWord, "redo") == 0)
            uiRedo(consolePointer);
        if (strcmp(currentWord, "list") == 0)
        {
            currentWord = strtok(NULL, " ");
            if (currentWord == NULL)
            {
                listMaps(consolePointer);
            }
            else {
                int exitCode = strToInt(currentWord);
                
                if(exitCode!=-1)
                {
                    currentWord = strtok(NULL, " ");
                    listByYearsOfStorage(consolePointer, exitCode, currentWord);
                }
                else
                {
                    
                    char* filterTerm;
                    filterTerm = strtok(NULL, " ");
                    
                    if (strcmp(currentWord, "state") == 0)
                        filteredList(consolePointer,filterTerm, &filterByStateOfDeterioration);
                    if (strcmp(currentWord, "type") == 0)
                        filteredList(consolePointer, filterTerm, &filterByMapType);
                }
            }
            continue;
        }
        if (strcmp(currentWord, "exit") == 0)
        {
            freeMemory(consolePointer);
            return 0;
        }
    }
}

