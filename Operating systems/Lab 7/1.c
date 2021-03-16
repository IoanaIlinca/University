#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

void IDoNotStop() // SIGTERM refuses to stop the program
{
        printf("I won't stop!\n");
}

int main()
{
        signal(SIGTERM, IDoNotStop);                                                           while(1)
                sleep(1);
        // the progam can stop with SIGKILL or SIGINT
        // it can be killed with kill -9 <PID>, or CTRL-C
        return 0;
}