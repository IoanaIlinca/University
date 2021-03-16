#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

void function()
{
        time_t curtime;
        time(&curtime);
        printf("%s\n", ctime(&curtime));
}

int main()
{
        signal(SIGHUP, function);
        while(1)
                sleep(1);
        return 0;
}