#include "domain.h"

Profile* CreateProfile(int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService)
{
    Profile* newProfile = (Profile*)malloc(sizeof(Profile));
    newProfile -> profileIdNumber = profileIdNumber;
    newProfile -> yearsOfRecordedService = yearsOfRecordedService;
    strcpy(newProfile -> placeOfBirth, placeOfBirth);
    strcpy(newProfile -> psychologicalProfile, psychologicalProfile);
    return newProfile;
}

void DestroyProfile(Profile* profil)
{
    if (profil == NULL)
        return;
    
    //free(profil->placeOfBirth);
    //free(profil->profileIdNumber);
    //free(profil->psychologicalProfile);
    //free(profil->yearsOfRecordedService);

    free(profil);
}

void ConvertProfileToString(Profile* profil, char* finalString)
{
    char profilIdNumberString[21], yearsOfRecordedServiceString[21];
    _itoa(profil->profileIdNumber, profilIdNumberString, 10);
    _itoa(profil->yearsOfRecordedService, yearsOfRecordedServiceString, 10);
    strcpy(finalString, "Profile id number: ");
    strcat(finalString, profilIdNumberString);
    strcat(finalString, " Place of birth: ");
    strcat(finalString, profil->placeOfBirth);
    strcat(finalString, " Psychological state:");
    strcat(finalString, profil->psychologicalProfile);
    strcat(finalString, " Years of service: ");
    strcat(finalString, yearsOfRecordedServiceString);
}
