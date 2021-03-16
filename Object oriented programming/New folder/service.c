#include "service.h"

void initializeService()
{
	initializeRepo();
}

ingrlist get_all()
{
	return repo_get_all();
}

int service_addIngr(int catalogingNumber, char* state, char* intendedUse, int potency)
{
	if (checkExisting(catalogingNumber))
		return 0;
	Ingredient i = createIngredient(catalogingNumber, state, intendedUse, potency);
	repo_addIngr(i);
	return 1;

}

int service_updateIngr(int catalogingNumber, char* state, char* intendedUse, int potency)
{
	if (!checkExisting(catalogingNumber))
	{
		return 0;
	}
	Ingredient i = createIngredient(catalogingNumber, state, intendedUse, potency);
	repo_updateIngr(i);
	return 1;
}

int service_deleteIngr(int catalogingNumber)
{
	if (!checkExisting(catalogingNumber))
		return 0;
	repo_deleteIngr(catalogingNumber);
	return 1;
}