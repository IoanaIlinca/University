#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <string.h>

typedef struct
{
	int catalogingNumber,potency;
	char state[100], intendedUse[100];
}Ingredient;

Ingredient createIngredient(int catalogingNumber, char *state, char *intendedUse, int potency);
