#define _CRT_SECURE_NO_WARNINGS
#include "command.h"


Command* CreateCommand(char* command, int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService)
{
    Command* newCommand = (Command*)malloc(sizeof(Command));
    newCommand->profileIdNumber = profileIdNumber;
    newCommand->yearsOfRecordedService = yearsOfRecordedService;
    newCommand->command = (char*)malloc(sizeof(char) * (strlen(command) + 1));
    newCommand->placeOfBirth = (char*)malloc(sizeof(char) * (strlen(placeOfBirth) + 1));
    newCommand->psychologicalProfile = (char*)malloc(sizeof(char) * (strlen(psychologicalProfile) + 1));
    strcpy(newCommand->command, command);
    strcpy(newCommand->placeOfBirth, placeOfBirth);
    strcpy(newCommand->psychologicalProfile, psychologicalProfile);
    return newCommand;
}

void DestroyCommand(Command* command)
{
    if (command == NULL)
        return;

    //printf("I have destroed a profile");
    //realloc(profil->placeOfBirth, sizeof(char) * 0);
    free(command->command);
    free(command->placeOfBirth);
    //free(profil->profileIdNumber);
    free(command->psychologicalProfile);
    //free(profil->yearsOfRecordedService);

    free(command);
}

Command* CopyCommand(Command* comm)
{
    Command* newP = (Command*)malloc(sizeof(Command));
    newP->command = (char*)malloc(sizeof(char) * (strlen(comm->command) + 1));
    newP->placeOfBirth = (char*)malloc((strlen(comm->placeOfBirth) + 1) * sizeof(char));
    newP->psychologicalProfile = (char*)malloc((strlen(comm->psychologicalProfile) + 1) * sizeof(char));
    strcpy(newP->command, comm->command);
    strcpy(newP->placeOfBirth, comm->placeOfBirth);
    strcpy(newP->psychologicalProfile, comm->psychologicalProfile);
    newP->profileIdNumber = comm->profileIdNumber;
    newP->yearsOfRecordedService = comm->yearsOfRecordedService;
    return newP;
}