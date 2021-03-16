
#include "tests.h"
#include <stdio.h>


int main()
{
	testAll();
    Console();
	//printf("%d", myList->length);
	destroy(myList);
	//free(myList);
	destroy(undoArrayOfArrays);



	destroy(redoArrayOfArrays);
	destroy(undoCommands);
	destroy(redoCommands);

	_CrtDumpMemoryLeaks();
	return 0;
}
