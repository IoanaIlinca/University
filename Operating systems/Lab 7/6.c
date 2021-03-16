#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
        int n, m;

        int A2BFifo;
        mkfifo("/tmp/pb6", 0600);
        if (fork() == 0) // process B
        {
                A2BFifo = open("/tmp/pb6", O_RDONLY);
                read(A2BFifo, &n, sizeof(int));
                read(A2BFifo, &m, sizeof(int));
                close(A2BFifo);
                int sum = -1;
                sum = m + n;
                //B2AFifo = open("/tmp/pb6", O_WRONLY);
                //write(B2A, &sum, sizeof(int));
                //close(B2A);
                printf("%d\n", sum);
                exit(0);

        }
        // parent A
        scanf("%d %d", &n, &m);
        A2BFifo = open("/tmp/pb6", O_WRONLY);
        write(A2BFifo, &n, sizeof(int));
        write(A2BFifo, &m, sizeof(int));
        close(A2BFifo);

        wait(0);

        return 0;
}