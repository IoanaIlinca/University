#include "domain.h"

Profile CreateProfile(int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService)
{
    Profile newProfile;
    newProfile.profileIdNumber = profileIdNumber;
    newProfile.yearsOfRecordedService = yearsOfRecordedService;
    strcpy(newProfile.placeOfBirth, placeOfBirth);
    strcpy(newProfile.psychologicalProfile, psychologicalProfile);
    return newProfile;
}
