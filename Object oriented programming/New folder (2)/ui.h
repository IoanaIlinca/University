#pragma once
#include "service.h"
#include <string.h>

typedef struct {
	MapService* mapServicePointer;
} Console;

Console createConsole(MapService* mapServicePointer);
int run(Console* consolePointer);
