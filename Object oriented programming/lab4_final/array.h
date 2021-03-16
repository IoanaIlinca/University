#pragma once

typedef void* elementType;
typedef void (*DestroyElementFunctionType)(void*);
typedef struct
{
    elementType* elements;
    int length; // actual length of the array
    int capacity; // maximum capacity of the array
    DestroyElementFunctionType destroyElementFunction;
} DynamicArray;


/// <summary>
/// Creates a dynamic array of generic elements, with a given capacity.
/// </summary>
/// <param name="capacity">Integer, maximum capacity for the dynamic array.</param>
/// <returns>A pointer the the created dynamic array.</returns>
DynamicArray* createDynamicArray(int capacity, DestroyElementFunctionType destroyElementFunction);


/// <summary>
/// Destroys the dynamic array.
/// </summary>
/// <param name="arrayToRemove">The dynamic array to be destoyed.</param>
/// <returns>A pointer the the created dynamic array.</returns>
void destroy(DynamicArray* arrayToRemove);

/// <summary>
/// Adds a generic element to the dynamic array.
/// </summary>
/// <param name="arrayToModify">The dynamic array.</param>
/// <param name="element">The element to be added.</param>
void add(DynamicArray* arrayToModify, elementType element);


/// <summary>
/// gets the current length of the array
/// </summary>
/// <param name="original"> the dynamic array whose length is returned.</param>
/// <returns>An integer representing the number of objects.</returns>
int getLength(DynamicArray* originalArray);


/// <summary>
/// gets the elemnt of the array stored at the index position
/// </summary>
/// <param name="storingArray">a dynamic array </param>
///<param name = "position">position of the element that we want in the dynamic array < / param>
/// <returns>A pointer to the object at index "position" in array.</returns>
elementType getElementAtPosition(DynamicArray* storingArray, int position);


/// <summary>
/// sets the element at index position to a new element
/// </summary>
/// <param name="storingArray">a dynamic array </param>
///<param name = "position">position of the element that we want to change in the dynamic array < / param>
///<param name = "newElemnt">the element that we want to put in the dynamic array  at index position< / param>
/// <returns>void.</returns>
void substitute(DynamicArray* storingArray, int positionBeingChanged, void* newElement);

/// <summary>
/// deletes the elemnt of the array stored at the index position
/// </summary>
/// <param name="storingArray">a dynamic array </param>
///<param name = "position">position of the element that we want to delete in the dynamic array < / param>
/// <returns>void</returns>
void deleteElement(DynamicArray* storingArray, int position);

void copyDynamicArray(DynamicArray* destination, DynamicArray* source);