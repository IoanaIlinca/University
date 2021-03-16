#include "repo.h"

void InitializeRepo()
{
    myList = createDynamicArray(10, DestroyProfile);
    undoArrayOfArrays = createDynamicArray(1, &destroy);
    redoArrayOfArrays = createDynamicArray(1, &destroy);
}


void RepoAddProfile(Profile* profil)
{
    
    add(myList, profil);
    //char string[101];
    //Profile* ptr = getElementAtPosition(myList, 0);
    //ConvertProfileToString(ptr, string);
    //printf("%s", string);
}

int CheckExisting(int profileIdNumber)
{
    int iterator = 0;
    for (iterator = 0; iterator < myList -> length; iterator++)
    {
        Profile* p = getElementAtPosition(myList, iterator);

        if (p -> profileIdNumber == profileIdNumber)
            return 1;
    }
    return 0;
}

int ReturnIndex(int profileIdNumber)
{
    int iterator = 0;
    for (iterator = 0; iterator < myList->length; iterator++)
    {
        Profile* p = getElementAtPosition(myList, iterator);

        if (p->profileIdNumber == profileIdNumber)
            return iterator;
    }
    return 0;
}

void RepoUpdateProfile(Profile* updatedProfile)
{
    int iterator = ReturnIndex(updatedProfile->profileIdNumber);
    substitute(myList, iterator, updatedProfile);
    return;
}

int RepoDeleteProfile(int profileIdNumber)
{
    int index = ReturnIndex(profileIdNumber);
    if (index == -1)
        return -1;
    deleteElement(myList, index);
    return 0;
}

DynamicArray* RepoGetAll()
{
    return myList;
}
