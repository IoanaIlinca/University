#include "tests.h"
#include "domain.h"
#include "dynamicArray.h"
#include "repository.h"
#include "service.h"
#include <string.h>

void createMap_validInput_ok()
{
	Map* testMap = createMap(1, "bad", "A4", 23);
	assert(testMap->mapCatalogueNumber == 1);
	destroyMap(testMap);
}

void getStateOfDeterioration_validInput_ok()
{
	Map* testMap = createMap(1, "bad", "A4", 23);
	assert( strcmp(getStateOfDeterioration(testMap),"bad") ==0);
	destroyMap(testMap);
}

void getYearsofStorage_validInput_ok()
{
	Map* testMap = createMap(1, "bad", "A4", 23);
	assert(getYearsOfStorage(testMap)== 23);
	destroyMap(testMap);
}
void setStateOfDeterioration_validInput_ok()
{
	Map* testMap = createMap(1, "bad", "A4", 23);
	setStateOfDeterioration(testMap, "good");
	assert(strcmp(getStateOfDeterioration(testMap), "good") == 0);
	destroyMap(testMap);
}

void setYearsOfStorage_validInput_ok()
{
	Map* testMap = createMap(1, "bad", "A4", 23);
	setYearsOfStorage(testMap, 100);
	assert(getYearsOfStorage(testMap) == 100);
	destroyMap(testMap);
}

void convertMapToString_validInput_ok()
{
	Map* testMap = createMap(1, "bad", "A4", 23);
	char mapString[100], expectedResult[100];
	strcpy(expectedResult, "Catalogue number:1 State:bad Type:A4 Years of storage:23");
	convertMapToString(testMap, mapString);
	assert(strcmp(mapString, expectedResult) == 0);
	destroyMap(testMap);
}
void testsDomain()
{
	createMap_validInput_ok();
	getStateOfDeterioration_validInput_ok();
	getYearsofStorage_validInput_ok();
	setStateOfDeterioration_validInput_ok();
	setYearsOfStorage_validInput_ok();
	convertMapToString_validInput_ok();
}


void createDynamicArray_validInput_ok()
{
	DynamicArray* testArrayOfMaps = createDynamicArray(5, &destroyMap);
	assert(testArrayOfMaps->capacity == 5);
}

void getLengthArray_validInput_ok()
{
	DynamicArray* testArrayOfMaps = createDynamicArray(5, &destroyMap);
	assert(testArrayOfMaps->length == 0);
}
void resizeDynamicArray_validInput_ok()
{
	DynamicArray* testArrayOfMaps = createDynamicArray(5, &destroyMap);
	resize(testArrayOfMaps);
	assert(testArrayOfMaps->capacity == 10);
}

void addToDynamicArray_validInput_ok()
{
	Map* testMap = createMap(1, "bad", "A4", 23);
	DynamicArray* testArrayOfMaps = createDynamicArray(5, &destroyMap);
	add(testArrayOfMaps, testMap);
	assert(testArrayOfMaps->length == 1);
}

void getElementAtPosition_validPosition_ok()
{
	Map* testMap = createMap(1, "bad", "A4", 23);
	DynamicArray* testArrayOfMaps = createDynamicArray(5, &destroyMap);
	add(testArrayOfMaps, testMap);
	Map* element = getElementAtPosition(testArrayOfMaps, 0);
	assert(strcmp(getStateOfDeterioration(element),"bad") == 0);
}

void substitute_validPosition_ok()
{
	Map* testMap = createMap(1, "bad", "A4", 23);
	DynamicArray* testArrayOfMaps = createDynamicArray(5, &destroyMap);
	add(testArrayOfMaps, testMap);
	Map* substituteMap = createMap(1, "good", "A4", 23);
	substitute(testArrayOfMaps, 0, substituteMap);
	Map* element = getElementAtPosition(testArrayOfMaps, 0);
	assert(strcmp(getStateOfDeterioration(element), "good") == 0);
}
void deleteElement_validPosition_ok()
{
	Map* testMap = createMap(1, "bad", "A4", 23);
	DynamicArray* testArrayOfMaps = createDynamicArray(5, &destroyMap);
	add(testArrayOfMaps, testMap);
	deleteElement(testArrayOfMaps, 0);
	assert(testArrayOfMaps->length == 0);
}
void testsDynamicArray()
{
	createDynamicArray_validInput_ok();
	getLengthArray_validInput_ok();
	resizeDynamicArray_validInput_ok();
	addToDynamicArray_validInput_ok();
	getElementAtPosition_validPosition_ok();
	substitute_validPosition_ok();
	deleteElement_validPosition_ok();
}

void initialiseRepo_validInput_ok()
{
	Repo testRepository;
	initialiseRepo(&testRepository);
	assert(testRepository.numberOfMaps == 0);
}

void addRepo_validInput_ok()
{
	Map* testMap = createMap(1, "bad", "A4", 23);
	Repo testRepository;
	initialiseRepo(&testRepository);
	addMap(&testRepository, testMap);
	assert(testRepository.numberOfMaps == 1);
}

void searchMapRepo_validInput_ok()
{
	Map* testMap = createMap(1, "bad", "A4", 23);
	Repo testRepository;
	initialiseRepo(&testRepository);
	addMap(&testRepository, testMap);
	assert(searchMap(&testRepository, 1) == 0);
}

void getMapWithId_validInput_ok()
{
	Map* testMap = createMap(1, "bad", "A4", 23);
	Repo testRepository;
	initialiseRepo(&testRepository);
	addMap(&testRepository, testMap);
	Map* currentElement = getMapWithId(&testRepository, 1);
	assert(getYearsOfStorage(currentElement) == 23);
}
void updateMapRepo_validInput_ok()
{
	Map* testMap = createMap(1, "bad", "A4", 23);
	Repo testRepository;
	initialiseRepo(&testRepository);
	addMap(&testRepository, testMap);
	Map* testUpdateMap = createMap(1, "good", "A4", 23);
	updateMap(&testRepository, testUpdateMap);
	int index = searchMap(&testRepository, 1);
	Map* currentElement = getElementAtPosition(testRepository.mapsList, 0);
	assert( getYearsOfStorage(currentElement)== 23);
}

void removeMapRepo_validInput_ok()
{
	Map* testMap = createMap(1, "bad", "A4", 23);
	Repo testRepository;
	initialiseRepo(&testRepository);
	addMap(&testRepository, testMap);
	removeMap(&testRepository, 1);
	assert(testRepository.numberOfMaps == 0);
}

void testsRepo()
{
	initialiseRepo_validInput_ok();
	addRepo_validInput_ok();
	searchMapRepo_validInput_ok();
	getMapWithId_validInput_ok();
	updateMapRepo_validInput_ok();
	removeMapRepo_validInput_ok();
}

void createMapSevice_validInput_ok()
{
	Repo testRepository;
	initialiseRepo(&testRepository);
	MapService testService = createMapService(&testRepository);
	assert(getLength(testService.undoCommandArguments) == 0);

}
void serviceAddMap_validInput_ok()
{
	Repo testRepository;
	initialiseRepo(&testRepository);
	MapService testService = createMapService(&testRepository);
	serviceAddMap(&testService, 1, "bad", "A4", 23);
	assert(testService.repositoryPointer->numberOfMaps == 1);

}
void getAllMapsService_validInput_ok()
{
	Repo testRepository;
	initialiseRepo(&testRepository);
	MapService testService = createMapService(&testRepository);
	serviceAddMap(&testService, 1, "bad", "A4", 23);
	Map** arrayOfAllMaps = serviceGetMaps(&testService);
	assert(arrayOfAllMaps[0]->mapCatalogueNumber == 1);

}
void serviceUpgradeMap_validInput_ok()
{
	Repo testRepository;
	initialiseRepo(&testRepository);
	MapService testService = createMapService(&testRepository);
	serviceAddMap(&testService, 1, "bad", "A4", 23);
	serviceUpgradeMap(&testService, 1, "good", "A4", 27);
	assert(getMapWithId(testService.repositoryPointer,1)->yearsOfStorage== 27);


}

void serviceRemoveMap_validInput_ok()
{
	Repo testRepository;
	initialiseRepo(&testRepository);
	MapService testService = createMapService(&testRepository);
	serviceAddMap(&testService, 1, "bad", "A4", 23);
	serviceRemoveMap(&testService, 1);
	assert(testService.repositoryPointer->numberOfMaps == 0);

}

void testsService()
{
	createMapSevice_validInput_ok();
	serviceAddMap_validInput_ok();
	getAllMapsService_validInput_ok();
	serviceUpgradeMap_validInput_ok();
	serviceRemoveMap_validInput_ok();
}

void allTests()
{
	testsDomain();
	testsDynamicArray();
	testsRepo();
	testsService();
}
