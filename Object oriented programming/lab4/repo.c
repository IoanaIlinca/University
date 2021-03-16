#include "repo.h"

void InitializeRepo()
{
    myList = createDynamicArray(10, &DestroyProfile);
    undoArrayOfArrays = createDynamicArray(10, &destroy);
    redoArrayOfArrays = createDynamicArray(10, &destroy);
    undoCommands = createDynamicArray(10, &DestroyCommand);
    redoCommands = createDynamicArray(10, &DestroyCommand);
}


void RepoAddProfile(Profile* profil)
{
    
    add(myList, profil);
    //char string[101];
    //Profile* ptr = getElementAtPosition(myList, 0);
    //ConvertProfileToString(ptr, string);
    //printf("%s", string);
}

int CheckExisting(DynamicArray* List, int profileIdNumber)
{
    /* Checks if an id exists
    Input: List - pointer to DynamicArray, profileIdNumber - integer
    Ouput: 0 if it does not exist, 1 otherwise
    */
    int iterator = 0;
    for (iterator = 0; iterator < List -> length; iterator++)
    {
        Profile* p = getElementAtPosition(List, iterator);

        if (p -> profileIdNumber == profileIdNumber)
            return 1;
    }
    return 0;
}

int ReturnIndex(DynamicArray* List, int profileIdNumber)
{
    /* Returns the index in the List of a given profile
    Input: List - pointer to DynamicArray, profileIdNumber - integer
    Ouput: 0 or the index
    */

    int iterator = 0;
    for (iterator = 0; iterator < List->length; iterator++)
    {
        Profile* p = getElementAtPosition(List, iterator);

        if (p->profileIdNumber == profileIdNumber)
            return iterator;
    }
    return 0;
}

void RepoUpdateProfile(Profile* updatedProfile)
{
    /*Updates a profile
    Input: a pointer to a profile */
    int iterator = ReturnIndex(myList, updatedProfile->profileIdNumber);
    substitute(myList, iterator, updatedProfile);
}

int RepoDeleteProfile(int profileIdNumber)
{
    /* Deletes a profile from the list
    Input: the id - profileIdNumber, integer
    Output: -1 - not successful, 0 - successful */
    int index = ReturnIndex(myList, profileIdNumber);
    if (index == -1)
        return -1;
    deleteElement(myList, index);
    return 0;
}

DynamicArray* RepoGetAll()
{
    /* Retuns myList, which is a pointer to a Dynamic array of profiles*/
    DynamicArray* newList = createDynamicArray(myList->capacity, &DestroyProfile);
    int index;
    for (index = 0; index < myList->length; index++)
    {
        Profile* ptr = Copy(getElementAtPosition(myList, index));
        add(newList, ptr);
    }
    return newList;
}
