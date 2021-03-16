#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void createCommand(char* command,char* word, char* file)
{
        strcpy(command, "awk '/\\<");
        strcat(command,word);
        strcat(command,"\\>/{if(length($0) % 3 == 0) print $0}' ");
        strcat(command,file);
}

int main(int argc, char** argv)
{
        char word[66],filename[66],command[111];
        printf("Insert file name (up to 65 characters): ");
        scanf("%s",filename);
        printf("Insert the word you want to search for (up to 65 characters): ");
        scanf("%s",word);
        char* extractedLine = malloc(2020);
        createCommand(command, word,filename);

        FILE* fp = popen(command,"r");
        while(fgets(extractedLine,2020,fp))
                printf("%s",extractedLine);
        pclose(fp);
        free(extractedLine);
        return 0;
}