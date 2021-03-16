#include "ui.h"

void PrintProfile(Profile profil)
{
	printf("Profile Id Number: %d , Place Of Birth: %s , Psychological Profile: %s , Years Of Recorded Service: %d \n",
		profil.profileIdNumber, profil.placeOfBirth, profil.psychologicalProfile, profil.yearsOfRecordedService);
}

void UiUndo()
{
	printf("%s", "Undo");
}

void UiRedo()
{
	printf("%s", "Redo");
}

void ListAllProfiles()
{
	myList = ServiceGetAll();
	int iterator;
	for (iterator = 0; iterator < myList.numberOfProfiles; iterator++)
		PrintProfile(myList.listOfProfiles[iterator]);
}

void ListPsychologicalProfile(char *psychologicalProfile)
{
	int ok = 0;
	char message[] = "No!";
	myList = ServiceGetAll();
	int iterator;
	for (iterator = 0; iterator < myList.numberOfProfiles; iterator++)
	{
		if (strcmp(myList.listOfProfiles[iterator].psychologicalProfile, psychologicalProfile) == 0)
		{
			PrintProfile(myList.listOfProfiles[iterator]);
			ok = 1;
		}
	}
	if (ok == 0)
		printf("%s", message);
}

void ListMaximumYearsOfService(char* maximumYearsOfService)
{
	int numberOfYears = atoi(maximumYearsOfService);
	myList = ServiceGetAll();
	int iterator;
	AllProfiles newList;
	newList.numberOfProfiles = 0;
	for (iterator = 0; iterator < myList.numberOfProfiles; iterator++)
	{
		if (myList.listOfProfiles[iterator].yearsOfRecordedService < numberOfYears)
		{
			newList.listOfProfiles[newList.numberOfProfiles++] = myList.listOfProfiles[iterator];
		}
	}
	ServiceSortProfiles(&newList);
	for (iterator = 0; iterator < newList.numberOfProfiles; iterator++)
		PrintProfile(newList.listOfProfiles[iterator]);
}

void UiAdd(char *initialText)
{
	char* add = strtok(initialText, " ");
	int profileIdNumber, yearsOfRecordedService;
    char placeOfBirth[21], psychologicalProfile[21];

	profileIdNumber = atoi(strtok(0, " ,"));
	strcpy(placeOfBirth, strtok(0, " ,"));
	strcpy(psychologicalProfile, strtok(0, " ,"));
	yearsOfRecordedService = atoi(strtok(0, " ,"));
	if (!ServiceAddProfile(profileIdNumber, placeOfBirth, psychologicalProfile, yearsOfRecordedService))
		printf("No!");
}

void UiUpdate(char *initialText)
{
	char* add = strtok(initialText, " ");
	int profileIdNumber, yearsOfRecordedService;
    char placeOfBirth[21], psychologicalProfile[21];

	profileIdNumber = atoi(strtok(0, " ,"));
	strcpy(placeOfBirth, strtok(0, " ,"));
	strcpy(psychologicalProfile, strtok(0, " ,"));
	yearsOfRecordedService = atoi(strtok(0, " ,"));
	if (!ServiceUpdateProfile(profileIdNumber, placeOfBirth, psychologicalProfile, yearsOfRecordedService))
		printf("No!");
}

void UiDelete(char *initialText)
{
	char* del = strtok(initialText, " ");
	int profileIdNumber = atoi(strtok(0, " "));
	if (!ServiceDeleteProfile(profileIdNumber))
		printf("No!");
}




void Console()
{
	InitializeService();
	while (1)
	{
		char first_cmd[256], full_cmd[256], * cmd,s[10]=">>";
		printf("%s",s);
		scanf("%[^\n]%*c", full_cmd);
		strcpy(first_cmd, full_cmd);
		cmd = strtok(first_cmd, " ");
		if (strcmp(cmd, "add") == 0)
		{
			UiAdd(full_cmd);
		}
		else if (strcmp(cmd, "update") == 0)
		{
			UiUpdate(full_cmd);
		}
		else if (strcmp(cmd, "delete") == 0)
		{
			UiDelete(full_cmd);
		}
		else if (strcmp(cmd, "list") == 0)
		{
			cmd = strtok(0, " ");
			if (!cmd)
				ListAllProfiles();
			else
			{
				if (atoi(cmd) == 0)
					ListPsychologicalProfile(cmd);
				else
					ListMaximumYearsOfService(cmd);
			}
		}
		else if (strcmp(cmd, "undo") == 0)
			UiUndo();
		else if (strcmp(cmd, "redo") == 0)
			UiRedo();
		else if (strcmp(cmd, "exit") == 0)
			break;
		else printf("Command does not exist!\n");
	}
}
