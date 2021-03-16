#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

int main()
{
        int fd[2], fr[2], n, m;
        pipe(fd);
        pipe(fr);
        if (fork() == 0)
        {
                close(fd[1]); // close write end
                close(fr[0]);
                read(fd[0], &n, sizeof(int));
                read(fd[0], &m, sizeof(int));
                close(fd[0]);
                int sum = -1;
                sum = m + n;
                write(fr[1], &sum, sizeof(int));
                close(fr[1]);
                //printf("%d\n", sum);
                exit(0);

        }

        close(fd[0]); // close the read end ASAP
        close(fr[1]); // close write end for reverse pipe
        scanf("%d %d", &n, &m);
        write(fd[1], &n, sizeof(int));
        write(fd[1], &m, sizeof(int));
        close(fd[1]);
        int s;
        read(fr[0], &s, sizeof(int));
        close(fr[0]);
        printf("%d\n", s);

        wait(0);

        return 0;
}