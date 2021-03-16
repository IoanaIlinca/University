#include <stdio.h>
#include "domain.h"
#include "repository.h"
#include "service.h"
#include "ui.h"
#include "tests.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
int main()
{
    allTests();
    Repo repository;
    initialiseRepo(&repository);
    MapService service= createMapService(&repository);
    Console console = createConsole(&service);
    run(&console);
    _CrtDumpMemoryLeaks();
    return 0;
}
