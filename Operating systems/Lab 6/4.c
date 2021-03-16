#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void create_forks(int pid)
{
        if (pid % 2 == 1)
                return;
        pid = fork();
        if(!pid)
        {
                printf("%d\n", getpid());
                create_forks(getpid());
                exit(0);
        }
        printf("%d has finished\n", pid);
        wait(0);

}

int main()
{
        create_forks(0);
        return 0;
}