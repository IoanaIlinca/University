#pragma once
#include "repo.h"

void initializeService();

int service_addIngr(int catalogingNumber, char* state, char* intendedUse, int potency);

int service_updateIngr(int catalogingNumber, char* state, char* intendedUse, int potency);

int service_deleteIngr(int catalogingNumber);

ingrlist get_all();

