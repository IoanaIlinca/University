#pragma once
#include "domain.h"

typedef struct
{
	Ingredient ingr[255];
	int len;
}ingrlist;

ingrlist apothecary;

void initializeRepo();

int checkExisting(int catalogingNumber);

void repo_addIngr(Ingredient i);

void repo_updateIngr(Ingredient i);

void repo_deleteIngr(int catalogingNumber);

ingrlist repo_get_all();