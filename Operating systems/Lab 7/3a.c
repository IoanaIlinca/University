#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>



int main()
{
        int fd[2], n, m;
        pipe(fd);
        if (fork() == 0)
        {
                close(fd[1]); // close write end
                read(fd[0], &n, sizeof(int*));
                read(fd[0], &m, sizeof(int*));
                close(fd[0]);
                int sum = -1;
                sum = m + n;
                printf("%d\n", sum);
                exit(0);

        }

        close(fd[0]); // close the read end ASAP
        scanf("%d %d", &n, &m);
        write(fd[1], &n, sizeof(int*));
        write(fd[1], &m, sizeof(int*));
        close(fd[1]);
        wait(0);

        return 0;
}