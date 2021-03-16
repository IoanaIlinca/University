#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
        char** array;
        int i = 0;
        array = (char**)malloc(11*sizeof(char*));
        array[0] = (char*)malloc(256*sizeof(char));
        if (fork() == 0)
        {
                while (scanf("%s", array[i]))                                                          {                                                                                              if (strcmp(array[i], ";") == 0)                                                               break;                                                                                                                                                                i++;                                                                                   array[i] = (char*)malloc(256*sizeof(char));                                    }                                                                       
                //exit(0);
                //printf("Ok");
                array[i] = NULL;
                execvp(array[0], array);
                exit(0);
        }
        wait(0);
        return 0;
}