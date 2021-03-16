#include "ui.h"

void PrintProfile(Profile* profil)
{
	printf("Profile Id Number: %d , Place Of Birth: %s , Psychological Profile: %s , Years Of Recorded Service: %d \n",
		profil -> profileIdNumber, profil -> placeOfBirth, profil -> psychologicalProfile, profil-> yearsOfRecordedService);
}

void UiUndo()
{
	DynamicArray* redoneList;
	redoneList = createDynamicArray(myList->capacity, DestroyProfile);
	*redoneList = *myList;
	add(redoArrayOfArrays, redoneList);
	myList = getElementAtPosition(undoArrayOfArrays, undoArrayOfArrays->length - 1);
	deleteElement(undoArrayOfArrays, undoArrayOfArrays->length - 1);
}

void UiRedo()
{
	DynamicArray* undoneList;
	undoneList = createDynamicArray(myList->capacity, DestroyProfile);
	*undoneList = *myList;
	add(undoArrayOfArrays, undoneList);
	myList = getElementAtPosition(redoArrayOfArrays, redoArrayOfArrays->length - 1);
	deleteElement(redoArrayOfArrays, redoArrayOfArrays->length - 1);
}

void ListAllProfiles()
{
	myList = ServiceGetAll();
	int iterator;
	for (iterator = 0; iterator < myList -> length; iterator++)
	{
		Profile* p = getElementAtPosition(myList, iterator);
		PrintProfile(p);
	}
		
}

void ListPsychologicalProfile(char *psychologicalProfile)
{
	int ok = 0;
	char message[] = "No!";
	myList = ServiceGetAll();
	int iterator;
	for (iterator = 0; iterator < myList -> length; iterator++)
	{
		Profile* p = getElementAtPosition(myList, iterator);
		if (strcmp(p -> psychologicalProfile, psychologicalProfile) == 0)
		{
			PrintProfile(p);
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
	DynamicArray newList;
	newList = *createDynamicArray(10, DestroyProfile);
	for (iterator = 0; iterator < myList -> length; iterator++)
	{
		Profile* p = getElementAtPosition(myList, iterator);
		if (p -> yearsOfRecordedService < numberOfYears)
		{
			add(&newList, p);
		}
	}
	ServiceSortProfiles(&newList);
	for (iterator = 0; iterator < newList.length; iterator++)
	{
		Profile* p = getElementAtPosition(&newList, iterator);
		PrintProfile(getElementAtPosition(&newList, iterator));
	}
		
}

void UiAdd(char *initialText)
{
	DynamicArray* undoneList;
	undoneList = createDynamicArray(myList->capacity, DestroyProfile);
	*undoneList = *myList;
	add(undoArrayOfArrays, undoneList);
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
	DynamicArray* undoneList;
	undoneList = createDynamicArray(myList->capacity, DestroyProfile);
	*undoneList = *myList;
	add(undoArrayOfArrays, undoneList);
	char* add = strtok(initialText, " ");
	int profileIdNumber, yearsOfRecordedService;
	char const* ptr;
	char placeOfBirth[21];
	char psychologicalProfile[21];

	profileIdNumber = atoi(strtok(0, " ,"));
	ptr = strtok(0, " ,");
	strcpy(placeOfBirth, ptr);
	ptr = strtok(0, " ,");
	strcpy(psychologicalProfile, ptr);
	yearsOfRecordedService = atoi(strtok(0, " ,"));
	if (!ServiceUpdateProfile(profileIdNumber, placeOfBirth, psychologicalProfile, yearsOfRecordedService))
		printf("No!");
}

void UiDelete(char *initialText)
{
	DynamicArray* undoneList;
	undoneList = createDynamicArray(myList->capacity, DestroyProfile);
	*undoneList = *myList;
	add(undoArrayOfArrays, undoneList);
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
