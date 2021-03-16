#pragma once
#include <string.h>
#include <stdlib.h>


typedef struct {
	int profileIdNumber, yearsOfRecordedService;
	char* placeOfBirth;
	char* psychologicalProfile;
	char* command;
} Command;

Command* CreateCommand(char* command, int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService);

void DestroyCommand(Command* command);

Command* CopyCommand(Command* comm);

