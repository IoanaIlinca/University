#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main()
{
        int p2a[2],p2b[2];
        char word[55], wordsA[99][55],wordsB[99][55];
        int nA=0,nB=0;
        pipe(p2a);
        pipe(p2b);

        if(fork()==0) // process a
        {                                                                                              close(p2a[1]);
                int totalLen = 0;
                read(p2a[0],wordsA,5500);
                read(p2a[0],&nA,sizeof(int));
                close(p2a[0]);
                for(int i=0;i<nA;i++)
                        totalLen += strlen(wordsA[i]);
                printf("The total length of words that contain 'oa' is %d\n",totalLen);                exit(0);
        }
        if(fork()==0) // process b
        {
                close(p2b[1]);
                int totalLen = 0;
                read(p2b[0],wordsB,5500);
                read(p2b[0],&nB,sizeof(int));
                close(p2b[0]);
                for(int i=0;i<nB;i++)
                        totalLen += strlen(wordsB[i]);
                printf("The total length of the other words is %d\n",totalLen);
                exit(0);
        }
        close(p2a[0]); close(p2b[0]);
        printf("Insert the words (<word> + Enter):\n");
            while(fgets(word,55,stdin)){
                if(word[0] == '\n'|| word[0]== ' ')
                        break;
                word[strlen(word)-1] = '\0';
                if(strstr(word,"oa"))
                        strcpy(wordsA[nA++], word);
                else
                        strcpy(wordsB[nB++], word);
        }
        write(p2a[1],wordsA,5500);
        write(p2a[1],&nA,sizeof(int));
        write(p2b[1],wordsB,5500);
        write(p2b[1],&nB,sizeof(int));

        close(p2a[1]); close(p2b[1]);
        wait(0); wait(0);
        return 0;
}
    