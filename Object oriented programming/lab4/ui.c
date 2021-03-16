#include "ui.h"

void PrintProfile(Profile* profil)
{
	/*Prints a profile
	Input: profil - pointer to Profile*/
	printf("Profile Id Number: %d , Place Of Birth: %s , Psychological Profile: %s , Years Of Recorded Service: %d \n",
		profil -> profileIdNumber, profil -> placeOfBirth, profil -> psychologicalProfile, profil-> yearsOfRecordedService);
}

void UiUndo()
{
	/*Undoes the last operation*/
	if (getLength(undoArrayOfArrays) == 0)
	{
		printf("No commands");
		return;
	}
	ServiceUndo();
}

void UiUndoCommands()
{
	
	/*Undoes the last operation*/
	if (getLength(undoCommands) == 0)
	{
		printf("No commands");
		return;
		
	}
		
	ServiceUndoCommand();
}

void UiRedo()
{
	/*Redoes the last operation*/
	if (getLength(redoArrayOfArrays) == 0)
	{
		printf("No commands");
		return;
	}
		

	ServiceRedo();
}

void UiRedoCommands()
{
	/*Redoes the last operation*/
	if (getLength(redoCommands) == 0)
	{
		printf("No commands");
		return;
	}

	ServiceRedoCommand();
}

void ListAllProfiles()
{
	/*Prints all profiles*/
	if (myList == NULL)
	{
		return;
	}
	int iterator;
	for (iterator = 0; iterator < myList -> length; iterator++)
	{
		Profile* p = getElementAtPosition(myList, iterator);
		PrintProfile(p);
	}
		
}

void ListPsychologicalProfile(char *psychologicalProfile)
{
	/* Prints profiles with a cartain psychological profile 
	input: psychologicalProfile - pointer to char */
	int ok = 0;
	char message[] = "No!";
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
	/* Prints profiles with up to a cartain number of years of service
	input: maximumYearsOfService - pointer to char */
	int numberOfYears = atoi(maximumYearsOfService);
	int iterator;
	DynamicArray* newList;
	newList = createDynamicArray(10, &DestroyProfile);
	for (iterator = 0; iterator < myList -> length; iterator++)
	{
		Profile* p = getElementAtPosition(myList, iterator);
		if (p -> yearsOfRecordedService < numberOfYears)
		{
			add(newList, Copy(p));
		}
	}
	for (iterator = 0; iterator < (newList->length - 1); iterator++)
	{
		int secondIterator = iterator + 1;
		for (secondIterator = iterator + 1; secondIterator < (newList->length); secondIterator++)
		{
			Profile* p = getElementAtPosition(newList, iterator);
			Profile* p2 = getElementAtPosition(newList, secondIterator);
			if (strcmp(p->placeOfBirth, p2->placeOfBirth) > 0)
			{
				Profile auxiliaryProfile = *p;
				*p = *p2;
				*p2 = auxiliaryProfile;
			}
		}
	}

	for (iterator = 0; iterator < newList->length; iterator++)
	{
		//Profile* p = getElementAtPosition(newList, iterator);
		PrintProfile(getElementAtPosition(newList, iterator));
	}
	destroy(newList);
}

void UiAdd(char *initialText)
{
	/*Adds a profile
	Input: initialtext - pointer to char*/
	DynamicArray* undoneList;
	//undoneList = createDynamicArray(myList->capacity, &DestroyProfile);
	undoneList = RepoGetAll();
	add(undoArrayOfArrays, undoneList);
	char* adde = strtok(initialText, " ");
	int profileIdNumber, yearsOfRecordedService;
    char placeOfBirth[21], psychologicalProfile[21];

	char* ptr = strtok(0, " ,");
	if (ptr != NULL)
		profileIdNumber = atoi(ptr);
	else
	{
		printf("No!");
		return;
	}
		

	ptr = strtok(0, " ,");
	if (ptr != NULL)
		strcpy(placeOfBirth, ptr);
	else
	{
		printf("No!");
		return;
	}

	ptr = strtok(0, " ,");
	if (ptr != NULL)
		strcpy(psychologicalProfile, ptr);
	else
	{
		printf("No!");
		return;
	}

	ptr = strtok(0, " ,");
	if (ptr != NULL)
		yearsOfRecordedService = atoi(ptr);
	else
	{
		printf("No!");
		return;
	}

	if (!ServiceAddProfile(profileIdNumber, placeOfBirth, psychologicalProfile, yearsOfRecordedService))
		printf("No!");
	else
	{
		Command* comm = CreateCommand("add", profileIdNumber, placeOfBirth, psychologicalProfile, yearsOfRecordedService);
		add(undoCommands, comm);
	}
	
}

void UiUpdate(char *initialText)
{
	/*Updates a profile
	Input: initialtext - pointer to char*/
	DynamicArray* undoneList;
	//undoneList = createDynamicArray(myList->capacity, &DestroyProfile);
	undoneList = RepoGetAll();
	add(undoArrayOfArrays, undoneList);
	char* adde = strtok(initialText, " ");
	int profileIdNumber, yearsOfRecordedService;
	char* ptr = strtok(0, " ,");
	char placeOfBirth[21];
	char psychologicalProfile[21];

	if (ptr != NULL)
		profileIdNumber = atoi(ptr);
	else
	{
		printf("No!");
		return;
	}


	ptr = strtok(0, " ,");
	if (ptr != NULL)
		strcpy(placeOfBirth, ptr);
	else
	{
		printf("No!");
		return;
	}

	ptr = strtok(0, " ,");
	if (ptr != NULL)
		strcpy(psychologicalProfile, ptr);
	else
	{
		printf("No!");
		return;
	}

	ptr = strtok(0, " ,");
	if (ptr != NULL)
		yearsOfRecordedService = atoi(ptr);
	else
	{
		printf("No!");
		return;
	}
	int index = ReturnIndex(myList, profileIdNumber);
	Profile* profil = getElementAtPosition(myList, index);
	Command* comm = CreateCommand("update", profileIdNumber, profil->placeOfBirth, profil->psychologicalProfile, profil->yearsOfRecordedService);
	if (!ServiceUpdateProfile(profileIdNumber, placeOfBirth, psychologicalProfile, yearsOfRecordedService))
	{
		printf("No!");
		DestroyCommand(comm);
	}
		
	else
	{
		add(undoCommands, comm);
	}
}

void UiDelete(char *initialText)
{
	/*Deletes a profile
	Input: initialtext - pointer to char*/
	DynamicArray* undoneList;
	//undoneList = createDynamicArray(myList->capacity, &DestroyProfile);
	undoneList = RepoGetAll();
	add(undoArrayOfArrays, undoneList);
	char* del = strtok(initialText, " ");
	int profileIdNumber = atoi(strtok(0, " "));

	int index = ReturnIndex(myList, profileIdNumber);
	Profile* profil = getElementAtPosition(myList, index);
	Command* comm = CreateCommand("delete", profileIdNumber, profil->placeOfBirth, profil->psychologicalProfile, profil->yearsOfRecordedService);
	if (!ServiceDeleteProfile(profileIdNumber))
	{
		printf("No!");
		DestroyCommand(comm);
	}
		
	else
	{
		add(undoCommands, comm);
	}
}




void Console()
{
	/* Reads a command and calls the appropriate function*/
	InitializeService();
	printf("Commands:\nadd id, place of birth, psychological state, years of recorded service\ndelete id\nlist\nlist psychological state\nlist maximum years of service\nupdate id, new place of birth, new psychological state, new years of recorded service\nundo\nredo\nexit\n");
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
			UiUndoCommands();
			//UiUndo();
		else if (strcmp(cmd, "redo") == 0)
			UiRedoCommands();
			//UiRedo();
		else if (strcmp(cmd, "exit") == 0)
		{
			
			break;
		}
			
		else printf("Command does not exist!\n");
	}
}
