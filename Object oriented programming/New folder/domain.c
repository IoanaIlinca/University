#include "domain.h"


Ingredient createIngredient(int catalogingNumber, char* state, char* intendedUse, int potency)
{
	Ingredient i;
	i.catalogingNumber = catalogingNumber;
	strcpy(i.state, state);
	strcpy(i.intendedUse, intendedUse);
	i.potency = potency;
	return i;
}