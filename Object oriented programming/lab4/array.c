#include "array.h"
#include <stdlib.h>
#include <assert.h>

DynamicArray* createDynamicArray(int capacity, DestroyElementFunctionType DestroyElementFunction)
{
	DynamicArray* temporaryArray = (DynamicArray*)malloc(sizeof(DynamicArray));
	// make sure that the space was allocated
	if (temporaryArray == NULL)
		return NULL;
	/*_CrtMemState s1;
	_CrtMemCheckpoint(&s1);
	_CrtMemDumpStatistics(&s1);*/
	temporaryArray->capacity = capacity;
	temporaryArray->length = 0;

	// allocate space for the elements
	temporaryArray->elements = (elementType*)malloc(capacity * sizeof(elementType));
	if (temporaryArray->elements == NULL)
		return NULL;

	// initialize the function pointer
	temporaryArray->destroyElementFunction = DestroyElementFunction;

	return temporaryArray;
}

void destroy(DynamicArray* arrayToRemove)
{
	if (arrayToRemove == NULL)
		return;

	// deallocate each of the elements - if we decide that the dynamic array is responsible with this
	for (int i = 0; i < arrayToRemove->length; i++)
	{
		arrayToRemove->destroyElementFunction(arrayToRemove->elements[i]);
	}
		
	//printf("I am here!");
	// free the space allocated for the elements
	if (arrayToRemove->elements != NULL)
	{
		free(arrayToRemove->elements);
		arrayToRemove->elements = NULL;
	}
		
	//free(arrayToRemove->destroyElementFunction);
	//printf("I am here 2!");
	// free the space allocated for the dynamic array
	free(arrayToRemove);
	arrayToRemove = NULL;
}

// Resizes the array, allocating more space.
// If more space cannot be allocated, returns -1, else it returns 0.
int resize(DynamicArray* arrayToResize)
{
	if (arrayToResize == NULL)
		return -1;

	arrayToResize->capacity *= 2;

	elementType* auxiliaryArray = (elementType*)malloc(arrayToResize->capacity * sizeof(elementType));
	if (auxiliaryArray == NULL)
		return -1;
	for (int i = 0; i < arrayToResize->length; i++)
		auxiliaryArray[i] = arrayToResize->elements[i];
	free(arrayToResize->elements);
	arrayToResize->elements = auxiliaryArray;

	return 0;
}

void add(DynamicArray* arrayAddingTo, elementType element)
{
	if (arrayAddingTo == NULL)
		return;
	if (arrayAddingTo->elements == NULL)
		return;

	// resize the array, if necessary
	if (arrayAddingTo->length == arrayAddingTo->capacity)
		resize(arrayAddingTo);
	arrayAddingTo->elements[arrayAddingTo->length++] = element;
}


int getLength(DynamicArray* originalArray)
{
	if (originalArray == NULL)
		return -1;

	return originalArray->length;
}

elementType getElementAtPosition(DynamicArray* storingArray, int position)
{
	if (position >= 0)
		return storingArray->elements[position];
	else
		return 0;
}

void substitute(DynamicArray* storingArray, int positionBeingChanged, elementType newElement)
{
	//storingArray->elements[positionBeingChanged] = newElement;
	storingArray->destroyElementFunction(storingArray->elements[positionBeingChanged]);
	storingArray->elements[positionBeingChanged] = newElement;
}
void deleteElement(DynamicArray* storingArray, int position)
{
	/*void** temp;
	temp = (void*)malloc(sizeof(void*) * storingArray->capacity);
	int j = 0;
	for (j = 0; j < position; j++) {
		temp[j] = storingArray->elements[j];
	}
	for (j = position; j < storingArray->length - 1; j++) {

		temp[j] = storingArray->elements[j + 1];
	}
	storingArray->elements = temp;
	storingArray->length--;*/
	storingArray->destroyElementFunction(storingArray->elements[position]);
	//printf("***");
	int j;
	for (j = position; j < storingArray->length - 1; j++) 
	{
		storingArray->elements[j] = storingArray->elements[j + 1];
	}
	storingArray->length--;
}

void copyDynamicArray(DynamicArray* destination, DynamicArray* source)
{
	for (int i = 0; i < destination->length; i++)
		destination->destroyElementFunction(destination->elements[i]);

	// free the space allocated for the elements
	free(destination->elements);
	destination->elements = NULL;
	*destination = *source;
}
// ------------------------------------------------------------------------------------------------------------

