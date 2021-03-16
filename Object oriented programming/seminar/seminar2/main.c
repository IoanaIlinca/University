#include "DynamicArray.h"
#include "Planet.h"
#include <stdlib.h>
#include <crtdbg.h>
#include <assert.h>
#include <string.h>

void testAnArrayOfPlanets()
{
	DynamicArray* arrayOfPlanets = createDynamicArray(2, &destroyPlanet);
	if (arrayOfPlanets == NULL)
		assert(0);

	assert(arrayOfPlanets->capacity == 2);
	assert(arrayOfPlanets->length == 0);

	// the array takes responsibility of all allocated memory for the planets
	Planet* p1 = createPlanet("Wolf 1061 c", "terrestrial", 13.8);
	add(arrayOfPlanets, p1);
	assert(getLength(arrayOfPlanets) == 1);

	Planet* p2 = createPlanet("HAT-P-26b", "Neptune-like", 450);
	add(arrayOfPlanets, p2);
	assert(getLength(arrayOfPlanets) == 2);

	// capacity must double
	Planet* p3 = createPlanet("Proxima Centauri b", "terrestrial", 4.2);
	add(arrayOfPlanets, p3);
	assert(getLength(arrayOfPlanets) == 3);

	// delete planet on position 0
	/*delete(arrayOfPlanets, 0);
	Planet* p = get(arrayOfPlanets, 0);
	assert(strcmp(getName(p), "HAT-P-26b") == 0);
	assert(getLength(arrayOfPlanets) == 2);*/

	// destroy the dynamic array
	destroy(arrayOfPlanets);
}

void testAnArrayOfDynamicArrays()
{
	DynamicArray* arrayOfArrays = createDynamicArray(1, &destroy);

	// create 2 dynamic arrays of pointers to Planets
	DynamicArray* arrayOfPlanets1 = createDynamicArray(1, &destroyPlanet);
	Planet* p1 = createPlanet("Wolf 1061 c", "terrestrial", 13.8);
	add(arrayOfPlanets1, p1);

	DynamicArray* arrayOfPlanets2 = createDynamicArray(1, &destroyPlanet);
	Planet* p2 = createPlanet("HAT-P-26b", "Neptune-like", 450);
	add(arrayOfPlanets2, p2);

	// add the arrays to the arrayOfArrays
	add(arrayOfArrays, arrayOfPlanets1);
	add(arrayOfArrays, arrayOfPlanets2);
	assert(getLength(arrayOfArrays) == 2);

	// this will destroy: the two planets, the two arrays of planets and the array of arrays
	destroy(arrayOfArrays);
}

int main()
{
	// some tests for the DynamicArray
	testAnArrayOfPlanets();
	testAnArrayOfDynamicArrays();

	_CrtDumpMemoryLeaks();
}