#include "service.h"


void InitializeService()
{
	/*Initializer*/
	InitializeRepo();
}

void ServiceUndoCommand()
{
	/*Undo function using commands*/
	//printf("%d", getLength(undoCommands));
	Command* com = getElementAtPosition(undoCommands, getLength(undoCommands) - 1);
	//printf("%s, %d, %s, %s, %d", com->command, com->profileIdNumber, com->placeOfBirth, com->psychologicalProfile, com->yearsOfRecordedService);
	if (strcmp(com->command, "add") == 0)
	{
		//printf("*");
		ServiceDeleteProfile(com->profileIdNumber);
		//add(redoCommands, com);
	}
		
	if (strcmp(com->command, "delete") == 0)
	{
		ServiceAddProfile(com->profileIdNumber, com->placeOfBirth, com->psychologicalProfile, com->yearsOfRecordedService);
		//add(redoCommands, com);
	}
		
	if (strcmp(com->command, "update") == 0)
	{
		int index = ReturnIndex(myList, com->profileIdNumber);
		Profile* oldProfile = Copy(getElementAtPosition(myList, index));
		ServiceUpdateProfile(com->profileIdNumber, com->placeOfBirth, com->psychologicalProfile, com->yearsOfRecordedService);
		com->yearsOfRecordedService = oldProfile->yearsOfRecordedService;
		strcpy(com->placeOfBirth, oldProfile->placeOfBirth);
		strcpy(com->psychologicalProfile, oldProfile->psychologicalProfile);
		//add(redoCommands, com);
		DestroyProfile(oldProfile);
	}
	add(redoCommands, com);
	//printf("%d", getLength(undoCommands));
	undoCommands->length--;
	//printf("%d", getLength(undoCommands));
}

void ServiceRedoCommand()
{
	/*Redo function using commands*/
	//printf("%d", getLength(redoCommands));
	Command* com = getElementAtPosition(redoCommands, getLength(redoCommands) - 1);
	//printf("%s, %d, %s, %s, %d", com->command, com->profileIdNumber, com->placeOfBirth, com->psychologicalProfile, com->yearsOfRecordedService);

	if (strcmp(com->command, "add") == 0)
	{
		ServiceAddProfile(com->profileIdNumber, com->placeOfBirth, com->psychologicalProfile, com->yearsOfRecordedService);
		//add(undoCommands, com);
	}

	if (strcmp(com->command, "delete") == 0)
	{
		ServiceDeleteProfile(com->profileIdNumber);
		//add(undoCommands, com);
	}

	if (strcmp(com->command, "update") == 0)
	{
		int index = ReturnIndex(myList, com->profileIdNumber);
		Profile* oldProfile = Copy( getElementAtPosition(myList, index));
		ServiceUpdateProfile(com->profileIdNumber, com->placeOfBirth, com->psychologicalProfile, com->yearsOfRecordedService);
		com->yearsOfRecordedService = oldProfile->yearsOfRecordedService;
		strcpy(com->placeOfBirth, oldProfile->placeOfBirth);
		strcpy(com->psychologicalProfile, oldProfile->psychologicalProfile);
		
		DestroyProfile(oldProfile);
	}

	add(undoCommands, com);
	redoCommands->length--;
}

void ServiceUndo()
{
	/*Undo function*/
	//printf("%d", undoArrayOfArrays->length);
	static DynamicArray* redoneList;
	//undoneList = createDynamicArray(myList->capacity, &DestroyProfile);
	redoneList = RepoGetAll();
	add(redoArrayOfArrays, redoneList);

	destroy(myList);

	myList = getElementAtPosition(undoArrayOfArrays, undoArrayOfArrays->length - 1);
	//destroy(getElementAtPosition(undoArrayOfArrays, undoArrayOfArrays->length - 1));
	undoArrayOfArrays->length--;
	//destroy(redoneList);
}

void ServiceRedo()
{
	/*Redo function*/
	//printf("%d", redoArrayOfArrays->length);
	DynamicArray* undoneList;
	//undoneList = createDynamicArray(myList->capacity, &DestroyProfile);
	undoneList = RepoGetAll();
	add(undoArrayOfArrays, undoneList);

	destroy(myList);

	myList = getElementAtPosition(redoArrayOfArrays, redoArrayOfArrays->length - 1);
	//destroy(getElementAtPosition(redoArrayOfArrays, redoArrayOfArrays->length - 1));
	redoArrayOfArrays->length--;
	//destroy(undoneList);
}

DynamicArray* ServiceGetAll()
{
	/*Returns the list*/
	return RepoGetAll();
}

int ServiceAddProfile(int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService)
{
	/*Creates a profile and adds it
	Input: integer - profileIdNumber, char* - placeOfBirth, char* - psychologicalProfile, int - yearsOfRecordedService*/
	
	if (CheckExisting(myList, profileIdNumber))
		return 0;
	
	Profile* newProfile = CreateProfile(profileIdNumber, placeOfBirth, psychologicalProfile, yearsOfRecordedService);
	RepoAddProfile(newProfile);
	return 1;

}

int ServiceUpdateProfile(int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService)
{
	/*Creates a new profile and updates the old one
	Input: integer - profileIdNumber, char* - placeOfBirth, char* - psychologicalProfile, int - yearsOfRecordedService*/
	
	if (!CheckExisting(myList, profileIdNumber))
	{
		return 0;
	}
	
	Profile* newProfile = CreateProfile(profileIdNumber, placeOfBirth, psychologicalProfile, yearsOfRecordedService);
	RepoUpdateProfile(newProfile);
	return 1;
}

int ServiceDeleteProfile(int profileIdNumber)
{
	/*Deletes a new profile and updates the old one
	Input: integer - profileIdNumber, char* - placeOfBirth, char* - psychologicalProfile, int - yearsOfRecordedService*/
	
	if (!CheckExisting(myList, profileIdNumber))
		return 0;
	
	if (RepoDeleteProfile(profileIdNumber) != -1)
		return 1;
	return 0;
}



void ServiceSortProfiles(DynamicArray* newList)
{
	/*Sorts ascendingly by prychological profile a dynamic array
		Input: newList - pointer to dynamicArray */
	int iterator = 0;
	for (iterator = 0; iterator < (newList->length - 1); iterator++)
	{
		int secondIterator = iterator + 1;
		for (secondIterator = iterator + 1; secondIterator < (newList->length); secondIterator++)
		{
			Profile* p = getElementAtPosition(newList, iterator);
			Profile* p2 = getElementAtPosition(newList, secondIterator);
			if (strcmp(p->placeOfBirth, p2->placeOfBirth) > 0)
			{
				Profile* auxiliaryProfile;
				auxiliaryProfile = p;
				substitute(newList, iterator, p2);
				substitute(newList, secondIterator, auxiliaryProfile);
			}
		}

	}
}

