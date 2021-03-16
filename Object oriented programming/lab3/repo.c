#include "repo.h"

void InitializeRepo()
{
    myList.numberOfProfiles = 0;
}

void RepoAddProfile(Profile newProfile)
{
    myList.listOfProfiles[myList.numberOfProfiles++] = newProfile;
}

int CheckExisting(int profileIdNumber)
{
    int iterator = 0;
    for (iterator = 0; iterator < myList.numberOfProfiles; iterator++)
    {
        if (myList.listOfProfiles[iterator].profileIdNumber == profileIdNumber)
            return 1;
    }
    return 0;
}

void RepoUpdateProfile(Profile updatedProfile)
{
    int iterator = 0;
    for(iterator = 0; iterator < myList.numberOfProfiles; iterator++)
    {
        if (myList.listOfProfiles[iterator].profileIdNumber == updatedProfile.profileIdNumber)
        {
            myList.listOfProfiles[iterator] = updatedProfile;
            return;
        }
    }
}

void RepoDeleteProfile(int profileIdNumber)
{
    int iterator = 0;
    AllProfiles newList;
    newList.numberOfProfiles = 0;
    for (iterator = 0; iterator < myList.numberOfProfiles; iterator++)
    {
        if (myList.listOfProfiles[iterator].profileIdNumber != profileIdNumber)
            newList.listOfProfiles[newList.numberOfProfiles++] = myList.listOfProfiles[iterator];
    }
    myList = newList;
}

AllProfiles RepoGetAll()
{
    return myList;
}
