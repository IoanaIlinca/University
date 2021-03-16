#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>



int i = -1, j = -1, k = -1;


int main()
{
        i = fork();
        //printf("%d ", i);
        if ((j = fork())) {

                k = fork();
                //k = 4;

        }


        printf("%d %d %d %d %d\n", i, j, k, getpid(), getppid());
        //printf("%d %d\n", i, getppid());
        return 0;
}