#include "repo.h"

void initializeRepo()
{
	apothecary.len = 0;
}

void repo_addIngr(Ingredient i)
{
	apothecary.ingr[apothecary.len++] = i;
}

int checkExisting(int catalogingNumber)
{
	int  i = 0;
	for (i = 0; i < apothecary.len; i++)
	{
		if (apothecary.ingr[i].catalogingNumber == catalogingNumber)
			return 1;
	}
	return 0;
}

void repo_updateIngr(Ingredient i)
{
	int  j = 0;
	for (j = 0; j < apothecary.len; j++)
	{
		if (apothecary.ingr[j].catalogingNumber == i.catalogingNumber)
		{
			apothecary.ingr[j] = i;
			return 1;
		}
	}
	return 0;
}

void repo_deleteIngr(int catalogingNumber)
{
	int i = 0;
	ingrlist new_list;
	new_list.len = 0;
	for (i = 0; i < apothecary.len; i++)
	{
		if (apothecary.ingr[i].catalogingNumber != catalogingNumber)
		{
			new_list.ingr[new_list.len++] = apothecary.ingr[i];
		}
	}
	apothecary = new_list;
}

ingrlist repo_get_all()
{
	return apothecary;
}


