#pragma once
#include "service.h"

struct UI {
	Service serv;
	Service* service;
};
 
 void UiList(UI ui)
{
	 ListElements(ui.serv);
}

 void UiAdd(Service* serv, int profileIdNumber, int yearsOfRecordedService, char placeOfBirth[], char psychologicalProfile[])
 {
     if (AddElement(serv, profileIdNumber, yearsOfRecordedService, placeOfBirth, psychologicalProfile) == -1)
     {
         printf("%s\n", "Id already exists!");
     }
        
 }

 void UiRemove(Service *serv, int profileIdNumber)
 {
     if (DeleteElement(serv, profileIdNumber) == -1)
     {
         printf("%s\n", "Id does not exist!");
     }
 }



 void UiMenu(UI menu)
 {
         char command[101];
         scanf("%s", command);
         while (strcmp(command, "exit") != 0)
         {
             if (strcmp(command, "add") == 0)
             {
                 int profileIdNumber, yearsOfRecordedService;
                 char placeOfBirth[21], psychologicalProfile[21];
                 scanf("%d", &profileIdNumber);
                 scanf("%s", &placeOfBirth);
                 scanf("%d", &yearsOfRecordedService);
                 scanf("%s", &psychologicalProfile);
                 UiAdd(menu.service, profileIdNumber, yearsOfRecordedService, placeOfBirth, psychologicalProfile);
             }
             if (strcmp(command, "delete") == 0)
             {
                 int profileIdNumber;
                 scanf("%d", &profileIdNumber);
                 UiRemove(menu.service, profileIdNumber);
             }
             if (strcmp(command, "list") == 0)
             {
                 UiList(menu);
             }
             scanf("%s", command);
         }
         
 }
