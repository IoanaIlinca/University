#include "ui.h"

void print_ingredient(Ingredient i)
{
	printf("apothecaryCatalogingNumber: %d , state: %s , intendedUse: %s , potency: %d \n",
		i.catalogingNumber, i.state, i.intendedUse, i.potency);
}

void print_apothecary()
{
	apothecary = get_all();
	for (int i = 0; i < apothecary.len; i++)
		print_ingredient(apothecary.ingr[i]);
}

void list_intendedUse(char *intendedUse)
{	
	int ok = 0;
	char message[256] = "No!";
	apothecary = get_all();
	for (int i = 0; i < apothecary.len; i++)
	{
		if (strcmp(apothecary.ingr[i].intendedUse, intendedUse)==0)
		{
			print_ingredient(apothecary.ingr[i]);
			ok = 1;
		}
	}
	if (ok == 0)
		printf("%s", message);
}

void ui_add(char *full_cmd)
{
	char* add = strtok(full_cmd, " ");
	int catalogingNumber, potency;
	char state[256], intendedUse[256];
	catalogingNumber = atoi(strtok(0, " ,"));
	strcpy(state, strtok(0, " ,"));
	strcpy(intendedUse, strtok(0, " ,"));
	potency = atoi(strtok(0, " ,"));
	if (!service_addIngr(catalogingNumber, state, intendedUse, potency))
		printf("No!");
}

void ui_update(char* full_cmd)
{
	char* update = strtok(full_cmd, " ");
	int catalogingNumber, potency;
	char state[256], intendedUse[256];
	catalogingNumber = atoi(strtok(0, " ,"));
	strcpy(state, strtok(0, " ,"));
	strcpy(intendedUse, strtok(0, " ,"));
	potency = atoi(strtok(0, " ,"));
	if (!service_updateIngr(catalogingNumber, state, intendedUse, potency))
		printf("No!");
}

void ui_delete(char* full_cmd)
{
	char* delete = strtok(full_cmd, " ");
	int catalogingNumber = atoi(strtok(0, " "));
	if (!service_deleteIngr(catalogingNumber))
		printf("No!");
}




void Console()
{
	initializeService();
	while (1)
	{
		char first_cmd[256], full_cmd[256], * cmd,s[10]=">>";
		printf("%s",s);
		scanf("%[^\n]%*c", full_cmd);
		strcpy(first_cmd, full_cmd);
		cmd = strtok(first_cmd, " ");
		if (strcmp(cmd, "add") == 0)
		{
			ui_add(full_cmd);
		}
		else if (strcmp(cmd, "update") == 0)
		{
			ui_update(full_cmd);
		}
		else if (strcmp(cmd, "delete") == 0)
		{
			ui_delete(full_cmd);
		}
		else if (strcmp(cmd, "list") == 0)
		{
			cmd = strtok(0, " ");
			if (!cmd)
				print_apothecary();
			else
				list_intendedUse(cmd);
		}
		else if (strcmp(cmd, "exit") == 0)
			break;
		else printf("Command does not exist!\n");
	}
}